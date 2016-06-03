/**
 * \file addition.cpp
 * \brief Operation Addition
 * \author Quentin Keunebroek
 * \version 1.0
 * \date 3 juin 2016
 *
 * Opération Addition pour tout type de Littérale.
 *
 */

#include "operationbinaire.h"

/**
 * \fn Addition::Addition(Litteral& l1, Litteral& l2)
 * \brief Fonction de construction de l'objet Addition.
 *
 * \param Deux objets de type littérale.
 * \return Opération binaire composée de deux littérales.
 */
Addition::Addition(Litteral& l1, Litteral& l2) : OperationBinaire(l1, l2){}

/**
 * \fn Litteral* Addition::addition(const Rationnel& r1, const Rationnel& r2) const
 * \brief Fonction pour effectuer l'addition entre deux objets rationnels.
 *
 * \param Deux objets de type Rationnel.
 * \return Littéral de type Rationnel.
 */
Litteral* Addition::addition(const Rationnel& r1, const Rationnel& r2) const{
    Litteral* result;
    Rationnel r(r1.getNumerateur()*r2.getDenominateur()+r2.getNumerateur()*r1.getDenominateur(), r1.getDenominateur()*r2.getDenominateur());
    result = new Rationnel(r.getNumerateur()/r.getDenominateur());
    return result;
}

/**
 * \fn Litteral* Addition::addition(const Complexe& c1, const Complexe& c2) const
 * \brief Fonction pour effectuer l'addition entre deux objets complexes.
 *
 * \param Deux objets de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* Addition::addition(const Complexe& c1, const Complexe& c2) const{
    Litteral* result;
    if (c1.estReel()) {
        //c1 est un réel
           if (c2.estReel()) {
               //c2 est aussi un réel
               result = new Complexe(c1.getRe() + c2.getRe(), c1.getIm() + c2.getIm());

           }
           else {
           //c2 est un Rationnel
               result = new Complexe(Rationnel(((c1.getRe()*(float)c2.getReRationnel().getDenominateur())+(float)c2.getReRationnel().getNumerateur()), (float)c2.getReRationnel().getDenominateur()),
                                     Rationnel(((c1.getIm()*(float)c2.getImRationnel().getDenominateur())+(float)c2.getImRationnel().getNumerateur()), (float)c2.getImRationnel().getDenominateur()));
           }
     }
     else {
        //c1 est un Rationnel
           if (c2.estReel()) {
                result = new Complexe(Rationnel(((c2.getRe()*(float)c1.getReRationnel().getDenominateur())+(float)c1.getReRationnel().getNumerateur()), (float)c1.getReRationnel().getDenominateur()),
                                      Rationnel(((c2.getIm()*(float)c1.getImRationnel().getDenominateur())+(float)c1.getImRationnel().getNumerateur()), (float)c1.getImRationnel().getDenominateur()));
           }
           //c1 et c2 sont Rationnel
           else {
                result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur()*c2.getReRationnel().getDenominateur()+c2.getReRationnel().getNumerateur()*c1.getReRationnel().getDenominateur(), c1.getReRationnel().getDenominateur()*c2.getReRationnel().getDenominateur()),
                                      Rationnel(c1.getImRationnel().getNumerateur()*c2.getImRationnel().getDenominateur()+c2.getImRationnel().getNumerateur()*c1.getImRationnel().getDenominateur(), c1.getImRationnel().getDenominateur()*c2.getImRationnel().getDenominateur()));
           }
      }
    return result;
}

/**
 * \fn Litteral* Addition::addition(const Complexe& c1, const Rationnel& r1) const
 * \brief Fonction pour effectuer l'addition entre un objet complexe et un objet rationnel.
 *
 * \param Un objet de type Complexe et un objet de type Rationnel.
 * \return Littéral de type Complexe.
 */
Litteral* Addition::addition(const Complexe& c1, const Rationnel& r1) const{
    const Complexe& cTor(r1);
    return addition(c1,cTor);
}

/**
 * \fn float Addition::add(const float& re1, const float& re2) const
 * \brief Fonction pour effectuer l'addition entre deux variables réelles.
 *
 * \param Deux variables de type float.
 * \return Variable de type float.
 */
