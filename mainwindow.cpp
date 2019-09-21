#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // 设置为无边框
    this->setObjectName("main window");
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
//    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);

    // 获取屏幕分辨率
    int totalWidth = 0, totalHeight = 0;
    QDesktopWidget *desktopWidget = QApplication::desktop();
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
    this->setGeometry(0, 0, 0, 0);
    this->setMinimumWidth(totalWidth);
    this->setMinimumHeight(totalHeight);

    // 设置透明
    this->setWindowOpacity(1);

    // 嵌入网页
    webView = new WebView(this);
    webView->setObjectName("web");
    webView->installEventFilter(this);

    webView->load(QUrl("http://localhost:4000"));
    webView->resize(this->width(), this->height());
    webView->show();

    // 添加按钮
//    IconButton *btn[5];
//    for (int i = 0; i < 5; i ++) {
//        btn[i] = new IconButton(this);
//        btn[i]->move(0, 100 * i);
//    }

    // 检测屏幕分辨率变化
    connect(desktopWidget, SIGNAL(resized(int)), this, SLOT(changeSize()));
//    connect(desktopWidget, SIGNAL(screenCountChanged(int)), this, SLOT(changeSize()));
}

void MainWindow::changeSize()
{
    qDebug() << __FUNCTION__;
}

bool MainWindow::event(QEvent *event)
{
    return QMainWindow::event(event);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::ShortcutOverride) {
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
