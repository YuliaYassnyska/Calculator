#include "operatorbutton.h"

OperatorButton::OperatorButton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    setFixedSize(50, 50);
}
