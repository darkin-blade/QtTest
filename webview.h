#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebEngineView>

class WebView : public QWebEngineView
{
public:
    WebView(QWidget *parent = Q_NULLPTR);

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // WEBVIEW_H
