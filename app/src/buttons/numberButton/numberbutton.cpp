#include "numberbutton.h"

#include <QPainter>

NumberButton::NumberButton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    setFixedSize(45, 45);
    setFlat(true);
}

void NumberButton::paintEvent(QPaintEvent *event)
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
