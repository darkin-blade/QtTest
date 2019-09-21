#include "mainwindow.h"
#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu m;
    m.showNormal();// 在主窗口显示


//    qDebug() << __FILE__;
//    qDebug() << __FUNCTION__;

    return a.exec();
}