float Addition::add(const float& re1, const float& re2) const{
    return re1+re2;
}

/**
 * \fn int Addition::add(const int& en1, const int& en2) const
 * \brief Fonction pour effectuer l'addition entre deux variables integer.
 *
 * \param Deux variables de type integer.
 * \return Variable de type integer.
 */
int Addition::add(const int& en1, const int& en2) const{
    return en1+en2;
}

/**
 * \fn float Addition::add(const int& en1, const float& re1) const
 * \brief Fonction pour effectuer l'addition entre une variable integer et une variable réelle.
 *
 * \param Une variable de type integer et une variable de type float.
 * \return Variable de type float.
 */
float Addition::add(const int& en1, const float& re1) const{
    return (float)en1+re1;
}

/**
 * \fn float Addition::add(const float& re1, const int& en1) const
 * \brief Fonction pour effectuer l'addition entre une variable réelle et une variable integer.
 *
 * \param Une variable de type float et une variable de type integer.
 * \return Variable de type float.
 */
float Addition::add(const float& re1, const int& en1) const{
    return add(en1, re1);
}

/**
 * \fn Litteral* Addition::addition(const Expression& e1, const float& re1) const
 * \brief Fonction pour effectuer l'addition entre une littérale Expression et une variable réelle.
 *
 * \param Un objet de type Expression et une variable de type float.
 * \return Littérale de type Expression.
 */
Litteral* Addition::addition(const Expression& e1, const float& re1) const{
    return new Expression(e1.getExp() + " " + QString::number(re1) + " +");
}

/**
 * \fn Litteral* Addition::addition(const Expression& e1, const int& en1) const
 * \brief Fonction pour effectuer l'addition entre une littérale Expression et une variable integer.
 *
 * \param Un objet de type Expression et une variable de type integer.
 * \return Littérale de type Expression.
 */
Litteral* Addition::addition(const Expression& e1, const int& en1) const{
    return new Expression(e1.getExp() + " " + QString::number(en1) + " +");
}

/**
 * \fn Litteral* Addition::addition(const Complexe& c1, const int& en1) const
 * \brief Fonction pour effectuer l'addition entre une littérale Complexe et une variable integer.
 *
 * \param Un objet de type Complexe et une variable de type integer.
 * \return Littérale de type Complexe.
 */
Litteral* Addition::addition(const Complexe& c1, const int& en1) const{
    Litteral* result = new Complexe(c1.getRe()+en1, c1.getIm());
    return result;
}

/**
 * \fn Litteral* Addition::addition(const int& en1, const Complexe& c1) const
 * \brief Fonction pour effectuer l'addition entre une variable integer et une littérale Complexe.
 *
 * \param Une variable de type integer et un objet de type Complexe.
 * \return Littérale de type Complexe.
 */
Litteral* Addition::addition(const int& en1, const Complexe& c1) const{
   return addition(c1, en1);
}

/**
 * \fn Litteral* Addition::addition(const Complexe& c1, const float& re1) const
 * \brief Fonction pour effectuer l'addition entre une littérale Complexe et une variable réelle.
 *
 * \param Un objet de type Complexe et une variable de type float.
 * \return Littérale de type Complexe.
 */
Litteral* Addition::addition(const Complexe& c1, const float& re1) const{
    Litteral* result = new Complexe(c1.getRe()+re1, c1.getIm());
    return result;
}

/**
 * \fn Litteral* Addition::addition(const float& re1, const Complexe& c1) const
 * \brief Fonction pour effectuer l'addition entre une variable réelle et une littérale Complexe.
 *
 * \param Une variable de type float et un objet de type Complexe.
 * \return Littérale de type Complexe.
 */
Litteral* Addition::addition(const float& re1, const Complexe& c1) const{
   return addition(c1, re1);
}

/**
 * \fn Litteral* Addition::addition(const Rationnel& r1, const float& re1) const
 * \brief Fonction pour effectuer l'addition entre une littérale Rationnel et une variable réelle.
 *
 * \param Un objet de type Rationnel et une variable de type float.
 * \return Littérale de type Rationnel.
 */
