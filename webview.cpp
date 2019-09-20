#include "webview.h"

WebView::WebView(QWidget *parent) :
    QWebEngineView(parent)
{
    qDebug() << __FILE__;
    qDebug() << __FUNCTION__;
    qDebug() << "create web view";
}

void WebView::keyPressEvent(QKeyEvent *event)
{
    ;
}
