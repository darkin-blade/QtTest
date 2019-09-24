#ifndef MENU_H
#define MENU_H

#include "mainwindow.h"
#include "server.h"
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QtGui>
#include <QPushButton>

class Menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    void init();// 初始化函数

    MainWindow *background;
 
    QSystemTrayIcon *tray;// 托盘图标

    QPushButton *btnQuit;
    QPushButton *btnHide;
    QPushButton *btnShow;
    QPushButton *btnLoad;

    Server *server;

protected:
    void closeEvent(QCloseEvent *event);

signals:

public slots:
    void TrayIconAction(QSystemTrayIcon::ActivationReason reason);// 对托盘图标操作的槽:本代码实现单机图标恢复窗口功能
    void pressQuit();
    void pressHide();
    void pressShow();
    void pressLoad();

private:
    bool isOpen;// 窗口是否打开
};

#endif // MENU_H
