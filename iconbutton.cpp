#include "iconbutton.h"

IconButton::IconButton(QWidget *parent) :
    QPushButton(parent)
{
    qDebug() << __FILE__;
    qDebug() << __FUNCTION__;
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
    this->setMaximumHeight(100);
    this->setMaximumWidth(100);
}

void IconButton::mousePressEvent(QMouseEvent *e)
{
}

void IconButton::mouseMoveEvent(QMouseEvent *e)
{
}

void IconButton::mouseReleaseEvent(QMouseEvent *e)
{
}

