#pragma once

#include "imodel.h"

class CalculatorModel : public IModel
{
public:
    CalculatorModel() = default;

    std::vector<double> numbers() override;
    std::vector<char> operators() override;

    void addNumber(double number) override;
    void addOperator(char oper) override;
    void replaceOperator(char oper, int index) override;
    void deleteNumbers() override;
    void deleteOperators() override;
    void deleteLastOperator() override;

private:
    std::vector<double> _numbers;
    std::vector<char> _operators;
};
