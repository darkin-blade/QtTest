#include "mainwindow.h"
#include "menu.h"
#include "server.h"
#include <QApplication>

#include <QtCore/QCoreApplication>
#include <QtCore/QProcess>
#include <QtCore/QStringList>

int main(int argc, char *argv[])
{
    if (1) {

        QApplication a(argc, argv);

        Menu m;

    //    qDebug() << __FILE__;
    //    qDebug() << __FUNCTION__;

        Server *server = new Server();
        server->start();

        m.showNormal();// 在主窗口显示

        return a.exec();
    } else {

        Server *server = new Server();
        server->start();

        for (int i = 0; i < 10; i ++) {
            qDebug() << "2";
        }


        return 0;
    }
}
