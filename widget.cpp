/*
	widget.cpp
	Author : zhuwenq
	Email : Leonez@nuaa.edu.cn
*/


#pragma execution_character_set("utf-8")	//set char-set to utf-8
#include "widget.h"

OpenChart_demo::OpenChart_demo(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	this->setWindowTitle("红外人体温度检测仪");
    QUrl url = QUrl::fromLocalFile(indexPagePath);
    ui.myWebView->load(url);
    QObject::connect(this, &Widget::refreshSignal, this, &Widget::refreshSlot);
    reloadButtonClicked();
    ui.openSerialPortButton->setText(tr("打开串口"));
    ui.baudRateComboBox->setCurrentIndex(1);
	gaussKernel << 0.106997, 0.11311, 0.106997,
		0.11311, 0.119572, 0.11311,
		0.106997, 0.11311, 0.106997;

	ui.minTemperatureLCDNumber->setSegmentStyle(QLCDNumber::Flat);
	ui.maxTemperatureLCDNumber->setSegmentStyle(QLCDNumber::Flat);
	ui.chipTemperatureLCDNumber->setSegmentStyle(QLCDNumber::Flat);

	QPalette lcdpat = ui.minTemperatureLCDNumber->palette();
	lcdpat.setColor(QPalette::Normal, QPalette::WindowText, Qt::red);

	ui.minTemperatureLCDNumber->setPalette(lcdpat);
	ui.maxTemperatureLCDNumber->setPalette(lcdpat);
	ui.chipTemperatureLCDNumber->setPalette(lcdpat);
}



void Widget::refreshSlot()
{
    const QJsonObject& option = makeJsonForHtmlSide(mat);
    QJsonDocument doc;
    doc.setObject(option);
    const QByteArray& array = doc.toJson(QJsonDocument::Compact);

    emit sendMsg(array);
}

/*
	make json data to send to the html side.
*/
QJsonObject OpenChart_demo::makeJsonForHtmlSide(Matrix<double, 24, 32> & mat)
{
    QJsonArray data;
    for (int i = 0; i < 24; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            QJsonArray tempData;
            tempData.append(j);
            tempData.append(i);
            tempData.append(mat(i, j));
            data.append(tempData);
        }
    }

	enableLCDNumbers(minTemperature, maxTemperature, chipTemperature);

	QJsonObject visualMap;
    visualMap.insert("min", minTemperature);
    visualMap.insert("max", maxTemperature);

	QJsonObject series;
    series.insert("type", "heatmap");
    series.insert("data", QJsonValue(data));
    series.insert("name", "TargetTemperature");

	QJsonObject option;
    option.insert("series", QJsonValue(series));
	option.insert("visualMap", QJsonValue(visualMap));

    return option;
}

void Widget::reloadButtonClicked()
{
    for (const QSerialPortInfo& info : QSerialPortInfo::availablePorts())
    {
        QSerialPort port;
        port.setPort(info);
        const QString portName = port.portName();
        if (port.open(QIODevice::ReadWrite)&&(ui.serialNameComboBox->findText(portName)==-1))
        {
            ui.serialNameComboBox->addItem(portName);
            port.close();
        }
    }
}


/*
	open serial port.
*/
void OpenChart_demo::openSerialportButtonClicked()
{
    if (ui.openSerialPortButton->text() == tr("打开串口"))
    {
        m_serialPort = new QSerialPort;
        m_serialPort->setPortName(ui.serialNameComboBox->currentText());
        m_serialPort->open(QIODevice::ReadWrite);
        const int baudRate = ui.baudRateComboBox->currentText().toInt();
        const char baudSet9600[4] = { 0xA5 , 0x15 , 0x01 , 0xBB };
        const char baudSet115200[4] = { 0xA5 , 0x15 , 0x02 , 0xBC };
        const char baudSet460800[4] = { 0xA5 , 0x15 , 0x03 , 0xBD };
        switch (baudRate)
        {
        case 9600:
            m_serialPort->write(baudSet9600);
            break;
        case 115200:
            m_serialPort->write(baudSet115200);
            break;
        case 460800:
            m_serialPort->write(baudSet460800);
            break;
        default:
            break;
        }
        m_serialPort->setBaudRate(baudRate);


        switch (ui.dataBitComboBox->currentText().toInt())
        {
        case 8:
            m_serialPort->setDataBits(QSerialPort::Data8);
            break;
        default:
            break;
        }

        switch (ui.parityComboBox->currentIndex())
        {
        case 0:
            m_serialPort->setParity(QSerialPort::NoParity);
            break;
        default:
            break;
        }

        switch (ui.stopBitComboBox->currentIndex())
        {
        case 0:
            m_serialPort->setStopBits(QSerialPort::OneStop);
            break;
        case 2:
            m_serialPort->setStopBits(QSerialPort::TwoStop);
            break;
        default:
            break;
        }

        m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

        ui.baudRateComboBox->setEnabled(false);
        ui.dataBitComboBox->setEnabled(false);
        ui.parityComboBox->setEnabled(false);
        ui.serialNameComboBox->setEnabled(false);
        ui.stopBitComboBox->setEnabled(false);
        ui.openSerialPortButton->setText(tr("关闭串口"));

        QObject::connect(m_serialPort, &QSerialPort::readyRead, this, &Widget::readSerialData);

		sendQuerryDataCommand();
    }
    //close
    else
    {
        m_serialPort->clear();
        m_serialPort->close();
        m_serialPort->deleteLater();

        ui.baudRateComboBox->setEnabled(true);
        ui.dataBitComboBox->setEnabled(true);
        ui.parityComboBox->setEnabled(true);
        ui.serialNameComboBox->setEnabled(true);
        ui.stopBitComboBox->setEnabled(true);
        ui.openSerialPortButton->setText(tr("打开串口"));
    }
}


