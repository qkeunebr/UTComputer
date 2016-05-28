#include "operationbinaire.h"


Division::Division(Litteral& l1, Litteral& l2) : OperationBinaire(l1,l2)
{
}

Litteral* Division::division(const Rationnel& r1, const Rationnel& r2) const{
    Litteral* result;
    result = new Rationnel(r1.getNumerateur()*r2.getDenominateur(), r1.getDenominateur() * r2.getNumerateur());
    return result;
}

Litteral* Division::division(const Complexe& c1, const Complexe& c2) const{
    Litteral* result;
    if (c1.estReel()) {
        //c1 est un réel
           if (c2.estReel()) {
               //c2 est aussi un réel
               result = new Complexe(c1.getRe()/c2.getRe(), c1.getIm()/c2.getIm());

           }
           else {
           //c2 est un Rationnel
               result = new Complexe(Rationnel(((c1.getRe()*(float)c2.getReRationnel().getDenominateur()), (float)c2.getReRationnel().getNumerateur()),
                                     Rationnel(((c1.getIm()*(float)c2.getImRationnel().getDenominateur()), (float)c2.getImRationnel().getNumerateur()));
           }
     }
     else {
        //c1 est un Rationnel
           if (c2.estReel()) {
                result = new Complexe(Rationnel(((c2.getRe()*(float)c1.getReRationnel().getDenominateur()), (float)c1.getReRationnel().getNumerateur()),
                                      Rationnel(((c2.getIm()*(float)c1.getImRationnel().getDenominateur()), (float)c1.getImRationnel().getNumerateur()));
           }
           //c1 et c2 sont Rationnel
           else {
                result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur()*c2.getReRationnel().getDenominateur(), c1.getReRationnel().getDenominateur()*c2.getReRationnel().getNumerateur()),
                                      Rationnel(c1.getImRationnel().getNumerateur()*c2.getImRationnel().getDenominateur(), c1.getImRationnel().getDenominateur()*c2.getImRationnel().getNumerateur()));
           }
      }
    return result;
}
Litteral* Division::division(const Complexe& c1, const Rationnel& r1) const{
    const Complexe& cTor(r1);
    return division(c1,cTor);
}

Litteral* Division::division(const Rationnel& r1, const Complexe& c1) const{
     return division(c1, r1);
}

Litteral* Division::division(const Expression& e1, const Expression& e2) const {
    return new Expression(e1.getExp() + " " + e2.getExp() + " /");
}

Litteral* Division::division(const Expression& e1, const Rationnel& r1) const{
    return new Expression(e1.getExp() + " " + r1.toString() + " /");
}

Litteral* Division::division(const Expression& e1, const Complexe& c1) const {
    return new Expression(e1.getExp() + " " + c1.toString() + " /");
}

Litteral* Division::division(const Rationnel& r1, const Expression& e1) const{
    return new Expression(r1.toString() + " " + e1.getExp() + " /");
}

Litteral* Division::division(const Complexe& c1, const Expression& e1) const {
    return new Expression(c1.toString() + " " + e1.getExp() + " /");
}


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
