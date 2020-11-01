/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_3;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QGroupBox *serialComboBox;
    QGridLayout *gridLayout;
    QLabel *serialPortNumberLabel;
    QComboBox *serialNameComboBox;
    QLabel *baudRateLabel;
    QComboBox *baudRateComboBox;
    QLabel *parityLabel;
    QComboBox *parityComboBox;
    QLabel *dataBitLabel;
    QComboBox *dataBitComboBox;
    QLabel *stopBitLabel;
    QComboBox *stopBitComboBox;
    QPushButton *reloadButton;
    QPushButton *openSerialPortButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *maxTemperaturLabel;
    QLCDNumber *maxTemperatureLCDNumber;
    QLabel *minTemperaturLabel;
    QLCDNumber *minTemperatureLCDNumber;
    QLabel *chipTemperatureLabel;
    QLCDNumber *chipTemperatureLCDNumber;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QPushButton *up;
    QPushButton *down;
    QPushButton *left;
    QPushButton *right;
    QPushButton *clearDataButton;
    QPushButton *exitButton;
    QWebEngineView *myWebView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1254, 670);
        gridLayout_3 = new QGridLayout(Widget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        dockWidget = new QDockWidget(Widget);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        serialComboBox = new QGroupBox(dockWidgetContents);
        serialComboBox->setObjectName(QString::fromUtf8("serialComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(serialComboBox->sizePolicy().hasHeightForWidth());
        serialComboBox->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(serialComboBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        serialPortNumberLabel = new QLabel(serialComboBox);
        serialPortNumberLabel->setObjectName(QString::fromUtf8("serialPortNumberLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(serialPortNumberLabel->sizePolicy().hasHeightForWidth());
        serialPortNumberLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(serialPortNumberLabel, 0, 0, 1, 1);

        serialNameComboBox = new QComboBox(serialComboBox);
        serialNameComboBox->setObjectName(QString::fromUtf8("serialNameComboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(serialNameComboBox->sizePolicy().hasHeightForWidth());
        serialNameComboBox->setSizePolicy(sizePolicy3);
        serialNameComboBox->setMinimumSize(QSize(20, 0));

        gridLayout->addWidget(serialNameComboBox, 0, 1, 1, 1);

        baudRateLabel = new QLabel(serialComboBox);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));
        sizePolicy2.setHeightForWidth(baudRateLabel->sizePolicy().hasHeightForWidth());
        baudRateLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(baudRateLabel, 1, 0, 1, 1);

        baudRateComboBox = new QComboBox(serialComboBox);
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->setObjectName(QString::fromUtf8("baudRateComboBox"));
        sizePolicy3.setHeightForWidth(baudRateComboBox->sizePolicy().hasHeightForWidth());
        baudRateComboBox->setSizePolicy(sizePolicy3);
        baudRateComboBox->setMinimumSize(QSize(20, 0));

        gridLayout->addWidget(baudRateComboBox, 1, 1, 1, 1);

        parityLabel = new QLabel(serialComboBox);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));
        sizePolicy2.setHeightForWidth(parityLabel->sizePolicy().hasHeightForWidth());
        parityLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(parityLabel, 2, 0, 1, 1);

        parityComboBox = new QComboBox(serialComboBox);
        parityComboBox->addItem(QString());
        parityComboBox->addItem(QString());
        parityComboBox->addItem(QString());
        parityComboBox->setObjectName(QString::fromUtf8("parityComboBox"));
        sizePolicy3.setHeightForWidth(parityComboBox->sizePolicy().hasHeightForWidth());
        parityComboBox->setSizePolicy(sizePolicy3);
        parityComboBox->setMinimumSize(QSize(20, 0));

        gridLayout->addWidget(parityComboBox, 2, 1, 1, 1);

        dataBitLabel = new QLabel(serialComboBox);
        dataBitLabel->setObjectName(QString::fromUtf8("dataBitLabel"));
        sizePolicy2.setHeightForWidth(dataBitLabel->sizePolicy().hasHeightForWidth());
        dataBitLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(dataBitLabel, 3, 0, 1, 1);

        dataBitComboBox = new QComboBox(serialComboBox);
        dataBitComboBox->addItem(QString());
        dataBitComboBox->addItem(QString());
        dataBitComboBox->addItem(QString());
        dataBitComboBox->addItem(QString());
        dataBitComboBox->setObjectName(QString::fromUtf8("dataBitComboBox"));
        sizePolicy3.setHeightForWidth(dataBitComboBox->sizePolicy().hasHeightForWidth());
        dataBitComboBox->setSizePolicy(sizePolicy3);
        dataBitComboBox->setMinimumSize(QSize(20, 0));

        gridLayout->addWidget(dataBitComboBox, 3, 1, 1, 1);

        stopBitLabel = new QLabel(serialComboBox);
        stopBitLabel->setObjectName(QString::fromUtf8("stopBitLabel"));
        sizePolicy2.setHeightForWidth(stopBitLabel->sizePolicy().hasHeightForWidth());
        stopBitLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(stopBitLabel, 4, 0, 1, 1);

        stopBitComboBox = new QComboBox(serialComboBox);
        stopBitComboBox->addItem(QString());
        stopBitComboBox->addItem(QString());
        stopBitComboBox->addItem(QString());
        stopBitComboBox->setObjectName(QString::fromUtf8("stopBitComboBox"));
        sizePolicy3.setHeightForWidth(stopBitComboBox->sizePolicy().hasHeightForWidth());
        stopBitComboBox->setSizePolicy(sizePolicy3);
        stopBitComboBox->setMinimumSize(QSize(20, 0));

        gridLayout->addWidget(stopBitComboBox, 4, 1, 1, 1);

        reloadButton = new QPushButton(serialComboBox);
        reloadButton->setObjectName(QString::fromUtf8("reloadButton"));

        gridLayout->addWidget(reloadButton, 5, 0, 1, 1);

        openSerialPortButton = new QPushButton(serialComboBox);
        openSerialPortButton->setObjectName(QString::fromUtf8("openSerialPortButton"));

        gridLayout->addWidget(openSerialPortButton, 5, 1, 1, 1);


        verticalLayout->addWidget(serialComboBox);

        groupBox = new QGroupBox(dockWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        maxTemperaturLabel = new QLabel(groupBox);
        maxTemperaturLabel->setObjectName(QString::fromUtf8("maxTemperaturLabel"));

        gridLayout_5->addWidget(maxTemperaturLabel, 2, 0, 1, 1);

        maxTemperatureLCDNumber = new QLCDNumber(groupBox);
        maxTemperatureLCDNumber->setObjectName(QString::fromUtf8("maxTemperatureLCDNumber"));
        sizePolicy3.setHeightForWidth(maxTemperatureLCDNumber->sizePolicy().hasHeightForWidth());
        maxTemperatureLCDNumber->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(maxTemperatureLCDNumber, 2, 1, 1, 1);

        minTemperaturLabel = new QLabel(groupBox);
        minTemperaturLabel->setObjectName(QString::fromUtf8("minTemperaturLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(minTemperaturLabel->sizePolicy().hasHeightForWidth());
        minTemperaturLabel->setSizePolicy(sizePolicy4);

        gridLayout_5->addWidget(minTemperaturLabel, 0, 0, 1, 1);

        minTemperatureLCDNumber = new QLCDNumber(groupBox);
        minTemperatureLCDNumber->setObjectName(QString::fromUtf8("minTemperatureLCDNumber"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(minTemperatureLCDNumber->sizePolicy().hasHeightForWidth());
        minTemperatureLCDNumber->setSizePolicy(sizePolicy5);

        gridLayout_5->addWidget(minTemperatureLCDNumber, 0, 1, 1, 1);

        chipTemperatureLabel = new QLabel(groupBox);
        chipTemperatureLabel->setObjectName(QString::fromUtf8("chipTemperatureLabel"));

        gridLayout_5->addWidget(chipTemperatureLabel, 3, 0, 1, 1);

        chipTemperatureLCDNumber = new QLCDNumber(groupBox);
        chipTemperatureLCDNumber->setObjectName(QString::fromUtf8("chipTemperatureLCDNumber"));
        sizePolicy3.setHeightForWidth(chipTemperatureLCDNumber->sizePolicy().hasHeightForWidth());
        chipTemperatureLCDNumber->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(chipTemperatureLCDNumber, 3, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(dockWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy6);
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        up = new QPushButton(groupBox_2);
        up->setObjectName(QString::fromUtf8("up"));

        gridLayout_6->addWidget(up, 0, 0, 1, 1);

        down = new QPushButton(groupBox_2);
        down->setObjectName(QString::fromUtf8("down"));

        gridLayout_6->addWidget(down, 0, 1, 1, 1);

        left = new QPushButton(groupBox_2);
        left->setObjectName(QString::fromUtf8("left"));

        gridLayout_6->addWidget(left, 1, 0, 1, 1);

        right = new QPushButton(groupBox_2);
        right->setObjectName(QString::fromUtf8("right"));

        gridLayout_6->addWidget(right, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        clearDataButton = new QPushButton(dockWidgetContents);
        clearDataButton->setObjectName(QString::fromUtf8("clearDataButton"));

        verticalLayout->addWidget(clearDataButton);

        exitButton = new QPushButton(dockWidgetContents);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        verticalLayout->addWidget(exitButton);

        dockWidget->setWidget(dockWidgetContents);

        gridLayout_3->addWidget(dockWidget, 0, 1, 1, 1);

        myWebView = new QWebEngineView(Widget);
        myWebView->setObjectName(QString::fromUtf8("myWebView"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(myWebView->sizePolicy().hasHeightForWidth());
        myWebView->setSizePolicy(sizePolicy7);
        myWebView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_3->addWidget(myWebView, 0, 0, 1, 1);

#if QT_CONFIG(shortcut)
        serialPortNumberLabel->setBuddy(serialNameComboBox);
        baudRateLabel->setBuddy(baudRateComboBox);
        parityLabel->setBuddy(parityComboBox);
        dataBitLabel->setBuddy(dataBitComboBox);
        stopBitLabel->setBuddy(stopBitComboBox);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Widget);
        QObject::connect(exitButton, SIGNAL(clicked()), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "OpenChart_demo", nullptr));
        serialComboBox->setTitle(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        serialPortNumberLabel->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", nullptr));
        baudRateLabel->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        baudRateComboBox->setItemText(0, QCoreApplication::translate("Widget", "460800", nullptr));
        baudRateComboBox->setItemText(1, QCoreApplication::translate("Widget", "115200", nullptr));

        parityLabel->setText(QCoreApplication::translate("Widget", "\345\245\207\345\201\266\346\240\241\351\252\214", nullptr));
        parityComboBox->setItemText(0, QCoreApplication::translate("Widget", "\346\227\240", nullptr));
        parityComboBox->setItemText(1, QCoreApplication::translate("Widget", "\345\245\207\346\240\241\351\252\214", nullptr));
        parityComboBox->setItemText(2, QCoreApplication::translate("Widget", "\345\201\266\346\240\241\351\252\214", nullptr));

        dataBitLabel->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", nullptr));
        dataBitComboBox->setItemText(0, QCoreApplication::translate("Widget", "8", nullptr));
        dataBitComboBox->setItemText(1, QCoreApplication::translate("Widget", "7", nullptr));
        dataBitComboBox->setItemText(2, QCoreApplication::translate("Widget", "6", nullptr));
        dataBitComboBox->setItemText(3, QCoreApplication::translate("Widget", "5", nullptr));

        stopBitLabel->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", nullptr));
        stopBitComboBox->setItemText(0, QCoreApplication::translate("Widget", "1", nullptr));
        stopBitComboBox->setItemText(1, QCoreApplication::translate("Widget", "1.5", nullptr));
        stopBitComboBox->setItemText(2, QCoreApplication::translate("Widget", "2", nullptr));

        reloadButton->setText(QCoreApplication::translate("Widget", "\345\210\267\346\226\260", nullptr));
        openSerialPortButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "\347\212\266\346\200\201\347\233\221\346\216\247", nullptr));
        maxTemperaturLabel->setText(QCoreApplication::translate("Widget", "\347\233\256\346\240\207\346\234\200\351\253\230\346\270\251\345\272\246", nullptr));
        minTemperaturLabel->setText(QCoreApplication::translate("Widget", "\347\233\256\346\240\207\346\234\200\344\275\216\346\270\251\345\272\246", nullptr));
        chipTemperatureLabel->setText(QCoreApplication::translate("Widget", "\350\212\257\347\211\207\346\270\251\345\272\246", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\344\272\221\345\217\260\346\216\247\345\210\266", nullptr));
        up->setText(QCoreApplication::translate("Widget", "\344\270\212", nullptr));
        down->setText(QCoreApplication::translate("Widget", "\344\270\213", nullptr));
        left->setText(QCoreApplication::translate("Widget", "\345\267\246", nullptr));
        right->setText(QCoreApplication::translate("Widget", "\345\217\263", nullptr));
        clearDataButton->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        exitButton->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
