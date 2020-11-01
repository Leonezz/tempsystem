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
};
typedef OpenChart_demo Widget;

#pragma execution_character_set("utf-8")	//set char-set to utf-8
