#include "configdeal.h"

bool haveAnalysisFile(QString filePath)
{
    QFileInfo fileInfo(filePath);

    if(fileInfo.isFile())
    {
        qDebug()<<filePath;
        return true;
    }
    return false;
}








cJSON *getConfigTableByFile(QString filePath)
{
    if(haveAnalysisFile(filePath))
    {
        QFile file(filePath);
        file.open(QIODevice::ReadOnly);
        QTextStream in(&file);
        QString fileText = in.readAll();


        if(fileText.isEmpty())
        {
            qDebug()<<filePath<<" file is empty!";

            return nullptr;
        }
        cJSON * json=cJSON_Parse(fileText.toStdString().c_str());
        if(json==nullptr)
        {
            qDebug()<<filePath<<" cJSON_Parse==nullptr in getConfigTableByFile!";

        }

        return json;
    }
    else
    {
        qDebug()<<filePath<<" file is not existence in getConfigTableByFile!";

        return nullptr;
    }
}

bool saveCJSONToFile(std::string filePath,cJSON *saveJs)
{
    std::ofstream ofs(filePath,std::ios::out|std::ios::out);
    if(!ofs.is_open())
    {
        qDebug()<<"cant open file path"<<filePath.c_str();
        return false;
    }

    char *saveStr=cJSON_Print(saveJs);
    if(saveStr!=nullptr)
    {
        ofs<<saveStr;
        delete(saveStr);
    }



    ofs.close();

}

bool autoGetSubCjsonString(cJSON *json,QString subName,QString &getStr)
{
    if(json==nullptr)
    {
        return false;
    }
    cJSON *subJs=cJSON_GetObjectItem(json,subName.toStdString().c_str());
    if(subJs==nullptr)
    {
        return false;
    }

    getStr=subJs->valuestring;

    return true;
}
bool autoGetSubCjsonNumber(cJSON *json,QString subName,int &getNum)
{
    if(json==nullptr)
    {
        return false;
    }
    cJSON *subJs=cJSON_GetObjectItem(json,subName.toStdString().c_str());
    if(subJs==nullptr)
    {
        return false;
    }

    getNum=subJs->valueint;

    return true;
}
