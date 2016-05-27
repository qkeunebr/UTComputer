#include "operationbinaire.h"

Addition::Addition(Litteral& l1, Litteral& l2) : OperationBinaire(l1, l2){}

Litteral* Addition::addition(const Rationnel& r1, const Rationnel& r2) const{Litteral* retour; return retour;}
Litteral* Addition::addition(const Complexe& c1, const Complexe& c2) const{Litteral* retour; return retour;}
Litteral* Addition::addition(const Complexe& c1, const Rationnel& r1) const{Litteral* retour; return retour;}
Litteral* Addition::addition(const Rationnel& r1, const Complexe& c1) const{Litteral* retour; return retour;}
Litteral* Addition::addition(const Expression& e1, const Expression& e2) const {Litteral* retour; return retour;}
Litteral* Addition::addition(const Expression& e1, const Rationnel& r1) const{Litteral* retour; return retour;}
Litteral* Addition::addition(const Expression& e1, const Complexe& c1) const {Litteral* retour; return retour;}
Litteral* Addition::addition(const Rationnel& r1, const Expression& e1) const{Litteral* retour; return retour;}
Litteral* Addition::addition(const Complexe& c1, const Expression& e1) const {Litteral* retour; return retour;}

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
                // second est un rationnel
                return addition(*expfirst, *((Rationnel*)second));
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
                    return addition(*complexefirst, *((Rationnel*)second));
                }
           }
        }
        else{
            //first est un rationnel
            Expression* expsecond = dynamic_cast<Expression*>(second);
            if (expsecond != NULL) {
                // second est une expression
                return addition(*((Rationnel*)first), *expsecond);
            }
            else {
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if (complexesecond != NULL){
                    //second est un complexe
                    return addition(*((Rationnel*)first), *complexesecond);
                }
                else{
                    return addition(*((Rationnel*)first), *((Rationnel*)second));
                }
           }
        }
    }
}

