#pragma once

#include <QLabel>

class StackLabel : public QLabel
{
public:
    StackLabel(QWidget *parent);

private:
    void paintEvent(QPaintEvent *event) override;
};
