#ifndef MAINLOGIC_H
#define MAINLOGIC_H

#include <Windows.h>

#include <QObject>
#include <QString>

#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <queue>


#include "mqtt/zjMqtt.h"
#include "mqtt/zjPahoMqtt/zjpahomqtt.h"

    typedef struct mqttStruct
    {
        int         port;
        QString     ip;
        QString     deviceId;
    }mqttStruct;
typedef struct mqttPubStruct
{
    QString     topic;
    QString     str;
}mqttPubStruct;

class mainLogic : public QObject
{



    Q_OBJECT
public:
    explicit mainLogic(QObject *parent = nullptr,QString deviceId="deviceIdNo1");
    ~mainLogic();
    void mqttLoopForerver(mqttStruct ms);
    void readMessageLoop();

private:



private slots:
    void mqttConnectOk();
    void connectMqtt(mqttStruct);
    void disconnectMqtt();
    void mqttSub(QString topic);
    void mqttPub(mqttPubStruct mps);


private:
    std::thread                     *loopThread=nullptr;
    std::thread                     *readMqttDequeThread=nullptr;

    bool                            readMqttFlag=false;

    zjMqtt::ZjMqtt                  *m_zjMqtt;  
    zjPahoMqtt                      *m_zjPahoMqtt;


    std::queue<std::string>         *mqttQueue=nullptr;
    std::mutex                      *mqttQueueMutex=nullptr;

    mqttStruct                      m_mqttStruct;


signals:
    void updateBrowserMainText(QString);
    void connectOk();
public slots:
};

#endif // MAINLOGIC_H
