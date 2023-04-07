#pragma once

#include <QMainWindow>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLabel;
class QPushButton;

class CalculatorController;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initWindow();
    void addLabels();
    void addWidgetsToLayouts();
    void addOptions(QWidget *parent);
    void addNumbers(QWidget *parent);
    void addOperators(QWidget *parent);
    void addEqual(QWidget *parent);
    void setSpacingBeetwenElements();

private:
    QWidget *_centralWidget{ nullptr };
    QWidget *_buttonsWidget{ nullptr };
    QWidget *_digitsWidget{ nullptr };
    QWidget *_operatorsWidget{ nullptr };
    QWidget *_optionsWidget{ nullptr };
    QWidget *_numbersWidget{ nullptr };

    QVBoxLayout *_mainLayout{ nullptr };
    QHBoxLayout *_buttonsLayout{ nullptr };
    QVBoxLayout *_digitsLayout{ nullptr };
    QVBoxLayout *_operatorsLayout{ nullptr };
    QHBoxLayout *_optionsLayout{ nullptr };
    QGridLayout *_numbersLayout{ nullptr };

    QLabel *_stackLabel{ nullptr };
    QLabel *_resultLabel{ nullptr };

    CalculatorController *_controller{ nullptr };
};
