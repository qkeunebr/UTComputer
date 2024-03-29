/**
 * \file soustraction.cpp
 * \brief Operation soustraction
 * \author Quentin Keunebroek
 * \version 1.0
 * \date 3 juin 2016
 *
 * Opération soustraction pour tout type de Littérale.
 *
 */

#include "operationbinaire.h"

/**
 * \fn Soustraction::soustraction(Litteral& l1, Litteral& l2)
 * \brief Fonction de construction de l'objet soustraction.
 *
 * \param Deux objets de type littérale.
 * \return Opération binaire composée de deux littérales.
 */
Soustraction::Soustraction(Litteral& l1, Litteral& l2) : OperationBinaire(l1, l2){}

/**
 * \fn Litteral* Soustraction::soustraction(const Rationnel& r1, const Rationnel& r2) const
 * \brief Fonction pour effectuer l'soustraction entre deux objets rationnels.
 *
 * \param Deux objets de type Rationnel.
 * \return Littéral de type Rationnel.
 */
Litteral* Soustraction::soustraction(const Rationnel& r1, const Rationnel& r2) const{
    Litteral* result;
    if (r1.getDenominateur() == 1){
        //r1 est un entier
        if (r2.getDenominateur() == 1){
            //r2 est aussi un entier
            result =  new Rationnel(r1.getNumerateur()-r2.getNumerateur(),1);
        }
        else{
            result =  new Rationnel((r1.getNumerateur()*r2.getDenominateur())-r2.getNumerateur(), r2.getDenominateur());
        }
    }
    else
        result = new Rationnel((r1.getNumerateur()*r2.getDenominateur())-(r1.getDenominateur()*r2.getNumerateur()), r1.getDenominateur()*r2.getDenominateur());
    return result;
}

/**
 * \fn Litteral* Soustraction::soustraction(const Complexe& c1, const Complexe& c2) const
 * \brief Fonction pour effectuer l'soustraction entre deux objets complexes.
 *
 * \param Deux objets de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* Soustraction::soustraction(const Complexe& c1, const Complexe& c2) const{
    Litteral* result;
    if (!c1.getSymboleDollar()){
        //c1 est un réel (partie imaginaire nulle)
        if(!c2.getSymboleDollar()){
            //c2 est un réel (partie imaginaire nulle)
            result = new Complexe(c1.getReReel()-c2.getReReel(),0.0);
        }
        else if (c2.estReel()) {
            //c2 est aussi composé de réels
            result = new Complexe(c1.getReReel() - c2.getReReel(), c2.getImReel());

        }
        else  if (c2.estEntier())
            //c2 est composé d'entiers
        {
             result = new Complexe(c1.getReReel() - (float)c2.getReEntier(), (float)c2.getImEntier());
        }
        else{
        //c2 composé de Rationnels
            result = new Complexe(Rationnel((((int)c1.getReReel()*c2.getReRationnel().getDenominateur())-c2.getReRationnel().getNumerateur()), c2.getReRationnel().getDenominateur()),
                                  Rationnel((c2.getImRationnel().getNumerateur()), c2.getImRationnel().getDenominateur()));
        }

    }
    else if (c1.estReel()) {
            //c1 est composée de réels
            if(!c2.getSymboleDollar()){
                //c2 est un réel (partie imaginaire nulle)
                result = new Complexe(c1.getReReel() - c2.getReReel(), c1.getImReel());
            }
            else if (c2.estReel()) {
               //c2 est aussi composé de réels
               result = new Complexe(c1.getReReel() - c2.getReReel(), c1.getImReel()-c2.getImReel());

           }
           else  if (c2.estEntier())
               //c2 est composé d'entiers
           {
                result = new Complexe(c1.getReReel() - (float)c2.getReEntier(), c1.getImReel() - (float)c2.getImEntier());
           }
           else{
           //c2 composé de Rationnels
               result = new Complexe(Rationnel((((int)c1.getReReel()*c2.getReRationnel().getDenominateur())-c2.getReRationnel().getNumerateur()), c2.getReRationnel().getDenominateur()),
                                     Rationnel((((int)c1.getImReel()*c2.getImRationnel().getDenominateur())-c2.getImRationnel().getNumerateur()), c2.getImRationnel().getDenominateur()));
           }
     }
     else if (c1.estEntier()){
        //c1 est composé d'entiers
            if(!c2.getSymboleDollar()){
                //c2 est un réel (partie imaginaire nulle)
                result = new Complexe((float)c1.getReEntier() - c2.getReReel(), (float)c1.getImEntier());
            }
            else if(c2.estEntier()){
                //c2 est composé d'entiers
                result = new Complexe(c1.getReEntier() - c2.getReEntier(), c1.getImEntier() - c2.getImEntier());
            }
            else if (c2.estReel()){
                //c2 est est composé de réels
                result = new Complexe((float)c1.getReEntier() - c2.getReReel(), (float)c1.getImEntier() - c2.getImReel());
            }
            else {
                //c2 est est composé de Rationnels
                result = new Complexe(Rationnel(((c1.getReEntier()*c2.getReRationnel().getDenominateur())-c2.getReRationnel().getNumerateur()), c2.getReRationnel().getDenominateur()),
                                      Rationnel(((c1.getImEntier()*c2.getImRationnel().getDenominateur())-c2.getImRationnel().getNumerateur()), c2.getImRationnel().getDenominateur()));
            }
     }
     else{
           //c1 est est composé de Rationnels
            if(!c2.getSymboleDollar()){
                //c2 est un réel (partie imaginaire nulle)
               result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur() - (int)c2.getReReel()*c1.getReRationnel().getDenominateur(), c1.getReRationnel().getDenominateur()),
                                     Rationnel(c1.getImRationnel().getNumerateur(), c1.getImRationnel().getDenominateur()));
            }
           if (c2.estReel()) {
               result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur() - (int)c2.getReReel()*c1.getReRationnel().getDenominateur(), c1.getReRationnel().getDenominateur()),
                                     Rationnel(c1.getImRationnel().getNumerateur() - (int)c2.getImReel()*c1.getImRationnel().getDenominateur(), c1.getImRationnel().getDenominateur()));
           }
           else if (c2.estEntier()){
               result = new Complexe(Rationnel((c1.getReRationnel().getNumerateur()-(c2.getReEntier()*c1.getReRationnel().getDenominateur())), c1.getReRationnel().getDenominateur()),
                                     Rationnel((c1.getImRationnel().getNumerateur()- (c2.getImEntier()*c2.getImRationnel().getDenominateur())), c1.getImRationnel().getDenominateur()));
           }
           else {
                //c1 et c2 sont composés de Rationnels
                result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur()*c2.getReRationnel().getDenominateur()-c2.getReRationnel().getNumerateur()*c1.getReRationnel().getDenominateur(), c1.getReRationnel().getDenominateur()*c2.getReRationnel().getDenominateur()),
                                      Rationnel(c1.getImRationnel().getNumerateur()*c2.getImRationnel().getDenominateur()-c2.getImRationnel().getNumerateur()*c1.getImRationnel().getDenominateur(), c1.getImRationnel().getDenominateur()*c2.getImRationnel().getDenominateur()));
           }
      }
    return result;
}

/**
 * \fn Litteral* Soustraction::soustraction(const Complexe& c1, const Rationnel& r1) const
 * \brief Fonction pour effectuer l'soustraction entre un objet complexe et un objet rationnel.
 *
 * \param Un objet de type Complexe et un objet de type Rationnel.
 * \return Littéral de type Complexe.
 */
