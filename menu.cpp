#include "menu.h"

Menu::Menu(QWidget *parent) : QMainWindow(parent)
{
    isOpen = true;
    init();
}

void Menu::init()
{
    this->setFixedSize(500, 300);// 菜单窗口的大小
    this->setWindowTitle("menu");

    // 托盘图标
    tray = new QSystemTrayIcon(this);
    tray->setIcon(QIcon(QPixmap("/home/lynx/Pictures/Aatrox256.png")));
    tray->show();
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(TrayIconAction(QSystemTrayIcon::ActivationReason)));

    // 设置菜单
    // menu = new QMenu(this);
    // // reset = new QAction(this);
    // // reset->setText("show");
    // // connect(reset, SIGNAL(triggered()), this, SLOT(showNormal()));

    // // `退出程序`选项
    // quit = new QAction(this);
    // quit->setText("quit");
    // connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

    // tray->setContextMenu(menu);
    // // menu->addAction(reset);
    // menu->addAction(quit);
    
    int width = this->width();
    int height = this->height();
    btnQuit = new QPushButton(this);
    
    connect(btnQuit, SIGNAL(clicked(bool)), this, SLOT(pressQuit()));
}

void Menu::pressQuit()
{
    exit(0);
}

void Menu::pressHide()
{
    ;
}

void Menu::pressShow()
{
    ;
}

void Menu::closeEvent(QCloseEvent *event)
{
    hide();
    isOpen = false;
    event->ignore();// 拦截关闭
}

void Menu::TrayIconAction(QSystemTrayIcon::ActivationReason reason)
{
    qDebug() << __FUNCTION__;
    qDebug() << reason;
    if (reason == QSystemTrayIcon::Trigger) {// 切换打开/关闭
        if (isOpen == true) {
            isOpen = false;
            this->hide();
        } else {
            isOpen = true;
            this->showNormal();
        }
    }
}
