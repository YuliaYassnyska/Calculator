#pragma once

#include <QPushButton>

class OptionButton : public QPushButton
{
public:
    OptionButton(const QString &text, const QString &image, QWidget *parent);

private:
    void paintEvent(QPaintEvent *event) override;
    const QString _image;
};
