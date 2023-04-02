#include "centralwidget.h"

#include <QPainter>

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
}

void CentralWidget::paintEvent(QPaintEvent *event)
{
    QPixmap pixmap;

    pixmap.load(":/image/resources/ocean.jpg");

    QPainter paint(this);
    paint.drawPixmap(0, 0, pixmap);
    QWidget::paintEvent(event);
}
