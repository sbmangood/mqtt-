#include "mainWindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    getConfigData();

    //m_mainLogic =   new mainLogic(this,m_mqttStruct.deviceId);
    readTpsLog=new zjTinyLog::ZjTinyLog("readTPS");



    ui->setupUi(this);
    setUi();

    connectUi();
    //m_mainLogic->connectMqtt1(m_mqttStruct);

}

mainWindow::~mainWindow()
{
    delete ui;
    if(m_mainLogic!=nullptr)
        delete m_mainLogic;
    delete readTpsLog;
}



bool mainWindow::getConfigData()
{
    initMqttStruct(m_mqttStruct);

    configJs=getConfigTableByFile(CONFIG_FILE_PATH);
    if(configJs==nullptr)
    {
        return false;
    }

    autoGetSubCjsonNumber(configJs,"port",m_mqttStruct.port);
    autoGetSubCjsonString(configJs,"ip",m_mqttStruct.ip);
    autoGetSubCjsonString(configJs,"deviceId",m_mqttStruct.deviceId);

    if(m_mqttStruct.port<100 || m_mqttStruct.port>26655)
    {
        m_mqttStruct.port=1883;
    }

    return true;
}

void mainWindow::initMqttStruct(mqttStruct &ms)
{
    ms.ip="127.0.0.1";
    ms.port=1883;
    ms.deviceId="deviceIdNo1";

}


void mainWindow::setUi()
{
    ui->lineEdit_ip->setText(m_mqttStruct.ip);
    ui->lineEdit_port->setText(QString::number(m_mqttStruct.port));
    ui->lineEdit_deviceId->setText(m_mqttStruct.deviceId);

}

void mainWindow::connectThisWithMainLogic()
{
    connect(this,SIGNAL(connectMqtt(mqttStruct)),
           m_mainLogic,SLOT(connectMqtt(mqttStruct)) );//mqttConnectOk()
    connect(this,SIGNAL(disConnectMqtt()),m_mainLogic,SLOT(disconnectMqtt()));
    connect(this,SIGNAL(pubMqtt(mqttPubStruct)),m_mainLogic,SLOT(mqttPub(mqttPubStruct)));
    connect(this,SIGNAL(subMqtt(QString)),m_mainLogic,SLOT(mqttSub(QString)));

    connect(m_mainLogic,SIGNAL(updateBrowserMainText(QString)),
            this,SLOT(updateBrowserMainText(QString)));


}

void mainWindow::connectUi()
{

    connect(ui->pushButton_connectOrDisConnect,
            SIGNAL(clicked()),this,SLOT(clickedConnectButton()));
    connect(ui->pushButton_send,
            SIGNAL(clicked()),this,SLOT(clickedSendButton()));
    connect(ui->pushButton_addSub,
            SIGNAL(clicked()),this,SLOT(clickedAddSub()));

    connect(ui->pushButton_clearSendText,
            SIGNAL(clicked()),this,SLOT(clickedClearSendText()));
    connect(ui->pushButton_clearMainText,
            SIGNAL(clicked()),this,SLOT(clickedClearMainText()));




}

void mainWindow::clickedConnectButton()
{
    m_mqttStruct.deviceId=ui->lineEdit_deviceId->text();
    if(m_mainLogic!=nullptr)
    {
        delete m_mainLogic;
        m_mainLogic =   new mainLogic(this,m_mqttStruct.deviceId);
    }
    else
    {
        m_mainLogic =   new mainLogic(this,m_mqttStruct.deviceId);
    }

    connectThisWithMainLogic();

    m_mqttStruct.ip=ui->lineEdit_ip->text();
    m_mqttStruct.port=ui->lineEdit_port->text().toInt();

    if(m_mqttStruct.port<100 || m_mqttStruct.port>26655)
    {
        m_mqttStruct.port=1883;
    }

    if( (ui->pushButton_connectOrDisConnect->text()) ==u8"连接" )
    {
        emit connectMqtt(m_mqttStruct);

        ui->pushButton_connectOrDisConnect->setText(u8"断开");
    }
    else if( (ui->pushButton_connectOrDisConnect->text()) ==u8"断开" )
    {
        emit disConnectMqtt();
        ui->pushButton_connectOrDisConnect->setText(u8"连接");
    }



}

void mainWindow::clickedSendButton()
{
    m_mqttPubStruct.topic=ui->lineEdit_pubTopic->text();
    m_mqttPubStruct.str=ui->textEdit_sendText->toPlainText();
    if(m_mqttPubStruct.topic!="" && m_mqttPubStruct.str!="")
    {
        emit pubMqtt(m_mqttPubStruct);
    }
}

void mainWindow::clickedAddSub()
{
    QString str=ui->lineEdit_subTopic->text();
    ui->lineEdit_subTopic->clear();
    if(str!="")
    {
        bool flag=false;
        for(auto it=subMqttList.begin();it!=subMqttList.end();it++)
        {
            if(str==(*it))
            {
                flag=true;
            }
        }
        if(!flag)
        {
            subMqttList.append(str);
            ui->textBrowser_subList->append(str);
            emit subMqtt(str);
        }

    }
}

void mainWindow::clickedClearSendText()
{
    ui->textEdit_sendText->clear();
}
void mainWindow::clickedClearMainText()
{
    ui->textBrowser_mainText->clear();
}

void mainWindow::updateBrowserMainText(QString str)
{
    if(ui->textBrowser_mainText==nullptr)
        return;

    static int cnt=0;



    qDebug()<<"old: "<<oldTps;
    qDebug()<<"new: "<<str;
    if(str!=oldTps &&str.indexOf("<-->")!=-1 )
    {
        oldTps=str;
        cnt++;
        ui->textBrowser_mainText->append(str);

        readTpsLog->writeLogFormat("TPS: %s",str.section("<-->",1,1).toStdString().c_str());

    }
    else
    {

        return;
    }

    if(cnt>50)
    {
        ui->textBrowser_mainText->clear();
        cnt=0;
    }



}
