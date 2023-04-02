#include "operatorbutton.h"

#include <QPainter>

OperatorButton::OperatorButton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    setFixedSize(50, 65);
    setFlat(true);
}

void OperatorButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::black);
    const int penWidth{ 1 };
    pen.setWidth(penWidth);
    painter.setPen(pen);
    QRect labelRect{ rect() };
    QRect borderRect{ QRect{ labelRect.x() + penWidth, labelRect.y() + penWidth,
                             labelRect.width() - penWidth * 2,
                             labelRect.height() - penWidth * 2 } };
    painter.drawRoundedRect(borderRect, 10, 10);
}
