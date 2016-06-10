#ifndef LITTERAL_H
#define LITTERAL_H

#include <Qstring>

/**
 * Classe abstraite representant une Litterale generique et les elements communs des Litterales de l'application
 * Les methodes sont virtuelles pures et permettent la manipulation de littérales en dehors de la classe sans
 * connaitre leur type exact
 */

class Litteral
{
public:
    virtual ~Litteral() {}
    virtual const QString toString() const =0;
    virtual void ajouterChiffre(int chiffre) = 0;
    virtual void setSlashEntre(bool slashEntre = true) = 0;
        virtual void setDollarEntre(bool dollarEntre = true) = 0;
};

#endif // LITTERAL_H
