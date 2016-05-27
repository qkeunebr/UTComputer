#include "operationbinaire.h"

Addition::Addition(Litteral& l1, Litteral& l2) : OperationBinaire(l1, l2){}

//Addition de deux rationnels
Litteral* Addition::addition(const Rationnel& r1, const Rationnel& r2) const{
    Litteral* result;
    Rationnel r(r1.getNumerateur()*r2.getDenominateur()+r2.getNumerateur()*r1.getDenominateur(), r1.getDenominateur()*r2.getDenominateur());
    result = new Rationnel(r.getNumerateur()/r.getDenominateur());
    return result;
}

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

