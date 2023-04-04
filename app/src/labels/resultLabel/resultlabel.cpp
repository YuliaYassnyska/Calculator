#include "resultlabel.h"

#include <QPainter>

ResultLabel::ResultLabel(QWidget *parent) : QLabel(parent)
{
    setFixedHeight(50);
}

void ResultLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::white);
    const int penWidth{ 2 };
    pen.setWidth(penWidth);
    painter.setPen(pen);
    QRect labelRect{ rect() };
    QRect borderRect{ QRect{ labelRect.x() + penWidth, labelRect.y() + penWidth,
                             labelRect.width() - penWidth * 2,
                             labelRect.height() - penWidth * 2 } };
    painter.drawRoundedRect(borderRect, 10, 10);

    QBrush brush{ QColor{ 38, 217, 237 } };
    painter.setBrush(brush);
    painter.setOpacity(0.6);
    painter.drawRoundedRect(borderRect, 10, 10);
}
