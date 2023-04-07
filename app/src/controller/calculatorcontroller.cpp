#include "calculatorcontroller.h"
#include "model/calculatormodel.h"

CalculatorController::CalculatorController() : _model{ new CalculatorModel() }
{
}

void CalculatorController::addNumber(double number)
{
    _model->addNumber(number);
}

void CalculatorController::addOperator(char oper)
{
    _model->addOperator(oper);
}

void CalculatorController::replaceLastOperator(char oper)
{
    const unsigned long index{ _model->operators().size() - 1 };
    _model->replaceOperator(oper, index);
}

void CalculatorController::deleteNumbers()
{
    _model->deleteNumbers();
}

void CalculatorController::deleteOperators()
{
    _model->deleteOperators();
}

void CalculatorController::deleteLastOperator()
{
    _model->deleteLastOperator();
}

QString CalculatorController::getResult()
{
    double result{ _model->numbers().front() };

    result = countExpression(result, 0);

    _model->deleteNumbers();
    _model->deleteOperators();

    return QString::number(result);
}

bool CalculatorController::isHighPriority(char oper) const
{
    return oper == 'x' | oper == '/';
}

double CalculatorController::countByOperator(double first, double second, char oper)
{
    switch (oper)
    {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case 'x':
        return first * second;
    case '/':
        return first / second;
    }
}

double CalculatorController::countExpression(double value, int operIndex)
{
    if (operIndex == _model->operators().size() - 1)
    {
        return countByOperator(value, _model->numbers().at(operIndex + 1),
                               _model->operators().at(operIndex));
    }

    if (!isHighPriority(_model->operators().at(operIndex))
        && isHighPriority(_model->operators().at(operIndex + 1)))
    {
        double next{ _model->numbers().at(operIndex + 1) };
        char oper{ _model->operators().at(operIndex) };
        if (oper == '-')
        {
            oper = '+';
            next = -next;
        }

        return countByOperator(value, countExpression(next, operIndex + 1), oper);
    }

    return countExpression(countByOperator(value, _model->numbers().at(operIndex + 1),
                                           _model->operators().at(operIndex)),
                           operIndex + 1);
}
