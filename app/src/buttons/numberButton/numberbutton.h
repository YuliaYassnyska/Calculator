#pragma once

#include <QPushButton>

class NumberButton : public QPushButton
{
public:
    NumberButton(const QString &text, const QString &image, QWidget *parent);

private:
    void paintEvent(QPaintEvent *event) override;
    const QString _image;
};
