#include "numberbutton.h"

NumberButton::NumberButton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    setFixedSize(50, 50);
}
