#include "mainwindow.h"
#include "buttons/numberButton/numberbutton.h"
#include "buttons/operatorButton/operatorbutton.h"
#include "buttons/optionButton/optionbutton.h"
#include "centralWidget/centralwidget.h"
#include "labels/resultLabel/resultlabel.h"
#include "labels/stackLabel/stacklabel.h"

#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>

QVector<QPushButton *> options(QWidget *parent)
{
    return { new OptionButton("C", ":/image/resources/shark_c.jpg", parent),
             new OptionButton("CE", ":/image/resources/shark_ce.jpg", parent) };
}

QVector<QPushButton *> operators(QWidget *parent)
{
    return { new OperatorButton("/", ":/image/resources/divide.jpg", parent),
             new OperatorButton("x", ":/image/resources/multiply.jpg", parent),
             new OperatorButton("-", ":/image/resources/minus.jpg", parent),
             new OperatorButton("+", ":/image/resources/plus.jpg", parent) };
}

QVector<QPushButton *> numbers(QWidget *parent)
{
    return { new NumberButton("1", ":/image/resources/one.jpg", parent),
             new NumberButton("2", ":/image/resources/two.jpg", parent),
             new NumberButton("3", ":/image/resources/three.jpg", parent),
             new NumberButton("4", ":/image/resources/four.webp", parent),
             new NumberButton("5", ":/image/resources/five.jpeg", parent),
             new NumberButton("6", ":/image/resources/six.webp", parent),
             new NumberButton("7", ":/image/resources/seven.jpeg", parent),
             new NumberButton("8", ":/image/resources/eight.jpeg", parent),
             new NumberButton("9", ":/image/resources/nine.jpeg", parent),
             new NumberButton(".", ":/image/resources/dot.jpeg", parent),
             new NumberButton("0", ":/image/resources/zero.avif", parent),
             new NumberButton("=", ":/image/resources/equal.jpeg", parent) };
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      _centralWidget{ new CentralWidget{ parent } },
      _buttonsWidget{ new QWidget{ parent } },
      _digitsWidget{ new QWidget{ parent } },
      _operatorsWidget{ new QWidget{ parent } },
      _optionsWidget{ new QWidget{ parent } },
      _numbersWidget{ new QWidget{ parent } },
      _mainLayout{ new QVBoxLayout(parent) },
      _buttonsLayout{ new QHBoxLayout(_buttonsWidget) },
      _digitsLayout{ new QVBoxLayout(_digitsWidget) },
      _operatorsLayout{ new QVBoxLayout(_operatorsWidget) },
      _optionsLayout{ new QHBoxLayout(_optionsWidget) },
      _numbersLayout{ new QGridLayout(_numbersWidget) },
      _stackLabel{ new StackLabel{ parent } },
      _resultLabel{ new ResultLabel{ parent } }
{
    initWindow();
    addLabels();
    addWidgetsToLayouts();
    addOperators(parent);
    addOptions(parent);
    addNumbers(parent);
    setSpacingBeetwenElements();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initWindow()
{
    setWindowTitle(QStringLiteral("Magic"));
    setFixedSize(300, 450);
    setCentralWidget(_centralWidget);
    _centralWidget->setLayout(_mainLayout);
}

void MainWindow::addLabels()
{
    _mainLayout->addWidget(_stackLabel);
    _mainLayout->addWidget(_resultLabel);
}

void MainWindow::addWidgetsToLayouts()
{
    _mainLayout->addWidget(_buttonsWidget, 0, Qt::AlignCenter);
    _buttonsLayout->addWidget(_digitsWidget, 0, Qt::AlignCenter);
    _buttonsLayout->addWidget(_operatorsWidget, 0, Qt::AlignRight);
    _digitsLayout->addWidget(_optionsWidget, 10, Qt::AlignCenter);
    _digitsLayout->addWidget(_numbersWidget, 20, Qt::AlignCenter | Qt::AlignTop);
}

void MainWindow::addOptions(QWidget *parent)
{
    for (const auto option : options(parent))
    {
        _optionsLayout->addWidget(option);
    }
}

void MainWindow::addNumbers(QWidget *parent)
{
    const int maxColumns{ 3 };
    int row{ 0 };
    int column{ 0 };
    for (const auto number : numbers(parent))
    {
        _numbersLayout->addWidget(number, row, column++);
        if (column == maxColumns)
        {
            column = 0;
            row++;
        }
    }
}

void MainWindow::addOperators(QWidget *parent)
{
    for (const auto oper : operators(parent))
    {
        _operatorsLayout->addWidget(oper);
    }
}

void MainWindow::setSpacingBeetwenElements()
{
    _digitsLayout->setAlignment(Qt::AlignTop);
    _digitsLayout->setContentsMargins(0, 0, 0, 0);
    _digitsLayout->setSpacing(0);
    _numbersLayout->setContentsMargins(0, 0, 0, 0);
    _optionsLayout->setAlignment(Qt::AlignTop);
}
