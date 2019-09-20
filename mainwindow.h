#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iconbutton.h>
#include <webview.h>
#include <QMainWindow>
#include <QKeyEvent>
#include <QDesktopWidget>
#include <QRect>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MainWindow *ui;
    WebView *webView;
    QWidget *window;
};

#endif // MAINWINDOW_H
