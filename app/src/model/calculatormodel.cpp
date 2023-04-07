#include "calculatormodel.h"

std::vector<double> CalculatorModel::numbers()
{
    return _numbers;
}

std::vector<char> CalculatorModel::operators()
{
    return _operators;
}

void CalculatorModel::addNumber(double number)
{
    _numbers.push_back(number);
}

void CalculatorModel::addOperator(char oper)
{
    _operators.push_back(oper);
}

void CalculatorModel::replaceOperator(char oper, int index)
{
    _operators.at(index) = oper;
}

void CalculatorModel::deleteNumbers()
{
    _numbers.clear();
}

void CalculatorModel::deleteOperators()
{
    _operators.clear();
}

void CalculatorModel::deleteLastOperator()
{
    _operators.pop_back();
}