Litteral* Addition::addition(const Rationnel& r1, const float& re1) const{
    Litteral* result= new Rationnel (r1.getNumerateur()+(re1*r1.getDenominateur()), r1.getDenominateur());
    return result;
}

/**
 * \fn Litteral* Addition::addition(const float& re1, const Rationnel& r1) const
 * \brief Fonction pour effectuer l'addition entre une variable réelle et une littérale Rationnel.
 *
 * \param Une variable de type float et un objet de type Rationnel.
 * \return Littérale de type Rationnel.
 */
Litteral* Addition::addition(const float& re1, const Rationnel& r1) const{
    return addition(r1, re1);
}

/**
 * \fn Litteral* Addition::addition(const Rationnel& r1, const int& en1) const
 * \brief Fonction pour effectuer l'addition entre une littérale Rationnel et une variable integer.
 *
 * \param Un objet de type Rationnel et une variable de type integer.
 * \return Littérale de type Rationnel.
 */
Litteral* Addition::addition(const Rationnel& r1, const int& en1) const{
    Litteral* result= new Rationnel (r1.getNumerateur()+(en1*r1.getDenominateur()), r1.getDenominateur());
    return result;
}

/**
 * \fn Litteral* Addition::addition(const int& en1, const Rationnel& r1) const
 * \brief Fonction pour effectuer l'addition entre une variable integer et une littérale Rationnel.
 *
 * \param Une variable de type integer et un objet de type Rationnel.
 * \return Littérale de type Rationnel.
 */
Litteral* Addition::addition(const int& en1, const Rationnel& r1) const{
    return addition(r1, en1);
}


/**
 * \fn Litteral* Addition::addition(const Rationnel& r1, const Complexe& c1) const
 * \brief Fonction pour effectuer l'addition entre un objet rationnel et un objet complexe.
 *
 * \param Un objet de type Rationnel et un objet de type Complexe.
 * \return Littéral de type Complexe.
 */
Litteral* Addition::addition(const Rationnel& r1, const Complexe& c1) const{
    return addition(c1, r1);
}

/**
 * \fn Litteral* Addition::addition(const Expression& e1, const Expression& e2) const
 * \brief Fonction pour effectuer l'addition entre deux objets Expression.
 *
 * \param Deux objets de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Addition::addition(const Expression& e1, const Expression& e2) const {
    return new Expression(e1.getExp() + " " + e2.getExp() + " +");
}

/**
 * \fn Litteral* Addition::addition(const Expression& e1, const Rationnel& r1) const
 * \brief Fonction pour effectuer l'addition entre un objet Expression et un objet Rationnel.
 *
 * \param Un objet de type Expression et un objet de type Rationnel.
 * \return Littéral de type Expression.
 */
Litteral* Addition::addition(const Expression& e1, const Rationnel& r1) const{
    return new Expression(e1.getExp() + " " + r1.toString() + " +");
}

/**
 * \fn Litteral* Addition::addition(const Expression& e1, const Complexe& c1) const
 * \brief Fonction pour effectuer l'addition entre un objet Expression et un objet Complexe.
 *
 * \param Un objet de type Expression et un objet de type Complexe.
 * \return Littéral de type Expression.
 */
Litteral* Addition::addition(const Expression& e1, const Complexe& c1) const {
     return new Expression(e1.getExp() + " " + c1.toString() + " +");
}

/**
 * \fn Litteral* Addition::addition(const Rationnel& r1, const Expression& e1) const
 * \brief Fonction pour effectuer l'addition entre un objet Rationnel et un objet Expression.
 *
 * \param Un objet de type Rationnel et un objet de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Addition::addition(const Rationnel& r1, const Expression& e1) const{
    return new Expression(r1.toString() + " " + e1.getExp() + " +");
}

/**
 * \fn Litteral* Addition::addition(const Complexe& c1, const Expression& e1) const
 * \brief Fonction pour effectuer l'addition entre un objet Complexe et un objet Expression.
 *
 * \param Un objet de type Complexe et un objet de type Expression.
 * \return Littéral de type Expression.
 */
