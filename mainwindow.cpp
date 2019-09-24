#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // 设置为无边框
    this->setObjectName("main window");
    this->setWindowFlags(Qt::FramelessWindowHint);
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);

    // 获取屏幕分辨率
    desktopWidget = QApplication::desktop();
    changeSize();

    // 检测屏幕分辨率变化
    connect(desktopWidget, SIGNAL(resized(int)), this, SLOT(changeSize()));
    connect(desktopWidget, SIGNAL(screenCountChanged(int)), this, SLOT(changeSize()));
}

void MainWindow::changeSize()
{
    int totalWidth = 0, totalHeight = 0;
    int screenNum = desktopWidget->screenCount();
    for (int i = 0; i < screenNum; i ++) {
        if (desktopWidget->screen(i)->height() > totalHeight) {
            totalHeight = desktopWidget->screen(i)->height();
        }
        totalWidth += desktopWidget->screen(i)->width();
    }
//    QRect deskRect = desktopWidget->availableGeometry();
//    QRect screenRect = desktopWidget->screenGeometry();

    // 设置全屏/最大化
    qDebug() << __FUNCTION__;
    qDebug() << totalWidth << " " << totalHeight;

    this->setGeometry(0, 0, totalWidth, totalHeight);
    this->setFixedSize(QSize(totalWidth, totalHeight));

    qDebug() << this->minimumWidth() << " " << this->minimumHeight();

    // 设置透明
    this->setWindowOpacity(1);

    // 嵌入网页
    webView = new WebView(this);
    webView->setObjectName("web");
    webView->installEventFilter(this);

    webView->load(QUrl("http://127.0.0.1:8000"));
    webView->resize(this->width(), this->height());
    webView->show();
}

bool MainWindow::event(QEvent *event)
{
    return QMainWindow::event(event);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::ShortcutOverride) {
        qDebug() << __FUNCTION__;
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Escape) {
            exit(0);
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
    ;
}

MainWindow::~MainWindow()
{
    delete ui;
}
