/**
 * \file addition.cpp
 * \brief Operation Multiplication
 * \author Quentin Keunebroek
 * \version 1.0
 * \date 3 juin 2016
 *
 * Opération Multiplication pour tout type de Littérale.
 *
 */

#include "operationbinaire.h"

/**
 * \fn Multiplication::Multiplication(Litteral& l1, Litteral& l2)
 * \brief Fonction de construction de l'objet Multiplication.
 *
 * \param Deux objets de type littérale.
 * \return Opération binaire composée de deux littérales.
 */
Multiplication::Multiplication(Litteral& l1, Litteral& l2) : OperationBinaire(l1,l2)
{
}

/**
 * \fn Litteral* Multiplication::multiplication(const Rationnel& r1, const Rationnel& r2) const
 * \brief Fonction pour effectuer la multiplication entre deux objets rationnels.
 *
 * \param Deux objets de type Rationnel.
 * \return Littéral de type Rationnel.
 */
Litteral* Multiplication::multiplication(const Rationnel& r1, const Rationnel& r2) const{
    Litteral* result;
    result = new Rationnel(r1.getNumerateur()*r2.getNumerateur(), r1.getDenominateur()*r2.getDenominateur());
    return result;
}

/**
 * \fn Litteral* Multiplication::multiplication(const Complexe& c1, const Complexe& c2) const
 * \brief Fonction pour effectuer la multiplication entre deux objets complexes.
 *
 * \param Deux objets de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* Multiplication::multiplication(const Complexe& c1, const Complexe& c2) const{
    Litteral* result;
    if (c1.estReel()) {
        //c1 est un réel
           if (c2.estReel()) {
               //c2 est aussi un réel
               result = new Complexe(c1.getRe() * c2.getRe(), c1.getIm() * c2.getIm());

           }
           else {
           //c2 est un Rationnel
               result = new Complexe(Rationnel(((c1.getRe()*(float)c2.getReRationnel().getNumerateur()), (float)c2.getReRationnel().getDenominateur())),
                                     Rationnel(((c1.getIm()*(float)c2.getImRationnel().getNumerateur()), (float)c2.getImRationnel().getDenominateur())));
           }
     }
     else {
        //c1 est un Rationnel
           if (c2.estReel()) {
                result = new Complexe(Rationnel(((c2.getRe()*(float)c1.getReRationnel().getNumerateur()), (float)c1.getReRationnel().getDenominateur())),
                                      Rationnel(((c2.getIm()*(float)c1.getImRationnel().getNumerateur()), (float)c1.getImRationnel().getDenominateur())));
           }
           //c1 et c2 sont Rationnel
           else {
                result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur()*c2.getReRationnel().getNumerateur(), c1.getReRationnel().getDenominateur()*c2.getReRationnel().getDenominateur()),
                                      Rationnel(c1.getImRationnel().getNumerateur()*c2.getImRationnel().getNumerateur(), c1.getImRationnel().getDenominateur()*c2.getImRationnel().getDenominateur()));
           }
      }
    return result;
}

/**
 * \fn Litteral* Multiplication::multiplication(const Complexe& c1, const Rationnel& r1) const
 * \brief Fonction pour effectuer la multiplication entre un objet complexe et un objet rationnel.
 *
 * \param Un objet de type Complexe et un objet de type Rationnel.
 * \return Littéral de type Complexe.
 */
Litteral* Multiplication::multiplication(const Complexe& c1, const Rationnel& r1) const{
    const Complexe& cTor(r1);
    return multiplication(c1,cTor);
}

