#pragma once

#include <QWidget>

class CentralWidget : public QWidget
{
public:
    CentralWidget(QWidget *parent);

private:
    void paintEvent(QPaintEvent *event) override;
};
