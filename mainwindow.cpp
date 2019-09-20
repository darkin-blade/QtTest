#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置为无边框
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
//    this->setWindowFlags(Qt::FramelessWindowHint);
//    this->setWindowFlags(Qt::WindowStaysOnBottomHint);

    // 设置全屏/最大化
    this->setWindowState(Qt::WindowMaximized);
//    this->showFullScreen();

    // 设置透明
//    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowOpacity(0.5);
    // this->setStyleSheet("MainWindow{background: transparent;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
