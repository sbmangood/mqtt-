#include "zjMqtt.h"
using namespace zjMqtt;

int ZjMqtt::mqttNum = 0;

ZjMqtt::ZjMqtt(const char *id) : mosquittopp(id)
{

    if(mqttNum==0)
        mosqpp::lib_init();
    mqttNum++;
    connectFlag = false;
    showDebug  = true;
    mqttSubs.clear();

    doReconnectFlag=true;

}

ZjMqtt::~ZjMqtt()
{
    mqttNum--;
    if(mqttNum==0)
        mosqpp::lib_cleanup();

}

void ZjMqtt::on_connect(int rc)
{
    connectFlag = true;
    if(showDebug)
    {
        std::cout<<"connect ok rc= "<<rc<<std::endl;
    }

    std::set<std::string>::iterator it;
    mqttSubsMutex.lock();
    for(it=mqttSubs.begin();it!=mqttSubs.end();it++)
    {
        subscribe(nullptr,(*it).c_str());
    }
    mqttSubsMutex.unlock();

}


void ZjMqtt::on_disconnect(int rc)
{
    connectFlag = false;
    if(showDebug)
    {
        std::cout<<"disconect server rc = "<<rc<<std::endl;
    }
    if(doReconnectFlag)
        while(reconnect());

}


void ZjMqtt::on_publish(int )
{
    if(showDebug)
    {
        std::cout<<"publish ok!\n";
    }

}

void ZjMqtt::on_subscribe(int mid,int ,const int *)
{
    if(showDebug)
    {
        std::cout<<"sub mid: %d "<<mid<<std::endl;
    }

}


void ZjMqtt::on_message(const struct mosquitto_message *mes)
{
    std::string strRcv = static_cast<char *>(mes->payload);
    std::string topic  = mes->topic;
    strRcv  =   topic+MQTT_SEPARATOR+strRcv;
    if(showDebug)
    {

        std::cout<<"I received mes from topic : " ;
        std::cout<<mes->topic;
        std::cout<< " mes: ";
        std::cout<<strRcv.c_str();
        std::cout<<std::endl;
    }
    mqttQueueMutex.lock();
    mqttQueue.push(strRcv);
    mqttQueueMutex.unlock();


    return;
}

void ZjMqtt::on_log(int level, const char * str)
{
    //log->writeLogFormat("level: %d log: %s",level,str);
}

void ZjMqtt::disConnectMqtt()
{
    doReconnectFlag=false;
    if(isConnected())
    {
        disconnect();
    }

    mqttSubs.clear();
}

int ZjMqtt::zjPublish(const std::string topic,const std::string str)
{
    int result;

    std::lock_guard<std::mutex> lock(mqttPubMutex);
    //result=publish(nullptr,topic.c_str(),static_cast<int>(str.length()),static_cast<const void *>(str.c_str()),0,true);
    static int mid=0;
    mid++;
    if(mid>1000)
    {
        mid=0;
    }
    result=456;
    if(reconnect()==MOSQ_ERR_SUCCESS)
    {
         result=publish(&mid,topic.c_str(),(str.length()),(str.c_str()),0,false);
    }

    if(result==MOSQ_ERR_SUCCESS)
        return 0;
    return -1;
}



int ZjMqtt::zjSubscribe(const std::string topic)
{
    int ret;

    mqttSubsMutex.lock();
    mqttSubs.insert(topic);
    mqttSubsMutex.unlock();
    ret=subscribe(nullptr,topic.c_str());
    if(ret==MOSQ_ERR_SUCCESS)
        return 0;
    return -1;
}

void ZjMqtt::zjLoopForErver()
{
    if(!doReconnectFlag)
        return;

loop:    loop_forever();
    if(doReconnectFlag)
    {

        while(reconnect()!=MOSQ_ERR_SUCCESS)
        {
            if(!doReconnectFlag)
                break;
            Sleep(50);
        }

        goto loop;

    }

    std::cout<<"stop mqtt!\n"<<std::endl;



}
