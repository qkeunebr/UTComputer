/**
 * \file soustraction.cpp
 * \brief Operation Soustraction
 * \author Quentin Keunebroek
 * \version 1.0
 * \date 3 juin 2016
 *
 * Opération Soustraction pour tout type de Littérale.
 *
 */

#include "operationbinaire.h"

/**
 * \fn Soustraction::Soustraction(Litteral& l1, Litteral& l2)
 * \brief Fonction de construction de l'objet Soustraction.
 *
 * \param Deux objets de type littérale.
 * \return Opération binaire composée de deux littérales.
 */
Soustraction::Soustraction(Litteral& l1, Litteral& l2) : OperationBinaire(l1, l1)
{
}

/**
 * \fn Litteral* Soustraction::soustraction(const Rationnel& r1, const Rationnel& r2) const
 * \brief Fonction pour effectuer la soustraction entre deux objets rationnels.
 *
 * \param Deux objets de type Rationnel.
 * \return Littéral de type Rationnel.
 */
Litteral* Soustraction::soustraction(const Rationnel& r1, const Rationnel& r2) const{
    Litteral* result;
    Rationnel r(r1.getNumerateur()*r2.getDenominateur()-r2.getNumerateur()*r1.getDenominateur(), r1.getDenominateur()*r2.getDenominateur());
    result = new Rationnel(r.getNumerateur()/r.getDenominateur());
    return result;
}

/**
 * \fn Litteral* Soustraction::soustraction(const Complexe& c1, const Complexe& c2) const
 * \brief Fonction pour effectuer la soustraction entre deux objets complexes.
 *
 * \param Deux objets de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* Soustraction::soustraction(const Complexe& c1, const Complexe& c2) const{
    Litteral* result;
    if (c1.estReel()) {
        //c1 est un réel
           if (c2.estReel()) {
               //c2 est aussi un réel
               result = new Complexe(c1.getRe() - c2.getRe(), c1.getIm() - c2.getIm());

           }
           else {
           //c2 est un Rationnel
               result = new Complexe(Rationnel(((c1.getRe()*(float)c2.getReRationnel().getDenominateur())-(float)c2.getReRationnel().getNumerateur()), (float)c2.getReRationnel().getDenominateur()),
                                     Rationnel(((c1.getIm()*(float)c2.getImRationnel().getDenominateur())-(float)c2.getImRationnel().getNumerateur()), (float)c2.getImRationnel().getDenominateur()));
           }
     }
     else {
        //c1 est un Rationnel
           if (c2.estReel()) {
                result = new Complexe(Rationnel(((c2.getRe()*(float)c1.getReRationnel().getDenominateur())-(float)c1.getReRationnel().getNumerateur()), (float)c1.getReRationnel().getDenominateur()),
                                      Rationnel(((c2.getIm()*(float)c1.getImRationnel().getDenominateur())-(float)c1.getImRationnel().getNumerateur()), (float)c1.getImRationnel().getDenominateur()));
           }
           //c1 et c2 sont Rationnel
           else {
                result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur()*c2.getReRationnel().getDenominateur()-c2.getReRationnel().getNumerateur()*c1.getReRationnel().getDenominateur(), c1.getReRationnel().getDenominateur()*c2.getReRationnel().getDenominateur()),
                                      Rationnel(c1.getImRationnel().getNumerateur()*c2.getImRationnel().getDenominateur()-c2.getImRationnel().getNumerateur()*c1.getImRationnel().getDenominateur(), c1.getImRationnel().getDenominateur()*c2.getImRationnel().getDenominateur()));
           }
      }
    return result;
}

/**
 * \fn Litteral* Soustraction::soustraction(const Complexe& c1, const Rationnel& r1) const
 * \brief Fonction pour effectuer la soustraction entre un objet complexe et un objet rationnel.
 *
 * \param Un objet de type Complexe et un objet de type Rationnel.
 * \return Littéral de type Complexe.
 */
Litteral* Soustraction::soustraction(const Complexe& c1, const Rationnel& r1) const{
    const Complexe& cTor(r1);
    return soustraction(c1,cTor);
}

