#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <stdio.h>
#include "litteral.h"
#include "rationnel.h"

#include <QString>

class Complexe: public Litteral
{
private:
    float ReReel;
    float ImReel;
    int ReEntier;
    int ImEntier;
    bool estunReel;
    bool estunEntier;
    bool symboleDollar;
    //La littérale Complexe peut être composée de littérales rationnelles
    Rationnel cReRationnel;
    Rationnel cImRationnel;
public:
    Complexe(int pRe, int pIm);
    Complexe(float pRe, float pIm);
    Complexe(Rationnel& pRe, Rationnel& pIm);
    Complexe(const Rationnel& pRe = Rationnel(), const Rationnel& pIm = Rationnel());

    //Accesseurs
    float getReReel() const {return ReReel;}
    float getImReel() const {return ImReel;}
    bool estReel() const {return estunReel;}
    bool estEntier() const{return estunEntier;}
    int getReEntier() const{return ReEntier;}
    int getImEntier() const{return ImEntier;}
    bool getSymboleDollar() const{return symboleDollar;}
    const Rationnel& getReRationnel() const { return cReRationnel; }
    const Rationnel& getImRationnel() const { return cImRationnel; }
    const QString toString() const;
};

#endif // COMPLEXE_H
