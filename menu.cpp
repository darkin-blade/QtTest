#include "menu.h"

Menu::Menu(QWidget *parent) : QMainWindow(parent)
{
    init();
}

void Menu::init()
{
    this->setFixedSize(200, 200);
    this->setWindowTitle("menu");

    tray = new QSystemTrayIcon(this);
    tray->setIcon(QIcon(QPixmap("/home/lynx/Pictures/Aatrox256.png")));
    tray->show();
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(TrayIconAction(QSystemTrayIcon::ActivationReason)));

    menu = new QMenu(this);
    reset = new QAction(this);
    reset->setText("show");
    connect(reset, SIGNAL(triggered()), this, SLOT(showNormal()));

    quit = new QAction(this);
    quit->setText("quit");
    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));

    tray->setContextMenu(menu);
    menu->addAction(reset);
    menu->addAction(quit);
}

void Menu::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
}

void Menu::TrayIconAction(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger) {
        this->showNormal();
    }
}
