/**
 * \file complexe.cpp
 * \brief Littérale Addition
 * \author Quentin Keunebroek
 * \version 1.0
 * \date 3 juin 2016
 *
 * Méthode de la littérale Complexe.
 *
 */

#include "complexe.h"

/**
 * \fn Complexe::Complexe(float pRe, float pIm)
 * \brief Constructeur de la classe Complexe.
 *
 * \param Deux variables de type float.
 * \return Objet de type Complexe.
 */
Complexe::Complexe(float pRe, float pIm) :Re(pRe),Im(pIm),cReRationnel(),cImRationnel(), estunReel(true), symboleDollar(Im!=0), Litteral(0){}

/**
 * \fn Complexe::Complexe(Rationnel& pRe, Rationnel& pIm)
 * \brief Constructeur de la classe Complexe.
 *
 * \param Deux objets de type Rationnel.
 * \return Objet de type Complexe.
 */
Complexe::Complexe(Rationnel& pRe, Rationnel& pIm):cReRationnel(pRe),cImRationnel(pIm),Re(0),Im(0), estunReel(false), symboleDollar(pIm.getNumerateur()!=0), Litteral(0){}

/**
 * \fn Complexe::Complexe(const Rationnel& pRe, const Rationnel& pIm)
 * \brief Constructeur de la classe Complexe.
 *
 * \param Deux objets de type const Rationnel.
 * \return Objet de type Complexe.
 */
Complexe::Complexe(const Rationnel& pRe, const Rationnel& pIm) : Re(0), Im(0), symboleDollar(pIm.getNumerateur() != 0), cReRationnel(pRe), cImRationnel(pIm), estunReel(false), Litteral(0)
{
}

/**
 * \fn const QString Complexe::toString() const
 * \brief Surcharge de la méthode toString() pour la classe Complexe.
 *
 * \param
 * \return Objet de type QString représentant un objet de type Complexe.
 */
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
