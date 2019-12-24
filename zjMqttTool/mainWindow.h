#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>

#include "configs/configdeal.h"
#include "mainLogic/mainlogic.h"
#include "zjTinyLog/zjTinyLog.h"


#define   CONFIG_FILE_PATH          "./configs/mqtt.json"

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private:
    bool getConfigData();
    void initMqttStruct(mqttStruct &ms);
    void setUi();
    void connectThisWithMainLogic();
    void connectUi();





private slots:
    void updateBrowserMainText(QString str);

    void clickedConnectButton();
    void clickedSendButton();
    void clickedAddSub();
    void clickedClearSendText();
    void clickedClearMainText();

private:
    mainLogic                           *m_mainLogic=nullptr;

    cJSON                               *configJs=nullptr;

    mqttStruct                          m_mqttStruct;
    mqttPubStruct                       m_mqttPubStruct;
    QStringList                         subMqttList;

    std::thread                         *mqttLoopThread;

    zjTinyLog::ZjTinyLog                *readTpsLog;

    QString                             oldTps="";


private:
    Ui::mainWindow          *ui;




signals:
    void connectMqtt(mqttStruct);
    void disConnectMqtt();
    void pubMqtt(mqttPubStruct);
    void subMqtt(QString);
};

#endif // MAINWINDOW_H
