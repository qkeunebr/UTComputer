#ifndef RATIONNEL_H
#define RATIONNEL_H

#endif // RATIONNEL_H

#include "litteral.h"

/**
 * Classe représentant une Littérale Rationnel, héritant de la classe Litteral.Un Rationnel peut être composé d'entiers uniquement. Un entier est un Rationnel dont le dénominateur vaut 1.
 */

class Rationnel : public Litteral
{
private:
    int numerateur;
    int denominateur;
public:
    Rationnel(int n=0, int d=1):numerateur(n), denominateur(d){}
    const int& getNumerateur() const{return numerateur;}
    const int& getDenominateur() const{return denominateur;}
    const QString toString() const;
    void ajouterChiffre(int chiffre);
    void setSlashEntre(bool slashEntre = true){

            }
     void setDollarEntre(bool dollarEntre = true) { }
};
