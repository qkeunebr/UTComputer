#ifndef RATIONNEL_H
#define RATIONNEL_H

#endif // RATIONNEL_H

#include "litteral.h"

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
};
