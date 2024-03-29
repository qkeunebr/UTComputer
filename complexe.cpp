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
         if(ReReel != 0.0)
            string = QString::number(ReReel);
        //Si il y a un dollar pour séparer la partie réelle de la partie imaginaire (partie imaginaire non nulle)
        if (symboleDollar && ImReel !=0.0) {
            string += " " + QString::number(ImReel) + "i";
        }
    }
    else if (estunEntier){
       if(ReEntier != 0)
       string = QString::number(ReEntier);
       //Si il y a un dollar pour séparer la partie réelle de la partie imaginaire (partie imaginaire non nulle)
       if (symboleDollar && ImEntier!=0) {
           string += " " + QString::number(ImEntier) + "i";
       }
    }
    else{
        //Le complexe est un rationnel
        if(cReRationnel.getNumerateur()!=0)
        string = cReRationnel.toString();
        if (symboleDollar && cImRationnel.getNumerateur()!=0) {
            string += " " + cImRationnel.toString() + "i";
        }
        }
    return string;
}


/**
 * \fn void Complexe::setSlashEntre(bool slashEntre)
 * \brief Surcharge de la méthode setSlashEntre(bool slashEntre) pour la classe Complexe.
 *
 * \param Variable de type booléenne.
 * \return
 */
void Complexe::setSlashEntre(bool slashEntre) {
    if (!estunReel && !estunEntier) {
        if (!symboleDollar) {
            cReRationnel.setSlashEntre(slashEntre);
        }
        else {
            cImRationnel.setSlashEntre(slashEntre);
        }
    }
}

/**
 * \fn void Complexe::ajouterChiffre(int chiffre)
 * \brief Surcharge de la méthode ajouterChiffre(int chiffre) pour la classe Complexe.
 *
 * \param Variable de type integer.
 * \return
 */
void Complexe::ajouterChiffre(int chiffre){
    if (estunReel) {
        if(!symboleDollar){
                ReReel*=10;
                ReReel+=chiffre;
            }
        else{
            ReReel*=10;
            ReReel+=chiffre;
            ImReel*=10;
            ImReel+=chiffre;
         }
    }
    else if (estunEntier){
        if(!symboleDollar){
                ReEntier*=10;
                ReEntier+=chiffre;
            }
        else{
            ReEntier*=10;
            ReEntier+=chiffre;
            ImEntier*=10;
            ImEntier+=chiffre;
         }
    }
    else {
        if (!symboleDollar) {
            cReRationnel.ajouterChiffre(chiffre);
        }
        else {
            cImRationnel.ajouterChiffre(chiffre);
        }
    }
}
