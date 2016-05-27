#include "operationbinaire.h"

Soustraction::Soustraction(Litteral& l1, Litteral& l2) : OperationBinaire(l1, l1)
{
}

Litteral* Soustraction::soustraction(const Rationnel& r1, const Rationnel& r2) const{Litteral* retour; return retour;}
Litteral* Soustraction::soustraction(const Complexe& c1, const Complexe& c2) const{Litteral* retour; return retour;}
Litteral* Soustraction::soustraction(const Complexe& c1, const Rationnel& r1) const{Litteral* retour; return retour;}
Litteral* Soustraction::soustraction(const Rationnel& r1, const Complexe& c1) const{Litteral* retour; return retour;}
Litteral* Soustraction::soustraction(const Expression& e1, const Expression& e2) const {Litteral* retour; return retour;}
Litteral* Soustraction::soustraction(const Expression& e1, const Rationnel& r1) const{Litteral* retour; return retour;}
Litteral* Soustraction::soustraction(const Expression& e1, const Complexe& c1) const {Litteral* retour; return retour;}
Litteral* Soustraction::soustraction(const Rationnel& r1, const Expression& e1) const{Litteral* retour; return retour;}
Litteral* Soustraction::soustraction(const Complexe& c1, const Expression& e1) const {Litteral* retour; return retour;}


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
