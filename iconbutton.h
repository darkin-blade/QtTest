#ifndef ICONBUTTON_H
#define ICONBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
#include <QPoint>

class IconButton : public QPushButton
{
public:
    IconButton(QWidget *parent = Q_NULLPTR);

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    bool isMoving;
    int posX, posY;
};

#endif // ICONBUTTON_H
