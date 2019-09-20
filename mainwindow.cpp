#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include <QRect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // 设置为无边框
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
    this->setWindowFlags(Qt::FramelessWindowHint);
//    this->setWindowFlags(Qt::WindowStaysOnBottomHint);

    // 获取屏幕分辨率
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect deskRect = desktopWidget->availableGeometry();
    QRect screenRect = desktopWidget->screenGeometry();

    printf("available: %d %d\n", deskRect.width(), deskRect.height());
    printf("screen: %d %d\n", screenRect.width(), screenRect.height());

    // 设置全屏/最大化
//    this->setWindowState(Qt::WindowMaximized);
    this->setGeometry(screenRect);
    this->setMinimumHeight(screenRect.height());
//    this->showFullScreen();

    // 设置透明
//    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowOpacity(1);
    // this->setStyleSheet("MainWindow{background: transparent;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
