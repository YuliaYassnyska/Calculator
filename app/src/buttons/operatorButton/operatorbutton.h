#pragma once

#include <QPushButton>

class OperatorButton : public QPushButton
{
public:
    OperatorButton(const QString &text, QWidget *parent);

private:
    void paintEvent(QPaintEvent *event) override;
};
