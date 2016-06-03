/**
 * \file divisionentiere.cpp
 * \brief Operation DivisionEntiere
 * \author Quentin Keunebroek
 * \version 1.0
 * \date 3 juin 2016
 *
 * Opération DivisionEntiere pour tout type de Littérale.
 *
 */

#include "operationbinaire.h"

/**
 * \fn DivisionEntiere::divisionentiere(Litteral& l1, Litteral& l2)
 * \brief Fonction de construction de l'objet divisionentiere.
 *
 * \param Deux objets de type littérale.
 * \return Opération binaire composée de deux littérales.
 */
DivisionEntiere::DivisionEntiere(Litteral& l1, Litteral& l2) : OperationBinaire(l1,l2)
{
}

/**
 * \fn Litteral* divisionentiere::divisionentiere(const Rationnel& r1, const Rationnel& r2) const
 * \brief Fonction pour effectuer la divisionentiere entre deux objets rationnels.
 *
 * \param Deux objets de type Rationnel.
 * \return Littéral de type Rationnel.
 */
Litteral* DivisionEntiere::divisionentiere(const Rationnel& r1, const Rationnel& r2) const{
    Litteral* result;
    result = new Rationnel(r1.getNumerateur()*r2.getDenominateur(), r1.getDenominateur() * r2.getNumerateur());
    return result;
}

/**
 * \fn Litteral* divisionentiere::divisionentiere(const Complexe& c1, const Complexe& c2) const
 * \brief Fonction pour effectuer la divisionentiere entre deux objets complexes.
 *
 * \param Deux objets de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* DivisionEntiere::divisionentiere(const Complexe& c1, const Complexe& c2) const{
    Litteral* result;
    if (c1.estReel()) {
        //c1 est un réel
           if (c2.estReel()) {
               //c2 est aussi un réel
               result = new Complexe(c1.getRe()/c2.getRe(), c1.getIm()/c2.getIm());

           }
           else {
           //c2 est un Rationnel
               result = new Complexe(Rationnel(((c1.getRe()*(float)c2.getReRationnel().getDenominateur()), (float)c2.getReRationnel().getNumerateur())),
                                     Rationnel(((c1.getIm()*(float)c2.getImRationnel().getDenominateur()), (float)c2.getImRationnel().getNumerateur())));
           }
     }
     else {
        //c1 est un Rationnel
           if (c2.estReel()) {
                result = new Complexe(Rationnel(((c2.getRe()*(float)c1.getReRationnel().getDenominateur()), (float)c1.getReRationnel().getNumerateur())),
                                      Rationnel(((c2.getIm()*(float)c1.getImRationnel().getDenominateur()), (float)c1.getImRationnel().getNumerateur())));
           }
           //c1 et c2 sont Rationnel
           else {
                result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur()*c2.getReRationnel().getDenominateur(), c1.getReRationnel().getDenominateur()*c2.getReRationnel().getNumerateur()),
                                      Rationnel(c1.getImRationnel().getNumerateur()*c2.getImRationnel().getDenominateur(), c1.getImRationnel().getDenominateur()*c2.getImRationnel().getNumerateur()));
           }
      }
    return result;
}

/**
 * \fn Litteral* divisionentiere::divisionentiere(const Complexe& c1, const Rationnel& r1) const
 * \brief Fonction pour effectuer la divisionentiere entre un objet complexe et un objet rationnel.
 *
 * \param Un objet de type Complexe et un objet de type Rationnel.
 * \return Littéral de type Complexe.
 */
Litteral* DivisionEntiere::divisionentiere(const Complexe& c1, const Rationnel& r1) const{
    const Complexe& cTor(r1);
    return divisionentiere(c1,cTor);
}

