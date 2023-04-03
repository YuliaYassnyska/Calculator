#pragma once

#include <QPushButton>

class OperatorButton : public QPushButton
{
public:
    OperatorButton(const QString &text, const QString &image, QWidget *parent);

private:
    void paintEvent(QPaintEvent *event) override;
    const QString _image;
};
