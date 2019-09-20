#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // 设置为无边框
    this->setObjectName("main window");
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
//    this->setWindowFlags(Qt::WindowStaysOnBottomHint);

    // 获取屏幕分辨率
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect deskRect = desktopWidget->availableGeometry();
    QRect screenRect = desktopWidget->screenGeometry();

    // 设置全屏/最大化
//    this->setWindowState(Qt::WindowMaximized);
    this->setGeometry(screenRect);
    this->setMinimumWidth(screenRect.width());
    this->setMinimumHeight(screenRect.height());
//    this->showFullScreen();

    // 设置透明
//    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowOpacity(1);
    // this->setStyleSheet("MainWindow{background: transparent;}");

    // 嵌入网页
    webView = new WebView(this);
    webView->setObjectName("web");
    webView->installEventFilter(this);

    webView->load(QUrl("http://localhost:4000"));
    webView->resize(screenRect.width(), screenRect.height());
    webView->show();
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    qDebug() << __FILE__;
    qDebug() << watched->objectName();
    qDebug() << event->type();
    qDebug() << __FUNCTION__;
//    if (event->type() == QEvent::KeyPress) {
//        qDebug() << "key pressed";
//        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
//        MainWindow::keyPressEvent(keyEvent);
//        if (keyEvent->key() == Qt::Key_Escape) {
//            this->close();
//            return true;
//        } else {
//            return false;
//        }
//    } else {
//        return false;
//    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << __FILE__;
    qDebug() << __FUNCTION__;
    qDebug() << "key pressed";
    QMainWindow::keyPressEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}
