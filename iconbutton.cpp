#include "iconbutton.h"

IconButton::IconButton() :
    QPushButton()
{
    qDebug() << __FILE__;
    qDebug() << __FUNCTION__;
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
    this->setMaximumHeight(100);
    this->setMaximumWidth(100);
}