/**
 * \fn Litteral* Multiplication::multiplication(const Rationnel& r1, const Complexe& c1) const
 * \brief Fonction pour effectuer la multiplication entre un objet rationnel et un objet complexe.
 *
 * \param Un objet de type Rationnel et un objet de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* Multiplication::multiplication(const Rationnel& r1, const Complexe& c1) const{
    return multiplication(c1, r1);
}

/**
 * \fn Litteral* Multiplication::multiplication(const Expression& e1, const Expression& e2) const
 * \brief Fonction pour effectuer la multiplication entre deux objets Expression.
 *
 * \param Deux objets de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Multiplication::multiplication(const Expression& e1, const Expression& e2) const {
     return new Expression(e1.getExp() + " " + e2.getExp() + " *");
}

/**
 * \fn Litteral* Multiplication::multiplication(const Expression& e1, const Rationnel& r1) const
 * \brief Fonction pour effectuer la multiplication entre un objet Expression et un objet Rationnel.
 *
 * \param Un objet de type Expression et un objet de type Rationnel.
 * \return Littéral de type Expression.
 */
Litteral* Multiplication::multiplication(const Expression& e1, const Rationnel& r1) const{
    return new Expression(e1.getExp() + " " + r1.toString() + " *");
}

/**
 * \fn Litteral* Multiplication::multiplication(const Expression& e1, const Complexe& c1) const
 * \brief Fonction pour effectuer la multiplication entre un objet Expression et un objet Complexe.
 *
 * \param Un objet de type Expression et un objet de type Complexe.
 * \return Littéral de type Expression.
 */
Litteral* Multiplication::multiplication(const Expression& e1, const Complexe& c1) const {
    return new Expression(e1.getExp() + " " + c1.toString() + " *");
}

/**
 * \fn Litteral* Multiplication::multiplication(const Rationnel& r1, const Expression& e1) const
 * \brief Fonction pour effectuer la multiplication entre un objet Rationnel et un objet Expression.
 *
 * \param Un objet de type Rationnel et un objet de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Multiplication::multiplication(const Rationnel& r1, const Expression& e1) const{
    return new Expression(r1.toString() + " " + e1.getExp() + " *");
}

/**
 * \fn Litteral* Multiplication::multiplication(const Complexe& c1, const Expression& e1) const
 * \brief Fonction pour effectuer la multiplication entre un objet Complexe et un objet Expression.
 *
 * \param Un objet de type Complexe et un objet de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Multiplication::multiplication(const Complexe& c1, const Expression& e1) const {
    return new Expression(c1.toString() + " " + e1.getExp() + " *");
}

/**
 * \fn float Multiplication::mult(const float& re1, const float& re2) const
 * \brief Fonction pour effectuer la multiplication entre deux variables réelles.
 *
 * \param Deux variables de type float.
 * \return Variable de type float.
 */
float Multiplication::mult(const float& re1, const float& re2) const{
    return re1*re2;
}

/**
 * \fn int Multiplication::mult(const int& en1, const int& en2) const
 * \brief Fonction pour effectuer la multiplication entre deux variables integer.
 *
 * \param Deux variables de type integer.
 * \return Variable de type integer.
 */
int Multiplication::mult(const int& en1, const int& en2) const{
    return en1*en2;
}

/**
 * \fn float Multiplication::add(const int& en1, const float& re1) const
 * \brief Fonction pour effectuer la multiplication entre une variable integer et une variable réelle.
 *
 * \param Une variable de type integer et une variable de type float.
 * \return Variable de type float.
 */
float Multiplication::mult(const int& en1, const float& re1) const{
    return (float)en1*re1;
}

/**
 * \fn float Multiplication::mult(const float& re1, const int& en1) const
 * \brief Fonction pour effectuer la multiplication entre une variable réelle et une variable integer.
 *
 * \param Une variable de type float et une variable de type integer.
 * \return Variable de type float.
 */
float Multiplication::mult(const float& re1, const int& en1) const{
    return mult(en1, re1);
}

/**
 * \fn Litteral* Multiplication::getResult() const
 * \brief Fonction qui appelle les différentes méthodes multiplication selon le type de Littérale considéré
 *
 *
 * \return Objet de type littéral.
 */
