#include "mainwindow.h"

#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), _mainLayout{ new QVBoxLayout(parent) }
{
    this->setWindowTitle(QStringLiteral("Magic"));
    this->setFixedSize(300, 400);
    QWidget *centralWidget{ new QWidget{} };
    setCentralWidget(centralWidget);
    QPushButton *button{ new QPushButton("=", nullptr) };
    QPushButton *button2{ new QPushButton("+", nullptr) };
    QPushButton *button3{ new QPushButton("-", nullptr) };
    _mainLayout->addWidget(button);
    _mainLayout->addWidget(button2);
    _mainLayout->addWidget(button3);
    centralWidget->setLayout(_mainLayout);
    connect(button, &QPushButton::clicked,
            [button](bool) { qDebug() << "Clicked on " << button->text(); });
    connect(button2, &QPushButton::clicked,
            [button2](bool) { qDebug() << "Clicked on " << button2->text(); });
    connect(button3, &QPushButton::clicked,
            [button3](bool) { qDebug() << "Clicked on " << button3->text(); });
}

MainWindow::~MainWindow()
{
}
