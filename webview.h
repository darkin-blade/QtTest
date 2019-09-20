#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebEngineView>

class WebView : public QWebEngineView
{
public:
    WebView(QWidget *parent = Q_NULLPTR);
};

#endif // WEBVIEW_H