/**
 * \fn Litteral* Soustraction::soustraction(const Rationnel& r1, const Complexe& c1) const
 * \brief Fonction pour effectuer la soustraction entre un objet rationnel et un objet complexe.
 *
 * \param Un objet de type Rationnel et un objet de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* Soustraction::soustraction(const Rationnel& r1, const Complexe& c1) const{
    return soustraction(c1, r1);
}

/**
 * \fn Litteral* Soustraction::soustraction(const Expression& e1, const Expression& e2) const
 * \brief Fonction pour effectuer la soustraction entre deux objets Expression.
 *
 * \param Deux objets de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Soustraction::soustraction(const Expression& e1, const Expression& e2) const {
    return new Expression(e1.getExp() + " " + e2.getExp() + " -");
}

/**
 * \fn Litteral* Soustraction::soustraction(const Expression& e1, const Rationnel& r1) const
 * \brief Fonction pour effectuer la soustractin entre un objet Expression et un objet Rationnel.
 *
 * \param Un objet de type Expression et un objet de type Rationnel.
 * \return Littéral de type Expression.
 */
Litteral* Soustraction::soustraction(const Expression& e1, const Rationnel& r1) const{
    return new Expression(e1.getExp() + " " + r1.toString() + " -");
}

/**
 * \fn Litteral* Soustraction::soustraction(const Expression& e1, const Complexe& c1) const
 * \brief Fonction pour effectuer la soustraction entre un objet Expression et un objet Complexe.
 *
 * \param Un objet de type Expression et un objet de type Complexe.
 * \return Littéral de type Expression.
 */
Litteral* Soustraction::soustraction(const Expression& e1, const Complexe& c1) const {
    return new Expression(e1.getExp() + " " + c1.toString() + " -");
}

/**
 * \fn Litteral* Soustraction::soustraction(const Rationnel& r1, const Expression& e1) const
 * \brief Fonction pour effectuer la soustraction entre un objet Rationnel et un objet Expression.
 *
 * \param Un objet de type Rationnel et un objet de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Soustraction::soustraction(const Rationnel& r1, const Expression& e1) const{
    return new Expression(r1.toString() + " " + e1.getExp() + " -");
}

/**
 * \fn Litteral* Soustraction::soustraction(const Complexe& c1, const Expression& e1) const
 * \brief Fonction pour effectuer la soustraction entre un objet Complexe et un objet Expression.
 *
 * \param Un objet de type Complexe et un objet de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Soustraction::soustraction(const Complexe& c1, const Expression& e1) const {
    return new Expression(c1.toString() + " " + e1.getExp() + " -");
}

/**
 * \fn Litteral* Soustraction::getResult() const
 * \brief Fonction qui appelle les différentes méthodes soustraction selon le type de Littérale considéré
 *
 *
 * \return Objet de type littéral.
 */
Litteral* Soustraction::getResult() const {
    Expression* expfirst = dynamic_cast<Expression*>(first);
    if (expfirst != NULL){
        //first est une expression
        Expression* expsecond = dynamic_cast<Expression*>(second);
        if (expsecond != NULL){
            // second est une expression
            return soustraction(*expfirst, *expsecond);
        }
        else {
            Complexe* complexesecond = dynamic_cast<Complexe*>(second);
            if (complexesecond != NULL) {
                // second est un complexe
                return soustraction(*expfirst, *complexesecond);
            }
            else {
                // second est un rationnel
                return soustraction(*expfirst, *((Rationnel*)second));
            }
        }
    }
    else {
        // first n'est pas une expression
        Complexe* complexefirst = dynamic_cast<Complexe*>(first);
        if (complexefirst != NULL){
            //first est un complexe
            Expression* expsecond = dynamic_cast<Expression*>(second);
            if (expsecond != NULL) {
                // second est une expression
                return soustraction(*complexefirst, *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return soustraction(*complexefirst, *complexesecond);
                }
                else{
                    return soustraction(*complexefirst, *((Rationnel*)second));
                }
           }
        }
        else{
            //first est un rationnel
            Expression* expsecond = dynamic_cast<Expression*>(second);
            if (expsecond != NULL) {
                // second est une expression
                return soustraction(*((Rationnel*)first), *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return soustraction(*((Rationnel*)first), *complexesecond);
                }
                else{
                    return soustraction(*((Rationnel*)first), *((Rationnel*)second));
                }
           }
        }
    }
}
