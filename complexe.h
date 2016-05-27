#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <stdio.h>
#include "litteral.h"
#include "rationnel.h"

#include <QString>

class Complexe: public Litteral
{
private:
    float Re;
    float Im;
    bool estunReel;
    bool symboleDollar;
    //La littérale Complexe peut être composée de littérales rationnelles
    Rationnel cReRationnel;
    Rationnel cImRationnel;
public:
    Complexe(float pRe, float pIm);
    Complexe(Rationnel& pRe, Rationnel& pIm);
    Complexe(const Rationnel& pRe = Rationnel(), const Rationnel& pIm = Rationnel());

    //Accesseurs
    float getRe() const {return Re;}
    float getIm() const {return Im;}
    bool estReel() const {return estunReel;}
    const Rationnel& getReRationnel() const { return cReRationnel; }
    const Rationnel& getImRationnel() const { return cImRationnel; }
    const QString toString() const;
};

#endif // COMPLEXE_H
