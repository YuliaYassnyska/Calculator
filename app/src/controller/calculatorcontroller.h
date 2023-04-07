#pragma once

#include <vector>

#include <QString>

class IModel;

class CalculatorController
{
public:
    CalculatorController();

    void addNumber(double number);
    void addOperator(char oper);
    void replaceLastOperator(char oper);
    void deleteNumbers();
    void deleteOperators();
    void deleteLastOperator();
    QString getResult();
    bool isHighPriority(char oper) const;
    double countByOperator(double first, double second, char oper);
    double countExpression(double value, int operIndex);

    std::vector<double> numbers();
    std::vector<char> operators();

private:
    IModel *_model;
};
