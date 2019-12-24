/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser_mainText;
    QLabel *label_ip;
    QLineEdit *lineEdit_ip;
    QLabel *label_port;
    QLabel *label_pubTopic;
    QTextEdit *textEdit_sendText;
    QLineEdit *lineEdit_port;
    QLineEdit *lineEdit_pubTopic;
    QLabel *label_4;
    QPushButton *pushButton_addSub;
    QPushButton *pushButton_send;
    QTextBrowser *textBrowser_subList;
    QPushButton *pushButton_connectOrDisConnect;
    QLineEdit *lineEdit_subTopic;
    QPushButton *pushButton_clearMainText;
    QPushButton *pushButton_clearSendText;
    QLabel *label_deviceId;
    QLineEdit *lineEdit_deviceId;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(744, 570);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainWindow->sizePolicy().hasHeightForWidth());
        mainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(mainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textBrowser_mainText = new QTextBrowser(centralWidget);
        textBrowser_mainText->setObjectName(QString::fromUtf8("textBrowser_mainText"));
        textBrowser_mainText->setGeometry(QRect(340, 10, 391, 471));
        label_ip = new QLabel(centralWidget);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));
        label_ip->setGeometry(QRect(10, 10, 21, 16));
        lineEdit_ip = new QLineEdit(centralWidget);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));
        lineEdit_ip->setGeometry(QRect(70, 10, 161, 21));
        label_port = new QLabel(centralWidget);
        label_port->setObjectName(QString::fromUtf8("label_port"));
        label_port->setGeometry(QRect(10, 40, 41, 21));
        label_pubTopic = new QLabel(centralWidget);
        label_pubTopic->setObjectName(QString::fromUtf8("label_pubTopic"));
        label_pubTopic->setGeometry(QRect(10, 70, 51, 21));
        textEdit_sendText = new QTextEdit(centralWidget);
        textEdit_sendText->setObjectName(QString::fromUtf8("textEdit_sendText"));
        textEdit_sendText->setGeometry(QRect(10, 130, 321, 141));
        lineEdit_port = new QLineEdit(centralWidget);
        lineEdit_port->setObjectName(QString::fromUtf8("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(70, 40, 161, 21));
        lineEdit_pubTopic = new QLineEdit(centralWidget);
        lineEdit_pubTopic->setObjectName(QString::fromUtf8("lineEdit_pubTopic"));
        lineEdit_pubTopic->setGeometry(QRect(70, 70, 161, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 320, 81, 21));
        pushButton_addSub = new QPushButton(centralWidget);
        pushButton_addSub->setObjectName(QString::fromUtf8("pushButton_addSub"));
        pushButton_addSub->setGeometry(QRect(240, 300, 101, 21));
        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(240, 270, 101, 21));
        textBrowser_subList = new QTextBrowser(centralWidget);
        textBrowser_subList->setObjectName(QString::fromUtf8("textBrowser_subList"));
        textBrowser_subList->setGeometry(QRect(10, 350, 221, 161));
        pushButton_connectOrDisConnect = new QPushButton(centralWidget);
        pushButton_connectOrDisConnect->setObjectName(QString::fromUtf8("pushButton_connectOrDisConnect"));
        pushButton_connectOrDisConnect->setGeometry(QRect(240, 50, 101, 21));
        lineEdit_subTopic = new QLineEdit(centralWidget);
        lineEdit_subTopic->setObjectName(QString::fromUtf8("lineEdit_subTopic"));
        lineEdit_subTopic->setGeometry(QRect(10, 300, 221, 21));
        pushButton_clearMainText = new QPushButton(centralWidget);
        pushButton_clearMainText->setObjectName(QString::fromUtf8("pushButton_clearMainText"));
        pushButton_clearMainText->setGeometry(QRect(650, 490, 75, 23));
        pushButton_clearSendText = new QPushButton(centralWidget);
        pushButton_clearSendText->setObjectName(QString::fromUtf8("pushButton_clearSendText"));
        pushButton_clearSendText->setGeometry(QRect(20, 270, 101, 21));
        label_deviceId = new QLabel(centralWidget);
        label_deviceId->setObjectName(QString::fromUtf8("label_deviceId"));
        label_deviceId->setGeometry(QRect(10, 100, 51, 21));
        lineEdit_deviceId = new QLineEdit(centralWidget);
        lineEdit_deviceId->setObjectName(QString::fromUtf8("lineEdit_deviceId"));
        lineEdit_deviceId->setGeometry(QRect(70, 100, 161, 21));
        mainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 744, 23));
        mainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        mainWindow->setStatusBar(statusBar);

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "mainWindow", nullptr));
        textBrowser_mainText->setHtml(QApplication::translate("mainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_ip->setText(QApplication::translate("mainWindow", "IP:", nullptr));
        lineEdit_ip->setText(QApplication::translate("mainWindow", "127.0.0.1", nullptr));
        label_port->setText(QApplication::translate("mainWindow", "\347\253\257\345\217\243", nullptr));
        label_pubTopic->setText(QApplication::translate("mainWindow", "\345\217\221\345\270\203\344\270\273\351\242\230", nullptr));
        textEdit_sendText->setHtml(QApplication::translate("mainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">hello world</p></body></html>", nullptr));
        lineEdit_port->setText(QApplication::translate("mainWindow", "1883", nullptr));
        lineEdit_pubTopic->setText(QApplication::translate("mainWindow", "testTopic", nullptr));
        label_4->setText(QApplication::translate("mainWindow", "\350\256\242\351\230\205\344\270\273\351\242\230\345\210\227\350\241\250", nullptr));
        pushButton_addSub->setText(QApplication::translate("mainWindow", "\346\267\273\345\212\240\350\256\242\351\230\205\344\270\273\351\242\230", nullptr));
        pushButton_send->setText(QApplication::translate("mainWindow", "\345\217\221\351\200\201", nullptr));
        textBrowser_subList->setHtml(QApplication::translate("mainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_connectOrDisConnect->setText(QApplication::translate("mainWindow", "\350\277\236\346\216\245", nullptr));
        pushButton_clearMainText->setText(QApplication::translate("mainWindow", "\346\270\205\351\231\244", nullptr));
        pushButton_clearSendText->setText(QApplication::translate("mainWindow", "\346\270\205\351\231\244", nullptr));
        label_deviceId->setText(QApplication::translate("mainWindow", "\350\256\276\345\244\207\345\217\267", nullptr));
        lineEdit_deviceId->setText(QApplication::translate("mainWindow", "deviceIdNo1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
