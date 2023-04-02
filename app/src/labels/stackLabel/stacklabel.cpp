#include "stacklabel.h"

StackLabel::StackLabel(QWidget *parent) : QLabel(parent)
{
    setFrameShape(QFrame::Shape::Box);
    setFixedHeight(30);
}
