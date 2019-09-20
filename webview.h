#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebEngineView>

class WebView : public QWebEngineView
{
public:
    WebView(QWidget *parent = Q_NULLPTR);

protected:
    void keyPressEvent(QKeyEvent *event);
    bool event(QEvent *event)
    {
//        qDebug() << __FILE__;
//        qDebug() << __FUNCTION__;
    }

    bool eventFilter(QObject *watched, QEvent *event)
    {
        qDebug() << __FILE__;
        qDebug() << __FUNCTION__;
    }
};

#endif // WEBVIEW_H
