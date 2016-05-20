#ifndef LITTERAL_H
#define LITTERAL_H


/**
 * Classe abstraite representant une littérale
 */

#include <Qstring>

class Litteral
{
public:
    virtual ~Litteral() {}
    virtual const QString toString() const = 0;
};

#endif // LITTERAL_H
