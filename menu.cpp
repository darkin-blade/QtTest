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
    
    int width = this->width();
    int height = this->height();

    btnQuit = new QPushButton(this);
    btnQuit->setText("quit");
    btnQuit->setFixedSize(100, 40);
    btnQuit->move(width - 100, height - 60);

    btnShow = new QPushButton(this);
    btnShow->setText("show");
    btnShow->setFixedSize(100, 40);
    btnShow->move(width - 200, height - 60);

    btnHide = new QPushButton(this);
    btnHide->setText("hide");
    btnHide->setFixedSize(100, 40);
    btnHide->move(width - 300, height - 60);
    
    connect(btnQuit, SIGNAL(clicked(bool)), this, SLOT(pressQuit()));
    connect(btnShow, SIGNAL(clicked(bool)), this, SLOT(pressShow()));
    connect(btnHide, SIGNAL(clicked(bool)), this, SLOT(pressHide()));

    // 背景
    background = new MainWindow();
}

void Menu::pressQuit()
{
    exit(0);
}

void Menu::pressHide()
{
    background->hide();
}

void Menu::pressShow()
{
    background->showNormal();
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
