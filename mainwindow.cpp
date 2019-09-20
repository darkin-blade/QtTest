#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // 设置为无边框
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
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
    this->setMinimumWidth(screenRect.width());
    this->setMinimumHeight(screenRect.height());
//    this->showFullScreen();

    // 设置透明
//    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowOpacity(1);
    // this->setStyleSheet("MainWindow{background: transparent;}");

    // 嵌入网页
    webView = new WebView(this);
//    webView->installEventFilter(this);

    webView->load(QUrl("http://localhost:4000"));
    webView->resize(screenRect.width(), screenRect.height());
    webView->show();
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        qDebug() << "shit";
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        MainWindow::keyPressEvent(keyEvent);
        if (keyEvent->key() == Qt::Key_Escape) {
            this->close();
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "fuck";
    QMainWindow::keyPressEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}
