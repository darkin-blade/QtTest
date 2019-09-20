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

    // 获取屏幕分辨率
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect deskRect = desktopWidget->availableGeometry();
    QRect screenRect = desktopWidget->screenGeometry();

    // 设置全屏/最大化
    this->setGeometry(screenRect);
    this->setMinimumWidth(screenRect.width());
    this->setMinimumHeight(screenRect.height());

    // 设置透明
    this->setWindowOpacity(1);

    // 嵌入网页
    webView = new WebView(this);
    webView->setObjectName("web");
    webView->installEventFilter(this);

    webView->load(QUrl("http://localhost:4000"));
    webView->resize(screenRect.width(), screenRect.height());
    webView->show();

    // 添加按钮
//    QVBoxLayout *vlay = new QVBoxLayout(this);
//    QPushButton *btn[10];
//    for (int i = 0; i < 10; i ++) {
//        btn[i] = new QPushButton(this);
//        btn[i]->resize(100, 100);
//        vlay->addWidget(btn[i]);
//    }
//    this->setLayout(vlay);

    window = new QWidget;
    QPushButton *button1 = new QPushButton(this);
    QPushButton *button2 = new QPushButton(this);
    QPushButton *button3 = new QPushButton(this);
    QPushButton *button4 = new QPushButton(this);
    QPushButton *button5 = new QPushButton(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    window->setLayout(layout);
    setCentralWidget(window);
//    window->show();
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::ShortcutOverride) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        qDebug() << keyEvent->key();
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
