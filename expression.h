#ifndef EXPRESSION_H
#define EXPRESSION_H

#endif // EXPRESSION_H

#include "litteral.h"
#include <QString>

class Expression : public Litteral
{
private:
    QString exp;
public:
    Expression(QString exp = "");
    const QString toString() const{ return "\'" + exp + "\'"; }

    // Getters
    bool symboleDollar() const{ return false;}
    QString getExp() const {return exp;}

};
