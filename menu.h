#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QtGui>

class Menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    void init();// 初始化函数
 
    QSystemTrayIcon *tray;// 托盘图标
    QMenu *menu;// 托盘菜单
    QAction *reset;// 菜单实现功能:恢复窗口
    QAction *quit;// 菜单实现功能:退出程序

protected:
    void closeEvent(QCloseEvent *event);

signals:

public slots:
    void TrayIconAction(QSystemTrayIcon::ActivationReason reason);// 对托盘图标操作的槽:本代码实现单机图标恢复窗口功能

private:
    bool isOpen;// 窗口是否打开
};

#endif // MENU_H
