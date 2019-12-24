#ifndef ZJMQTT_H
#define ZJMQTT_H



#include <iostream>
#include <queue>
#include <mutex>
#include <set>
#include <Windows.h>

#include "mosquitto.h"
#include "mosquittopp.h"



//#pragma comment(lib,"mosquittopp.lib")
#define MQTT_SEPARATOR               "<-->"



namespace  zjMqtt
{



class ZjMqtt : public mosqpp::mosquittopp
{

public:
    explicit ZjMqtt(const char *id=nullptr);
    ~ZjMqtt();

    //these are call back function
    void on_connect(int rc);
    void on_disconnect(int );
    void on_publish(int );
    void on_subscribe(int mid,int qos_count,const int *granted_qos);
    void on_message(const struct mosquitto_message *message);
    void on_log(int level, const char * str);

    void connectMqtt();
    void disConnectMqtt();
    int zjPublish(const std::string topic,const std::string str);
    int zjSubscribe(const std::string topic);
    void zjLoopForErver();

    bool isConnected(){return connectFlag;}
    void setShowDebug(bool flag){showDebug = flag;}
    std::queue<std::string> *getMqttQueue(){return &mqttQueue;}
    std::mutex              *getMqttQueueMutex(){return &mqttQueueMutex;}

    bool                   doReconnectFlag;

private:
    bool connectFlag;
    bool showDebug;
    static int mqttNum;

    std::queue<std::string> mqttQueue;
    std::mutex              mqttQueueMutex;

    std::set<std::string>  mqttSubs;
    std::mutex             mqttSubsMutex;

    std::mutex             mqttPubMutex;






};



}



#endif // ZJMQTT_H
