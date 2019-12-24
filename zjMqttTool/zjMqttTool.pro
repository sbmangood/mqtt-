#-------------------------------------------------
#
# Project created by QtCreator 2019-12-03T09:34:35
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zjMqttTool
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainWindow.cpp \
    mainLogic/mainlogic.cpp \
    mqtt/zjPahoMqtt/zjpahomqtt.cpp \
    mqtt/zjMqtt.cpp \
    configs/configdeal.cpp \
    cJSON/cJSON.c \
    zjTinyLog/zjTinyLog.cpp

HEADERS += \
        mainWindow.h \
    mainLogic/mainlogic.h \
    mqtt/paho/include/MQTTAsync.h \
    mqtt/paho/include/MQTTClient.h \
    mqtt/paho/include/MQTTClientPersistence.h \
    mqtt/paho/include/MQTTProperties.h \
    mqtt/paho/include/MQTTReasonCodes.h \
    mqtt/paho/include/MQTTSubscribeOpts.h \
    mqtt/zjPahoMqtt/paho/include/MQTTAsync.h \
    mqtt/zjPahoMqtt/paho/include/MQTTClient.h \
    mqtt/zjPahoMqtt/paho/include/MQTTClientPersistence.h \
    mqtt/zjPahoMqtt/paho/include/MQTTProperties.h \
    mqtt/zjPahoMqtt/paho/include/MQTTReasonCodes.h \
    mqtt/zjPahoMqtt/paho/include/MQTTSubscribeOpts.h \
    mqtt/zjPahoMqtt/zjpahomqtt.h \
    mqtt/mosquitto.h \
    mqtt/mosquitto_plugin.h \
    mqtt/mosquitto_pluginold.h \
    mqtt/mosquittopp.h \
    mqtt/mosquittoppOld.h \
    mqtt/zjMqtt.h \
    configs/configdeal.h \
    cJSON/cJSON.h \
    zjTinyLog/zjTinyLog.h

FORMS += \
        mainwindow.ui

LIBS += -L$$PWD/mqtt/zjPahoMqtt/paho/lib    \
        -lpaho-mqtt3a   -lpaho-mqtt3as  -lpaho-mqtt3c   -lpaho-mqtt3cs

LIBS += -L$$PWD/mqtt    \
        -lmosquitto     -lmosquittopp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

RC_ICONS =   icon.ico
#RC_FILE =   icon.rc
