/*
	widget.h
	Author : zhuwenq
	Email : Leonez@nuaa.edu.cn
*/

#pragma once

#include <QtWidgets/QWidget>
#include <QDir>
#include <QUrl>
#include <QTimer>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QLCDNumber>
#include <Eigen/Dense>

#include "ui_widget.h"

#define EXP

using namespace Eigen;
QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE
class OpenChart_demo : public QWidget
{
    Q_OBJECT

public:
    explicit OpenChart_demo(QWidget *parent = Q_NULLPTR);
    QJsonObject makeJsonForHtmlSide(Matrix<double, 24, 32> & mat);
signals:
    void sendMsg(const QString& text);
    void refreshSignal();

private slots:
    void refreshSlot();
    void reloadButtonClicked();
    void openSerialportButtonClicked();
    void readSerialData();
    void sendQuerryDataCommand();
private:
	void gaussBlur(Matrix<double, 24, 32> & mat, const Matrix<double, 3, 3>& kernel);
	void createGaussKernel(int size, double sigma,Matrix<double,3,3>& mat);
	void serialDataToMatrixAndGaussBlur(QByteArray& data);
	void enableLCDNumbers(const float min, const float max, const float chip);
private:
    Ui::Widget ui;

    QSerialPort* m_serialPort;
    Matrix<double, 24, 32> mat;
	Matrix<double, 3, 3> gaussKernel;
    float chipTemperature;
	float minTemperature;
	float maxTemperature;
	const QString indexPagePath = "/Resources/index.html";
#ifdef EXP
    double temp;
    QSerialPort* tempSerialPort;
    void getTemp()
    {
        QByteArray buf = tempSerialPort->readAll();
        if (buf.length() != 10)return;
        int tempInt = (unsigned char)buf[0] + (unsigned char)buf[1] * 256 - ((unsigned char)buf[1] > 127 ? 65536 : 0);
        this->temp = tempInt / 10.0;
    }
    void experment()
    {
        static const QSet<int> nums = { 30,32,34,36,38,40,42,44,46,48 };
        if (!nums.contains(this->maxTemperature))
            return;
        static const QString expPath = "./exp";
        static QDir dir;
        if (!dir.exists(expPath))
            dir.mkpath(expPath);
        static QFile expFile(expPath + "results.txt");
        static QString data = "system : real\n";
        expFile.open(QIODevice::ReadWrite);
        data = expFile.readAll();
        data += QString::number(this->maxTemperature);

        QPixmap screenGrap = QPixmap::grabWidget(this, this->rect());
        screenGrap.save(expPath + "/" + QString::number(this->maxTemperature), "png");

        static const QByteArray readCommand = QByteArrayLiteral("\x81\x81\x52\x00\x00\x00\x53\x00");
        tempSerialPort->write(readCommand);
        QTime dieTime = QTime::currentTime().addMSecs(50);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
        data += " : " + QString::number(this->temp);
        data += "\n";
        expFile.write(data.toUtf8());
        expFile.close();
    };
#endif // EXP
};
typedef OpenChart_demo Widget;

#pragma execution_character_set("utf-8")	//set char-set to utf-8
