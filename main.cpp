#include "mainwindow.h"
#include "menu.h"
#include "server.h"
#include <QApplication>

#include <QtCore/QCoreApplication>
#include <QtCore/QProcess>
#include <QtCore/QStringList>

int main(int argc, char *argv[])
{
    if (0) {

        QApplication a(argc, argv);

        Menu m;
    //    m.showNormal();// 在主窗口显示

    //    qDebug() << __FILE__;
    //    qDebug() << __FUNCTION__;

        Server *server = new Server();
        server->local_host();


        return a.exec();
    } else {
        QString program = "ls";
        QStringList arguments;
        arguments << ".";

        QProcess *myProcess = new QProcess();
        myProcess->start(program, arguments);
        myProcess->waitForFinished();
        QByteArray output = myProcess->readAllStandardOutput();
//        QByteArray output = myProcess->readAllStandardError();
        qDebug() << output;

        return 0;
    }
}
