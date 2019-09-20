#include "webview.h"

WebView::WebView(QWidget *parent) :
    QWebEngineView(parent)
{
    ;
}

void WebView::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "key pressed";
}
