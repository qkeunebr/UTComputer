#include "complexe.h"

Complexe::Complexe(float pRe, float pIm) :Re(pRe),Im(pIm),cReRationnel(),cImRationnel(), estunReel(true), symboleDollar(Im!=0){}

Complexe::Complexe(Rationnel& pRe, Rationnel& pIm):cReRationnel(pRe),cImRationnel(pIm),Re(0),Im(0), estunReel(false), symboleDollar(pIm.getNumerateur()!=0){}

Complexe::Complexe(const Rationnel& pRe, const Rationnel& pIm) : Re(0), Im(0), symboleDollar(pIm.getNumerateur() != 0), cReRationnel(pRe), cImRationnel(pIm), estunReel(false)
{
}

const QString Complexe::toString() const {
    QString string;
    //Si le complexe est reel
    if (estunReel) {
         string = QString::number(Re);
        //Si il y a un dollar pour séparer la partie réelle de la partie imaginaire (partie imaginaire non nulle)
        if (symboleDollar) {
            string += "$" + QString::number(Im);
        }
    }
    else {
        //Le complexe est un rationnel
        string = cReRationnel.toString();
        if (symboleDollar) {
            string += "$" + cImRationnel.toString();
        }
    }
    return string;
}
