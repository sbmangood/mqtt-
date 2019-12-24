#include "zjpahomqtt.h"

zjPahoMqtt::zjPahoMqtt(std::string id)
{
    conn_opts = MQTTClient_connectOptions_initializer;
    deviceId=id+"1";
    timeout=3000;
}



int zjPahoMqtt::connect(std::string const ip,int const port,int const heart)
{
    int rc;

    std::string addr=std::string("tcp://")+ip+":"+std::to_string(port);

    MQTTClient_create(&client,addr.c_str(),deviceId.c_str(),MQTTCLIENT_PERSISTENCE_NONE,nullptr);

    conn_opts.keepAliveInterval=heart;
    conn_opts.cleansession=1;

    if( (rc=MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS )
    {
        printf("Failed to connect, return code %d\n", rc);

    }
    return rc;
}


int zjPahoMqtt::zjPublish(const std::string topic,const std::string str)
{
    int rc;



    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    pubmsg.payload = (void *)str.c_str();
    pubmsg.payloadlen = str.length();
    pubmsg.qos = 1;
    pubmsg.retained = 0;

    MQTTClient_publishMessage(client, topic.c_str(), &pubmsg, &token);

    rc = MQTTClient_waitForCompletion(client, token, timeout);

    printf("Message with delivery token %d delivered\n", token);



    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);

    return rc;

}