/**
 * \fn Litteral* Addition::addition(const Rationnel& r1, const Complexe& c1) const
 * \brief Fonction pour effectuer l'addition entre un objet rationnel et un objet complexe.
 *
 * \param Un objet de type Rationnel et un objet de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* DivisionEntiere::divisionentiere(const Rationnel& r1, const Complexe& c1) const{
     return divisionentiere(c1, r1);
}

/**
 * \fn Litteral* divisionentiere::divisionentiere(const Expression& e1, const Expression& e2) const
 * \brief Fonction pour effectuer la divisionentiere entre deux objets Expression.
 *
 * \param Deux objets de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* DivisionEntiere::divisionentiere(const Expression& e1, const Expression& e2) const {
    return new Expression(e1.getExp() + " " + e2.getExp() + " /");
}

/**
 * \fn Litteral* divisionentiere::divisionentiere(const Expression& e1, const Rationnel& r1) const
 * \brief Fonction pour effectuer la divisionentiere entre un objet Expression et un objet Rationnel.
 *
 * \param Un objet de type Expression et un objet de type Rationnel.
 * \return Littéral de type Expression.
 */
Litteral* DivisionEntiere::divisionentiere(const Expression& e1, const Rationnel& r1) const{
    return new Expression(e1.getExp() + " " + r1.toString() + " /");
}

/**
 * \fn Litteral* divisionentiere::divisionentiere(const Expression& e1, const Complexe& c1) const
 * \brief Fonction pour effectuer la divisionentiere entre un objet Expression et un objet Complexe.
 *
 * \param Un objet de type Expression et un objet de type Complexe.
 * \return Littéral de type Expression.
 */
Litteral* DivisionEntiere::divisionentiere(const Expression& e1, const Complexe& c1) const {
    return new Expression(e1.getExp() + " " + c1.toString() + " /");
}

/**
 * \fn Litteral* divisionentiere::divisionentiere(const Rationnel& r1, const Expression& e1) const
 * \brief Fonction pour effectuer la divisionentiere entre un objet Rationnel et un objet Expression.
 *
 * \param Un objet de type Rationnel et un objet de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* DivisionEntiere::divisionentiere(const Rationnel& r1, const Expression& e1) const{
    return new Expression(r1.toString() + " " + e1.getExp() + " /");
}

/**
 * \fn Litteral* divisionentiere::divisionentiere(const Complexe& c1, const Expression& e1) const
 * \brief Fonction pour effectuer la divisionentiere entre un objet Complexe et un objet Expression.
 *
 * \param Un objet de type Complexe et un objet de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* DivisionEntiere::divisionentiere(const Complexe& c1, const Expression& e1) const {
    return new Expression(c1.toString() + " " + e1.getExp() + " /");
}

/**
 * \fn Litteral* divisionentiere::getResult() const
 * \brief Fonction qui appelle les différentes méthodes divisionentiere selon le type de Littérale considéré
 *
 *
 * \return Objet de type littéral.
 */
Litteral* DivisionEntiere::getResult() const {
    Expression* expfirst = dynamic_cast<Expression*>(first);
    if (expfirst != NULL){
        //first est une expression
        Expression* expsecond = dynamic_cast<Expression*>(second);
        if (expsecond != NULL){
            // second est une expression
            return divisionentiere(*expfirst, *expsecond);
        }
        else {
            Complexe* complexesecond = dynamic_cast<Complexe*>(second);
            if (complexesecond != NULL) {
                // second est un complexe
                return divisionentiere(*expfirst, *complexesecond);
            }
            else {
                // second est un rationnel
                return divisionentiere(*expfirst, *((Rationnel*)second));
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
                return divisionentiere(*complexefirst, *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return divisionentiere(*complexefirst, *complexesecond);
                }
                else{
                    return divisionentiere(*complexefirst, *((Rationnel*)second));
                }
           }
        }
        else{
            //first est un rationnel
            Expression* expsecond = dynamic_cast<Expression*>(second);
            if (expsecond != NULL) {
                // second est une expression
                return divisionentiere(*((Rationnel*)first), *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return divisionentiere(*((Rationnel*)first), *complexesecond);
                }
                else{
                    return divisionentiere(*((Rationnel*)first), *((Rationnel*)second));
                }
           }
        }
    }
}