Litteral* Soustraction::soustraction(const Complexe& c1, const Rationnel& r1) const{
    const Complexe cTor(r1, Rationnel(0,0));
    return soustraction(c1,cTor);
}


/**
 * \fn Litteral* Soustraction::soustraction(const Rationnel& r1, const Complexe& c1) const
 * \brief Fonction pour effectuer l'soustraction entre un objet rationnel et un objet complexe.
 *
 * \param Un objet de type Rationnel et un objet de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* Soustraction::soustraction(const Rationnel& r1, const Complexe& c1) const{
    return soustraction(c1, r1);
}

/**
 * \fn Litteral* Soustraction::soustraction(const Expression& e1, const Expression& e2) const
 * \brief Fonction pour effectuer l'soustraction entre deux objets Expression.
 *
 * \param Deux objets de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Soustraction::soustraction(const Expression& e1, const Expression& e2) const {
    return new Expression(e1.getExp() + " " + e2.getExp() + " -");
}

/**
 * \fn Litteral* Soustraction::soustraction(const Expression& e1, const Rationnel& r1) const
 * \brief Fonction pour effectuer l'soustraction entre un objet Expression et un objet Rationnel.
 *
 * \param Un objet de type Expression et un objet de type Rationnel.
 * \return Littéral de type Expression.
 */
Litteral* Soustraction::soustraction(const Expression& e1, const Rationnel& r1) const{
    return new Expression(e1.getExp() + " " + r1.toString() + " -");
}

/**
 * \fn Litteral* Soustraction::soustraction(const Expression& e1, const Complexe& c1) const
 * \brief Fonction pour effectuer l'soustraction entre un objet Expression et un objet Complexe.
 *
 * \param Un objet de type Expression et un objet de type Complexe.
 * \return Littéral de type Expression.
 */
Litteral* Soustraction::soustraction(const Expression& e1, const Complexe& c1) const {
     return new Expression(e1.getExp() + " " + c1.toString() + " -");
}

/**
 * \fn Litteral* Soustraction::soustraction(const Rationnel& r1, const Expression& e1) const
 * \brief Fonction pour effectuer l'soustraction entre un objet Rationnel et un objet Expression.
 *
 * \param Un objet de type Rationnel et un objet de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Soustraction::soustraction(const Rationnel& r1, const Expression& e1) const{
    return new Expression(r1.toString() + " " + e1.getExp() + " -");
}

/**
 * \fn Litteral* Soustraction::soustraction(const Complexe& c1, const Expression& e1) const
 * \brief Fonction pour effectuer l'soustraction entre un objet Complexe et un objet Expression.
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
                Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
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
                    Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                        // second est un rationnel
                        return soustraction(*complexefirst, *((Rationnel*)second));
                }
            }
         }
        else{
            Rationnel* rationnelfirst = dynamic_cast<Rationnel*>(first);
            if (rationnelfirst != NULL){
                //first est un rationnel
                Expression* expsecond = dynamic_cast<Expression*>(second);
                if (expsecond != NULL) {
                    // second est une expression
                    return soustraction(*rationnelfirst, *expsecond);
                }
                else {
                    Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                    if (complexesecond != NULL){
                        //second est un complexe
                        return soustraction(*rationnelfirst, *complexesecond);
                    }
                    else{
                        Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                            // second est un rationnel
                           return soustraction(*rationnelfirst, *((Rationnel*)second));
                    }
               }
            }

          }
        }
     }