/*
	read hex data from serial port.
*/
void OpenChart_demo::readSerialData()
{
    const int dataLength = 1544;
    QByteArray buf;
    static QByteArray temp;
    buf = m_serialPort->readAll();
    if (buf.length()>2)
    {
        const QByteArray head = buf.left(2);
        const int bufLength = buf.length();

        if ((head=="ZZ") && (temp.isEmpty()))
        {
            if (bufLength == dataLength)
            {
                temp.append(buf);
                serialDataToMatrixAndGaussBlur(temp);
            }
            else if (bufLength < dataLength)
            {
                temp.append(buf);
            }
        }
        else if (head == "ZZ" && (!temp.isEmpty()))
        {
            temp.clear();
            temp.append(buf);
        }
        else if ((head!="ZZ") && (!temp.isEmpty()))
        {
            if(temp.left(2)== "ZZ")
            {
                 temp.append(buf);
                 if(temp.length() == dataLength)
                 {
                      serialDataToMatrixAndGaussBlur(temp);
                 }
            }
        }
    }

    buf.clear();
    sendQuerryDataCommand();
}

/*
	send querry command to serial port.
	the serial port divice will understand.
*/
void OpenChart_demo::sendQuerryDataCommand()
{
    const char querryCmd[4] = { 0xA5 , 0x35  ,0x01  ,0xDB };
    m_serialPort->write(querryCmd);
}


/*
	args:
		mat : matrix to be gauss blured.
		kernel : gauss kernel.
	summary :
		gauss blur the matrix data to make image looks better.
*/
void OpenChart_demo::gaussBlur(Matrix<double, 24, 32> & mat,const Matrix<double,3,3>& kernel)
{
	Matrix<double, 24, 32> temp = mat;
	Matrix<double, 26, 34> afterPadding;
	afterPadding.block(1, 1, 24, 32) = mat;
	afterPadding.block(0, 1, 1, 32) = mat.row(0);
	afterPadding.block(25, 1, 1, 32) = mat.row(23);
	afterPadding.block(1, 0, 24, 1) = mat.col(0);
	afterPadding.block(1, 33, 24, 1) = mat.col(31);
	afterPadding(0, 0) = mat(0, 0);
	afterPadding(0, 33) = mat(0, 31);
	afterPadding(25, 0) = mat(23, 0);
	afterPadding(25, 33) = mat(23, 31);

	const std::size_t t_rows = mat.rows();
	const std::size_t t_cols = mat.cols();

	const std::size_t kernelSize = 3;

	for (std::size_t i = 0; i < t_rows; ++i)
	{
		for (std::size_t j = 0; j < t_cols; ++j)
		{
			Matrix<double, Dynamic, Dynamic> block =
				afterPadding.block(i - kernelSize / 2, j - kernelSize / 2, kernelSize, kernelSize);
			temp(i, j) = (block.cwiseProduct(kernel)).sum();
		}
	}
	mat = temp;
}

void OpenChart_demo::createGaussKernel(int size, double sigma, Matrix<double, 3, 3>& mat)
{
	mat.resize(size, size);

	int i, j;
	int center_i, center_j;
	center_i = center_j = size / 2;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			mat(i, j) = exp(-(1.0f) * (((i - center_i) * (i - center_i) + (j - center_j) * (j - center_j)) /
				(2.0f * sigma * sigma)));
		}
	}
	mat = mat / mat.sum();
}


/*
	process data from serial port.
*/
void OpenChart_demo::serialDataToMatrixAndGaussBlur(QByteArray& data)
{
    //get target temperature matrix
    for (int i = 4; i < 1539; i += 2)
    {
        //qDebug() << data.length();
        char head = data.at(i);
        char tail = data.at(i + 1);
        float temperature = (head + tail * 256) / 100;
        //qDebug() << temperature;

        const int row = (i - 4) / 64;
        const int col = ((i - 4) - (row * 64)) / 2;

        mat(23 - row, col) = temperature;
    }

    //get chip temperature
    chipTemperature = (data.at(1540) + data.at(1541) * 256) / 100;
	data.clear();
	minTemperature = mat.minCoeff();
	maxTemperature = mat.maxCoeff();

	gaussBlur(mat, gaussKernel);
    emit refreshSignal();
}

void OpenChart_demo::enableLCDNumbers(const float min, const float max, const float chip)
{
	ui.minTemperatureLCDNumber->display(QString("%1 °").arg(min));
	ui.maxTemperatureLCDNumber->display(QString("%1 °").arg(max));
	ui.chipTemperatureLCDNumber->display(QString("%1 °").arg(chip));
}




