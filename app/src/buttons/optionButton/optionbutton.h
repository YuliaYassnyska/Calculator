#pragma once

#include <QPushButton>

class OptionButton : public QPushButton
{
public:
    OptionButton(const QString &text, QWidget *parent);

private:
    void paintEvent(QPaintEvent *event) override;
};
