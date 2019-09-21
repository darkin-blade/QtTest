#include "menu.h"

Menu::Menu(QWidget *parent) : QMainWindow(parent)
{
    isOpen = true;
    init();
}

void Menu::init()
{
    
    int widthMenu = 200;
    int heightMenu = 170;
    int widthBtn = 120;
    int heightBtn = 30;

    this->setFixedSize(widthMenu, heightMenu);// 菜单窗口的大小
    this->setWindowTitle("menu");

    // 托盘图标
    tray = new QSystemTrayIcon(this);
    tray->setIcon(QIcon(QPixmap("/home/lynx/Pictures/Aatrox256.png")));
    tray->show();
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(TrayIconAction(QSystemTrayIcon::ActivationReason)));

    btnQuit = new QPushButton(this);
    btnQuit->setText("quit");
    btnQuit->setFixedSize(widthBtn, heightBtn);
    btnQuit->move(40, (heightBtn + 10) * 3);

    btnShow = new QPushButton(this);
    btnShow->setText("show");
    btnShow->setFixedSize(widthBtn, heightBtn);
    btnShow->move(40, (heightBtn + 10) * 2);

    btnHide = new QPushButton(this);
    btnHide->setText("hide");
    btnHide->setFixedSize(widthBtn, heightBtn);
    btnHide->move(40, (heightBtn + 10) * 1);
    
    connect(btnQuit, SIGNAL(clicked(bool)), this, SLOT(pressQuit()));
    connect(btnShow, SIGNAL(clicked(bool)), this, SLOT(pressShow()));
    connect(btnHide, SIGNAL(clicked(bool)), this, SLOT(pressHide()));

    this->setStyleSheet(
        "Menu {"
        "   background: rgb(44, 45, 45);"
        "   border-radius: 100px;"
        "}"
        "QPushButton {"
        "   font-size: 18px;"
        "   background: rgb(240, 240, 240);"
        "   border: 0px solid red;"
        "   border-radius: 1px;"
        "}"
    );

    // 背景
    background = new MainWindow();
}

void Menu::pressQuit()
{
    exit(0);
}

void Menu::pressHide()
{
    background->close();
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
