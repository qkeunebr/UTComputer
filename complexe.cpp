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
#include <QTextStream>
#include <iostream>

/**
 * \fn Complexe::Complexe(float pRe, float pIm)
 * \brief Constructeur de la classe Complexe.
 *
 * \param Deux variables de type float.
 * \return Objet de type Complexe.
 */
Complexe::Complexe(int pRe, int pIm) :cReRationnel(),cImRationnel(), estunReel(false), symboleDollar(true), estunEntier(true), ReEntier(pRe), ImEntier(pIm), ReReel(), ImReel(){}

/**
 * \fn Complexe::Complexe(float pRe, float pIm)
 * \brief Constructeur de la classe Complexe.
 *
 * \param Deux variables de type float.
 * \return Objet de type Complexe.
 */
Complexe::Complexe(float pRe, float pIm) :ReReel(pRe), ImReel(pIm), ReEntier(), ImEntier(), cReRationnel(),cImRationnel(), estunReel(true), symboleDollar(pIm!=0.0), estunEntier(false){}

/**
 * \fn Complexe::Complexe(Rationnel& pRe, Rationnel& pIm)
 * \brief Constructeur de la classe Complexe.
 *
 * \param Deux objets de type Rationnel.
 * \return Objet de type Complexe.
 */
Complexe::Complexe(Rationnel& pRe, Rationnel& pIm):cReRationnel(pRe),cImRationnel(pIm), estunReel(false), estunEntier((pRe.getDenominateur()==1)&&(pIm.getDenominateur()==1)), symboleDollar(true),ReEntier(), ImEntier(),ReReel(), ImReel(){
}

/**
 * \fn Complexe::Complexe(const Rationnel& pRe, const Rationnel& pIm)
 * \brief Constructeur de la classe Complexe.
 *
 * \param Deux objets de type const Rationnel.
 * \return Objet de type Complexe.
 */
Complexe::Complexe(const Rationnel& pRe, const Rationnel& pIm) : cReRationnel(pRe),cImRationnel(pIm), estunReel(false), estunEntier((pRe.getDenominateur()==1)&&(pIm.getDenominateur()==1)), symboleDollar(true),ReEntier(), ImEntier(),ReReel(), ImReel()
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
    if (estunReel || estunEntier) {
         string = QString::number(ReReel);
        //Si il y a un dollar pour séparer la partie réelle de la partie imaginaire (partie imaginaire non nulle)
        if (symboleDollar && ImReel !=0.0) {
            string += " " + QString::number(ImReel) + "i";
        }
    }
    else if (estunEntier){
       string = QString::number(ReEntier);
       //Si il y a un dollar pour séparer la partie réelle de la partie imaginaire (partie imaginaire non nulle)
       if (symboleDollar && ImEntier!=0) {
           string += " " + QString::number(ImEntier) + "i";
       }
    }
    else{
        //Le complexe est un rationnel
        string = cReRationnel.toString();
        if (symboleDollar && cImRationnel.getNumerateur()!=0) {
            string += " " + cImRationnel.toString() + "i";
        }
        }
    return string;
}