Litteral* Addition::addition(const Complexe& c1, const Expression& e1) const {
     return new Expression(c1.toString() + " " + e1.getExp() + " +");
}


/**
 * \fn Litteral* Addition::getResult() const
 * \brief Fonction qui appelle les différentes méthodes addition selon le type de Littérale considéré
 *
 *
 * \return Objet de type littéral.
 */
Litteral* Addition::getResult() const {
    Expression* expfirst = dynamic_cast<Expression*>(first);
    if (expfirst != NULL){
        //first est une expression
        Expression* expsecond = dynamic_cast<Expression*>(second);
        if (expsecond != NULL){
            // second est une expression
            return addition(*expfirst, *expsecond);
        }
        else {
            Complexe* complexesecond = dynamic_cast<Complexe*>(second);
            if (complexesecond != NULL) {
                // second est un complexe
                return addition(*expfirst, *complexesecond);
            }
            else {
                Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                if(rationnelsecond!=NULL){
                    // second est un rationnel
                    return addition(*expfirst, *((Rationnel*)second));
                }
                else{
                    float* reelsecond = (float*)(second);
                    if(reelsecond!=NULL){
                        // second est un reel
                        return addition(*expfirst, *((float*)second));
                    }
                    else{
                        //second est un entier
                        return addition(*expfirst, *((int*)second));
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
                return addition(*complexefirst, *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return addition(*complexefirst, *complexesecond);
                }
                else{
                    Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                    if(rationnelsecond!=NULL){
                        // second est un rationnel
                        return addition(*complexefirst, *((Rationnel*)second));
                    }
                    else{
                        float* reelsecond = (float*)(second);
                        if(reelsecond!=NULL){
                            // second est un reel
                            return addition(*complexefirst, *((float*)second));
                        }
                        else{
                            //second est un entier
                            return addition(*complexefirst, *((int*)second));
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
                    return addition(*rationnelfirst, *expsecond);
                }
                else {
                    Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                    if (complexesecond != NULL){
                        //second est un complexe
                        return addition(*rationnelfirst, *complexesecond);
                    }
                    else{
                        Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                        if(rationnelsecond!=NULL){
                            // second est un rationnel
                           return addition(*rationnelfirst, *((Rationnel*)second));
                        }
                        else{
                            float* reelsecond = (float*)(second);
                            if(reelsecond!=NULL){
                                // second est un reel
                                return addition(*rationnelfirst, *((float*)second));
                            }
                            else{
                                //second est un entier
                                return addition(*rationnelfirst, *((int*)second));
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
                        return addition(reelfirst, *expsecond);
                    }
                    else {
                        Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                        if (complexesecond != NULL){
                            //second est un complexe
                            return addition(reelfirst, *complexesecond);
                        }
                        else{
                            Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                            if(rationnelsecond!=NULL){
                                // second est un rationnel
                               return addition(reelfirst, *((Rationnel*)second));
                            }
                            else{
                                float reelsecond = (second->getFloat());
                                if(reelsecond!=NULL){
                                    // second est un reel
                                    Litteral* result = new Litteral(add(reelfirst, reelsecond));
                                    return result;
                                }
                                else{
                                    //second est un entier
                                    Litteral* result = new Litteral(add(reelfirst, reelsecond));
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
                            return addition(*((int*)first), *expsecond);
                        }
                        else {
                            Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                            if (complexesecond != NULL){
                                //second est un complexe
                                return addition(*((int*)first), *complexesecond);
                            }
                            else{
                                Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                                if(rationnelsecond!=NULL){
                                    // second est un rationnel
                                   return addition(*((int*)first), *((Rationnel*)second));
                                }
                                else{
                                    float reelsecond = (second->getFloat());
                                    if(reelsecond!=NULL){
                                        // second est un reel
                                        Litteral* result= new Litteral(add((first->getInt()), reelsecond));
                                        return result;
                                    }
                                    else{
                                        //second est un entier
                                        Litteral* result= new Litteral(add((first->getInt()), reelsecond));
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

