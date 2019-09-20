#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    qDebug() << __FILE__;
    qDebug() << __FUNCTION__;

    return a.exec();
}
