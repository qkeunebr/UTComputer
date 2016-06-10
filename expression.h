#ifndef EXPRESSION_H
#define EXPRESSION_H

#endif // EXPRESSION_H

#include "litteral.h"
#include <QString>

/**
 * Classe représentant une Littérale Expression, héritant de la classe Litteral.
 */

class Expression : public Litteral
{
private:
    QString exp;
public:
    Expression(QString exp = "");
    const QString toString() const{ return "\"" + exp + "\""; }

    // Getters
    bool symboleDollar() const{ return false;}
    QString getExp() const {return exp;}

};
