#ifndef CONFIGDEAL_H
#define CONFIGDEAL_H
#include <iostream>
#include <map>
#include <utility>
#define _WINSOCKAPI_
#include <Windows.h>
#include <fstream>
#include <iterator>

#include <QFileInfo>
#include <QString>
#include <QFile>
#include <QDebug>

#include "cJSON/cJSON.h"

bool haveAnalysisFile(QString filePath);

cJSON *getConfigTableByFile(QString filePath);

bool saveCJSONToFile(std::string filePath,cJSON *saveJs);

bool autoGetSubCjsonString(cJSON *json,QString SubName,QString &getStr);
bool autoGetSubCjsonNumber(cJSON *json,QString subName,int &getNum);

#endif // CONFIGDEAL_H
