#include "operationbinaire.h"


Division::Division(Litteral& l1, Litteral& l2) : OperationBinaire(l1,l2)
{
}

Litteral* Division::division(const Rationnel& r1, const Rationnel& r2) const{Litteral* retour; return retour;}
Litteral* Division::division(const Complexe& c1, const Complexe& c2) const{Litteral* retour; return retour;}
Litteral* Division::division(const Complexe& c1, const Rationnel& r1) const{Litteral* retour; return retour;}
Litteral* Division::division(const Rationnel& r1, const Complexe& c1) const{Litteral* retour; return retour;}
Litteral* Division::division(const Expression& e1, const Expression& e2) const {Litteral* retour; return retour;}
Litteral* Division::division(const Expression& e1, const Rationnel& r1) const{Litteral* retour; return retour;}
Litteral* Division::division(const Expression& e1, const Complexe& c1) const {Litteral* retour; return retour;}
Litteral* Division::division(const Rationnel& r1, const Expression& e1) const{Litteral* retour; return retour;}
Litteral* Division::division(const Complexe& c1, const Expression& e1) const {Litteral* retour; return retour;}

Litteral* Division::getResult() const {
    Expression* expfirst = dynamic_cast<Expression*>(first);
    if (expfirst != NULL){
        //first est une expression
        Expression* expsecond = dynamic_cast<Expression*>(second);
        if (expsecond != NULL){
            // second est une expression
            return division(*expfirst, *expsecond);
        }
        else {
            Complexe* complexesecond = dynamic_cast<Complexe*>(second);
            if (complexesecond != NULL) {
                // second est un complexe
                return division(*expfirst, *complexesecond);
            }
            else {
                // second est un rationnel
                return division(*expfirst, *((Rationnel*)second));
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
                return division(*complexefirst, *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return division(*complexefirst, *complexesecond);
                }
                else{
                    return division(*complexefirst, *((Rationnel*)second));
                }
           }
        }
        else{
            //first est un rationnel
            Expression* expsecond = dynamic_cast<Expression*>(second);
            if (expsecond != NULL) {
                // second est une expression
                return division(*((Rationnel*)first), *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return division(*((Rationnel*)first), *complexesecond);
                }
                else{
                    return division(*((Rationnel*)first), *((Rationnel*)second));
                }
           }
        }
    }
}
