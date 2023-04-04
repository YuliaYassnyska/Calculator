#pragma once

#include <QLabel>

class ResultLabel : public QLabel
{
public:
    ResultLabel(QWidget *parent);

private:
    void paintEvent(QPaintEvent *event) override;
};
