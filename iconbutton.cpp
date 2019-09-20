#include "iconbutton.h"

IconButton::IconButton(QWidget *parent) :
    QPushButton(parent)
{
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
    this->setMaximumHeight(100);
    this->setMaximumWidth(100);
}

void IconButton::mousePressEvent(QMouseEvent *e)
{
    qDebug() << __FILE__;
    qDebug() << __FUNCTION__;
    qDebug() << e->globalPos();
//    qDebug() << pos();
    isMoving = true;
    return QPushButton::mousePressEvent(e);
}

void IconButton::mouseMoveEvent(QMouseEvent *e)
{
    if (isMoving) {
        this->move(e->globalPos());
    }
    return QPushButton::mouseMoveEvent(e);
}

void IconButton::mouseReleaseEvent(QMouseEvent *e)
{
    return QPushButton::mouseReleaseEvent(e);
}

