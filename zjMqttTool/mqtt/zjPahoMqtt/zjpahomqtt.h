#ifndef ZJPAHOMQTT_H
#define ZJPAHOMQTT_H


#include <iostream>
#include <queue>
#include <mutex>
#include <set>
#include <string>

#include "paho/include/MQTTAsync.h"
#include "paho/include/MQTTClient.h"
#include "paho/include/MQTTClientPersistence.h"
#include "paho/include/MQTTProperties.h"
#include "paho/include/MQTTReasonCodes.h"
#include "paho/include/MQTTSubscribeOpts.h"


class zjPahoMqtt
{
public:
    zjPahoMqtt(std::string id);

public:

    int connect(std::string const ip=std::string("127.0.0.1"),int const port=1883,int const heart=60);

    int zjPublish(const std::string topic,const std::string str);
    int zjSubscribe(const std::string topic);
    void zjLoopForErver();


    bool isConnected(){return connectFlag;}
    void setShowDebug(bool flag){showDebug = flag;}
    std::queue<std::string> *getMqttQueue(){return &mqttQueue;}
    std::mutex              *getMqttQueueMutex(){return &mqttQueueMutex;}

private:
    bool connectFlag;
    bool showDebug;
    static int mqttNum;

    std::queue<std::string> mqttQueue;
    std::mutex              mqttQueueMutex;

    std::set<std::string>  mqttSubs;
    std::mutex             mqttSubsMutex;

    std::mutex             mqttPubMutex;

    MQTTClient                  client;
    MQTTClient_connectOptions   conn_opts;
    std::string                 deviceId;

    unsigned long               timeout;
};

#endif // ZJPAHOMQTT_H
