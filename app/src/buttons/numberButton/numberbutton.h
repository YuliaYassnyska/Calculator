#pragma once

#include <QPushButton>

class NumberButton : public QPushButton
{
public:
    NumberButton(const QString &text, QWidget *parent);

private:
    void paintEvent(QPaintEvent *event) override;
};
