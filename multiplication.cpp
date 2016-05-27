#include "operationbinaire.h"

Multiplication::Multiplication(Litteral& l1, Litteral& l2) : OperationBinaire(l1,l2)
{
}

Litteral* Multiplication::multiplication(const Rationnel& r1, const Rationnel& r2) const{Litteral* retour; return retour;}
Litteral* Multiplication::multiplication(const Complexe& c1, const Complexe& c2) const{Litteral* retour; return retour;}
Litteral* Multiplication::multiplication(const Complexe& c1, const Rationnel& r1) const{Litteral* retour; return retour;}
Litteral* Multiplication::multiplication(const Rationnel& r1, const Complexe& c1) const{Litteral* retour; return retour;}
Litteral* Multiplication::multiplication(const Expression& e1, const Expression& e2) const {Litteral* retour; return retour;}
Litteral* Multiplication::multiplication(const Expression& e1, const Rationnel& r1) const{Litteral* retour; return retour;}
Litteral* Multiplication::multiplication(const Expression& e1, const Complexe& c1) const {Litteral* retour; return retour;}
Litteral* Multiplication::multiplication(const Rationnel& r1, const Expression& e1) const{Litteral* retour; return retour;}
Litteral* Multiplication::multiplication(const Complexe& c1, const Expression& e1) const {Litteral* retour; return retour;}


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
                // second est un rationnel
                return multiplication(*expfirst, *((Rationnel*)second));
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
                    return multiplication(*complexefirst, *((Rationnel*)second));
                }
           }
        }
        else{
            //first est un rationnel
            Expression* expsecond = dynamic_cast<Expression*>(second);
            if (expsecond != NULL) {
                // second est une expression
                return multiplication(*((Rationnel*)first), *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return multiplication(*((Rationnel*)first), *complexesecond);
                }
                else{
                    return multiplication(*((Rationnel*)first), *((Rationnel*)second));
                }
           }
        }
    }
}

