#include "numberbutton.h"

#include <QPainter>

NumberButton::NumberButton(const QString &text, const QString &image, QWidget *parent)
    : QPushButton(text, parent), _image{ image }
{
    setFixedSize(45, 45);
    setFlat(true);
    QFont font("serif", 18, 60);
    setFont(font);
    QPalette palette;
    palette.setColor(foregroundRole(), Qt::white);
    setPalette(palette);
}

void NumberButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const int penWidth{ 1 };
    const int cornerRadius{ 10 };
    QRect buttonRect{ rect() };
    QRect borderRect{ QRect{ buttonRect.x() + penWidth, buttonRect.y() + penWidth,
                             buttonRect.width() - penWidth * 2,
                             buttonRect.height() - penWidth * 2 } };

    QPixmap pixmap{ QPixmap{ _image }.scaled(borderRect.size()) };

    QPen pen(Qt::white);
    pen.setWidth(penWidth);
    painter.setPen(pen);
    painter.drawRoundedRect(borderRect, cornerRadius, cornerRadius);

    QBrush brush{ pixmap };
    if (!isDown())
        painter.setOpacity(0.6);
    painter.setBrush(brush);
    painter.drawRoundedRect(borderRect, cornerRadius, cornerRadius);

    painter.setOpacity(1.0);
    painter.drawText(borderRect, Qt::AlignCenter, text());
}
