#include "optionbutton.h"

#include <QPainter>

OptionButton::OptionButton(const QString &text, const QString &image, QWidget *parent)
    : QPushButton(text, parent), _image{ image }
{
    setFixedSize(75, 55);
    setFlat(true);
    QFont font("serif", 18, 60);
    setFont(font);
    QPalette palette;
    palette.setColor(foregroundRole(), Qt::white);
    setPalette(palette);
}

void OptionButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const int penWidth{ 1 };
    const int cornerRadius{ 10 };
    QRect buttonRect{ rect() };
    QRect borderRect{ QRect{ buttonRect.x() + penWidth, buttonRect.y() + penWidth,
                             buttonRect.width() - penWidth * 2,
                             buttonRect.height() - penWidth * 2 } };

    QPen pen(Qt::white);
    pen.setWidth(penWidth);
    painter.setPen(pen);
    painter.drawRoundedRect(borderRect, cornerRadius, cornerRadius);

    QPixmap pixmap{ QPixmap{ _image }.scaled(borderRect.size()) };
    QBrush brush{ pixmap };
    painter.setBrush(brush);
    if (!isDown())
        painter.setOpacity(0.6);
    painter.drawRoundedRect(borderRect, cornerRadius, cornerRadius);

    painter.setOpacity(1.0);
    painter.drawText(borderRect, Qt::AlignCenter, text());
}
