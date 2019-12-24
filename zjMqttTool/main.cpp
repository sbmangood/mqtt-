#include "mainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;

    w.show();
    w.setWindowTitle(u8"知津科技mqtt工具      -ywh");
    w.setFixedSize(745,525);
    //w.setWindowIcon(":/images/zhijintech.ico");

    return a.exec();
}
