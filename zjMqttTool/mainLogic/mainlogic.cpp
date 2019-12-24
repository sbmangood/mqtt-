#include "mainlogic.h"

mainLogic::mainLogic(QObject *parent,QString deviceId) : QObject(parent)
{
    m_zjMqtt    =   new zjMqtt::ZjMqtt(deviceId.toStdString().c_str());
    m_zjPahoMqtt=   new zjPahoMqtt(deviceId.toStdString().c_str());

    mqttQueue   =   m_zjMqtt->getMqttQueue();
    mqttQueueMutex= m_zjMqtt->getMqttQueueMutex();

    connect(this,SIGNAL(connectOk()),this,SLOT(mqttConnectOk()));
}


mainLogic::~mainLogic()
{

    if(m_zjMqtt!=nullptr)
    {
        disconnectMqtt();
        delete      m_zjMqtt;
    }


    delete      m_zjPahoMqtt;


    if(loopThread!=nullptr && loopThread->joinable())
        loopThread->join();
    if(readMqttDequeThread!=nullptr && readMqttDequeThread->joinable())
        readMqttDequeThread->join();


}


void mainLogic::connectMqtt(mqttStruct ms)
{
    m_mqttStruct=ms;
    std::cout<<"test";

    loopThread = new std::thread(&mainLogic::mqttLoopForerver,this,ms);

}

void mainLogic::disconnectMqtt()
{
    readMqttFlag=false;
    m_zjMqtt->disConnectMqtt();

    emit updateBrowserMainText("disconnect mqtt !!");

}

void mainLogic::mqttSub(QString topic)
{
    if(m_zjMqtt!=nullptr && m_zjMqtt->isConnected() )
    {
        m_zjMqtt->zjSubscribe(topic.toStdString());
    }

}

void mainLogic::mqttPub(mqttPubStruct mps)
{
    int rc=-1;

    m_zjPahoMqtt->connect(m_mqttStruct.ip.toStdString(),m_mqttStruct.port);

    rc=m_zjPahoMqtt->zjPublish(mps.topic.toStdString(),mps.str.toStdString());
    if(rc==0)
    {
        emit updateBrowserMainText("publish ok!");
    }
    else
    {
        emit updateBrowserMainText("publish err!");
    }

}
void mainLogic::mqttConnectOk()
{

    emit updateBrowserMainText("connect ok!!");
    readMqttDequeThread = new std::thread(&mainLogic::readMessageLoop,this);
}

void mainLogic::mqttLoopForerver(mqttStruct ms)
{
    m_zjMqtt->doReconnectFlag=true;
    readMqttFlag=true;
    while(m_zjMqtt->connect(ms.ip.toStdString().c_str(),ms.port,60)!=MOSQ_ERR_SUCCESS)
    {
        emit updateBrowserMainText("conect mqtt...");
        Sleep(4000);
        if(m_zjMqtt->doReconnectFlag==false)
            break;

    }

    emit connectOk();
    m_zjMqtt->zjLoopForErver();
    emit updateBrowserMainText("mqtt real disconnected !");
}

void mainLogic::readMessageLoop()
{
    while(readMqttFlag)
    {

        mqttQueueMutex->lock();
        if(mqttQueue->empty())
        {
            mqttQueueMutex->unlock();
            Sleep(500);
        }
        else
        {
            QString str=QString(mqttQueue->front().c_str());

            mqttQueue->pop();
            mqttQueueMutex->unlock();
            emit updateBrowserMainText(str);
            Sleep(20);
        }

    }
}