Litteral* Multiplication::getResult() const {
    Expression* expfirst = dynamic_cast<Expression*>(first);
    if (expfirst != NULL){
        //first est une expression
        Expression* expsecond = dynamic_cast<Expression*>(second);
        if (expsecond != NULL){
            // second est une expression
            return multiplication(*expfirst, *expsecond);
        }
        else {
            Complexe* complexesecond = dynamic_cast<Complexe*>(second);
            if (complexesecond != NULL) {
                // second est un complexe
                return multiplication(*expfirst, *complexesecond);
            }
            else {
                Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                if(rationnelsecond!=NULL){
                    // second est un rationnel
                    return multiplication(*expfirst, *((Rationnel*)second));
                }
                else{
                    float* reelsecond = (float*)(second);
                    if(reelsecond!=NULL){
                        // second est un reel
                        return multiplication(*expfirst, *((float*)second));
                    }
                    else{
                        //second est un entier
                        return multiplication(*expfirst, *((int*)second));
                    }
                }

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
                return multiplication(*complexefirst, *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return multiplication(*complexefirst, *complexesecond);
                }
                else{
                    Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                    if(rationnelsecond!=NULL){
                        // second est un rationnel
                        return multiplication(*complexefirst, *((Rationnel*)second));
                    }
                    else{
                        float* reelsecond = (float*)(second);
                        if(reelsecond!=NULL){
                            // second est un reel
                            return multiplication(*complexefirst, *((float*)second));
                        }
                        else{
                            //second est un entier
                            return multiplication(*complexefirst, *((int*)second));
                        }
                    }
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
                    return multiplication(*rationnelfirst, *expsecond);
                }
                else {
                    Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                    if (complexesecond != NULL){
                        //second est un complexe
                        return multiplication(*rationnelfirst, *complexesecond);
                    }
                    else{
                        Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                        if(rationnelsecond!=NULL){
                            // second est un rationnel
                           return multiplication(*rationnelfirst, *((Rationnel*)second));
                        }
                        else{
                            float* reelsecond = (float*)(second);
                            if(reelsecond!=NULL){
                                // second est un reel
                                return multiplication(*rationnelfirst, *((float*)second));
                            }
                            else{
                                //second est un entier
                                return multiplication(*rationnelfirst, *((int*)second));
                            }
                        }
                    }
               }
            }
            else{
                float reelfirst = first->getFloat();
                if(reelfirst!=NULL){
                    Expression* expsecond = dynamic_cast<Expression*>(second);
                    if (expsecond != NULL) {
                        // second est une expression
                        return multiplication(reelfirst, *expsecond);
                    }
                    else {
                        Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                        if (complexesecond != NULL){
                            //second est un complexe
                            return multiplication(reelfirst, *complexesecond);
                        }
                        else{
                            Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                            if(rationnelsecond!=NULL){
                                // second est un rationnel
                               return multiplication(reelfirst, *((Rationnel*)second));
                            }
                            else{
                                float reelsecond = (second->getFloat());
                                if(reelsecond!=NULL){
                                    // second est un reel
                                    Litteral* result = new Litteral(mult(reelfirst, reelsecond));
                                    return result;
                                }
                                else{
                                    //second est un entier
                                    Litteral* result = new Litteral(mult(reelfirst, reelsecond));
                                    return result;
                                }
                            }
                        }
                   }
                }
                else{
                        //first est un entier
                        Expression* expsecond = dynamic_cast<Expression*>(second);
                        if (expsecond != NULL) {
                            // second est une expression
                            return multiplication(*((int*)first), *expsecond);
                        }
                        else {
                            Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                            if (complexesecond != NULL){
                                //second est un complexe
                                return multiplication(*((int*)first), *complexesecond);
                            }
                            else{
                                Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                                if(rationnelsecond!=NULL){
                                    // second est un rationnel
                                   return multiplication(*((int*)first), *((Rationnel*)second));
                                }
                                else{
                                    float reelsecond = (second->getFloat());
                                    if(reelsecond!=NULL){
                                        // second est un reel
                                        Litteral* result= new Litteral(mult((first->getInt()), reelsecond));
                                        return result;
                                    }
                                    else{
                                        //second est un entier
                                        Litteral* result= new Litteral(mult((first->getInt()), reelsecond));
                                        return result;
                                    }
                                }
                            }
                       }

                    }
                }
            }
        }
}

