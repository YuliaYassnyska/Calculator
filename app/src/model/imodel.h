#pragma once

#include <vector>

class IModel
{
public:
    virtual std::vector<double> numbers() = 0;
    virtual std::vector<char> operators() = 0;

    virtual void addNumber(double number) = 0;
    virtual void addOperator(char oper) = 0;
    virtual void replaceOperator(char oper, int index) = 0;
    virtual void deleteNumbers() = 0;
    virtual void deleteOperators() = 0;
    virtual void deleteLastOperator() = 0;
};
