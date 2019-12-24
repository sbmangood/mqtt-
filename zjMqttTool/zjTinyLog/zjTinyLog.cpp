#include "zjTinyLog.h"

using namespace zjTinyLog;
ZjTinyLog::ZjTinyLog() :m_logFilePath("")
{
    m_logFilePath = std::string("./logs/log_");

}

ZjTinyLog::ZjTinyLog(std::string logFile)
{

   m_logFilePath=std::string("./logs/log_")+logFile;
}

ZjTinyLog::~ZjTinyLog()
{

}


void ZjTinyLog::writeLogFormat(const char *format, ...)
{
    va_list argList;
    std::string strArgData;
    char szBuffer[0x1024];
    ZeroMemory(szBuffer,0x1024);

    va_start(argList,format);
    vsprintf_s(szBuffer,format,argList);
    va_end(argList);

    strArgData = szBuffer;

    std::lock_guard<std::mutex> lock(writeMutex);
    std::fstream of(m_logFilePath+getFilePath(),std::ios::app);

    if(!of.is_open())
    {

        return;
    }

    of<<getSystemTimes()<<"         "<<strArgData<<std::endl;
    of.close();

}

std::string ZjTinyLog::getFilePath()
{
    std::string FlieTmp="";
    FlieTmp += getCurrentDate()+".txt";
    return FlieTmp;


}



std::string ZjTinyLog::getSystemTimes()
{
    time_t Time;
    char strTime[MAX_PATH];

    ZeroMemory(strTime,MAX_PATH);
    time(&Time);

    tm t;

    localtime_s(&t,&Time);
    strftime(strTime,100,"%Y-%m-%d %H:%M:%S",&t);

    std::string strTime2= strTime;
    return strTime2;
}

std::string ZjTinyLog::getCurrentDate()
{
    time_t currentTime;
    char    strTime[MAX_PATH];
    ZeroMemory(strTime,MAX_PATH);
    time(&currentTime);

    struct tm t;

    localtime_s(&t,&currentTime);

    strftime(strTime,100,"%Y-%m-%d",&t);

    std::string strTime2= strTime;
    return strTime2;
}
