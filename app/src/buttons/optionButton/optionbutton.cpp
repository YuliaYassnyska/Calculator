#include "optionbutton.h"

OptionButton::OptionButton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    setFixedSize(75, 50);
}
