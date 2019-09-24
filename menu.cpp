#include "menu.h"

Menu::Menu(QWidget *parent) : QMainWindow(parent)
{
    isOpen = true;
    init();
}

void Menu::init()
{
    // 初始化菜单窗口
    int widthMenu = 200;
    int heightMenu = 230;
    int widthBtn = 120;
    int heightBtn = 30;

    this->setFixedSize(widthMenu, heightMenu);// 菜单窗口的大小
    this->setWindowTitle("menu");

    tray = new QSystemTrayIcon(this);// 托盘图标
    tray->setIcon(QIcon(QPixmap("/home/lynx/Pictures/Aatrox256.png")));
    tray->show();
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(TrayIconAction(QSystemTrayIcon::ActivationReason)));

    // 初始化按钮
    btnQuit = new QPushButton(this);
    btnQuit->setText("quit");
    btnQuit->setFixedSize(widthBtn, heightBtn);
    btnQuit->move(40, (heightBtn + 10) * 4);

    btnLoad = new QPushButton(this);
    btnLoad->setText("load");
    btnLoad->setFixedSize(widthBtn, heightBtn);
    btnLoad->move(40, (heightBtn + 10) * 3);

    btnShow = new QPushButton(this);
    btnShow->setText("show");
    btnShow->setFixedSize(widthBtn, heightBtn);
    btnShow->move(40, (heightBtn + 10) * 2);

    btnHide = new QPushButton(this);
    btnHide->setText("hide");
    btnHide->setFixedSize(widthBtn, heightBtn);
    btnHide->move(40, (heightBtn + 10) * 1);
    
    connect(btnShow, SIGNAL(clicked(bool)), this, SLOT(pressShow()));
    connect(btnHide, SIGNAL(clicked(bool)), this, SLOT(pressHide()));
    connect(btnLoad, SIGNAL(clicked(bool)), this, SLOT(pressLoad()));
    connect(btnQuit, SIGNAL(clicked(bool)), this, SLOT(pressQuit()));

    this->setStyleSheet(
        "Menu {"
        "   background: rgb(44, 45, 45);"
        "   border-radius: 100px;"
        "}"
        "QPushButton {"
        "   font-size: 18px;"
        "   background: rgb(230, 230, 230);"
        "   border: 0px solid red;"
        "   border-radius: 1px;"
        "}"
        "QPushButton:hover {"
        "   transition-duration: 1s"
        "   background: rgb(249, 249, 249);"
        "}"
    );

    // 初始化网页背景以及服务器
    background = new MainWindow();
    server = new Server();
}

void Menu::pressLoad()
{
    if (server->getSuccess() == -1) {
        server->start();// TODO
    }
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
