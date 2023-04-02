#include "resultlabel.h"

ResultLabel::ResultLabel(QWidget *parent) : QLabel(parent)
{
    setFrameShape(QFrame::Shape::Box);
    setFixedHeight(50);
}
