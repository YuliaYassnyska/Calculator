#pragma once

#include <QString>

namespace Utils
{
bool isOperator(char symbol)
{
    QString operators{ QStringLiteral("x/-+") };

    return operators.contains(symbol);
}
} // namespace Utils
