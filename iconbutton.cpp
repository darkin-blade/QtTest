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
    isMoving = true;
    posX = e->globalPos().x() - pos().x();
    posY = e->globalPos().y() - pos().y();
    return QPushButton::mousePressEvent(e);
}

void IconButton::mouseMoveEvent(QMouseEvent *e)
{
    if (isMoving) {
        this->move(e->globalPos().x() - posX, e->globalPos().y() - posY);
    }
    return QPushButton::mouseMoveEvent(e);
}

void IconButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (isMoving) {
        isMoving = false;
        this->move(e->globalPos().x() / 100 * 100, e->globalPos().y() / 100 * 100);
    }
    return QPushButton::mouseReleaseEvent(e);
}
