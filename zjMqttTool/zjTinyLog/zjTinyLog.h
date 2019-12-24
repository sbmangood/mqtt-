#ifndef ZJTINYLOG_H
#define ZJTINYLOG_H
// a tiny log by zhijintech
#include <iostream>
#include <fstream>
#include <ctime>
#include <tchar.h>
#include <string>
#include <mutex>
#include <windows.h>


namespace zjTinyLog
{


class ZjTinyLog
{

public:
    ZjTinyLog();
    ZjTinyLog(std::string logFile);
    ~ZjTinyLog();

    template<class T>
    void writeLog(T x);
    void writeLogFormat(const char * format,...);


private:

    std::mutex   writeMutex;
    std::string getFilePath();
    std::string m_logFilePath;
    std::string getSystemTimes();
    std::string getCurrentDate();
    bool isPathExist(const std::string filsePath);



};


template<class T> void ZjTinyLog::writeLog(T x)
{

    std::lock_guard<std::mutex> lock(ZjTinyLog::writeMutex);
    std::fstream of(m_logFilePath+getFilePath(),std::ios::app);
    if(!of.is_open())
    {

        return;
    }

    of.seekp(std::ios::end);      //设置指针到尾部
    //of<<getSystemTimes()<<"      Line: "<<__LINE__<<"      Value: "<<x<<std::endl;
    of<<getSystemTimes()<<"         "<<x<<std::endl;
    of.close();

}

}
#endif // ZJTINYLOG_H
