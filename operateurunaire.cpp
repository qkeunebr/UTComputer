#include "operationunaire.h"

Neg::Neg(Litteral& l):OperationUnaire(l){}

Litteral* Neg::getResult() const {
    Rationnel* r = dynamic_cast<Rationnel*>(unique);
    if (r != 0) {
        // unique est un rationnel
        return neg(*r);
    }
    else {
        Complexe* c = dynamic_cast<Complexe*>(unique);
        if (c != 0) {
            // unique est un complexe
            return neg(*c);
        }
    }
    else{
        //expression
        throw TypeConstanteException("Opération impossible : DEG sur complexe ou rationnel");
    }
}

Litteral* Neg::neg(const Complexe &c) const{
    if(c.estReel()){
        return Complexe(-c.getRe(),-c.getIm());
    }
    else return Complexe(-c.getReRationnel(), -c.getImRationnel());
}

Litteral* Neg::neg(const Rationnel &r) const{
    return Rationnel(-r.getNumerateur(), -r.getDenominateur());
}




Num::Num(Litteral& l):OperationUnaire(l){}

Litteral* Num::getResult() const {
    Rationnel* r = dynamic_cast<Rationnel*>(unique);
    if (r != 0) {
        // unique est un rationnel
        return num(*r);
    }
    else {
        Complexe* c = dynamic_cast<Complexe*>(unique);
        if (c != 0) {
            // unique est un complexe
            throw TypeConstanteException("Opération impossible : NUM sur complexe");
        }
    }
    else{
        //Entier ou expression
        return unique;
    }
}

Litteral* Num::num(const Rationnel &r) const {
    return r.getNumerateur();
}

Den::Den(Litteral& l):OperationUnaire(l)
{
}


Litteral* Den::getResult() const {
    Rationnel* r = dynamic_cast<Rationnel*>(unique);
    if (r != 0) {
        // unique est un rationnel
        return den(*r);
    }
    else {
        Complexe* c = dynamic_cast<Complexe*>(unique);
        if (c != 0) {
            // unique est un complexe
            throw TypeConstanteException("Opération impossible : NUM sur complexe");
        }
    }
    else{
        //Entier ou expression
        return unique;
    }
}

Litteral* Den::den(const Rationnel &r) const {
    return r.getDenominateur();
}

Dollar::Dollar(Litteral& l):OperationUnaire(l)
{
}

Litteral* Dollar::getResult() const {
    Complexe* complexe = dynamic_cast<Complexe*>(unique);
    if (complexe != 0) {
        // c est un complexe
        return dollar(*complexe);
    }
    else {
        throw TypeConstanteException("Opération impossible : dollar applicable aux Complexes seulement");
        }
}

Litteral* dollar(const Complexe& c) const{
     return c;
}

RE::RE(Litteral& l):OperationUnaire(l)
{
}

Litteral* RE::getResult() const {
    Complexe* complexe = dynamic_cast<Complexe*>(unique);
    if (complexe != 0) {
        // c est un complexe
        return re(*complexe);
    }
    else {
        throw TypeConstanteException("Opération impossible : RE applicable à un Complexe");
        }
}

Litteral* RE::re(const Complexe &c) const{
    if(c.estReel()){
          return c.getRe();
    }
    else return c.getReRationnel();
}

IM::IM(Litteral& l):OperationUnaire(l)
{
}

Litteral* IM::getResult() const {
    Complexe* complexe = dynamic_cast<Complexe*>(unique);
    if (complexe != 0) {
        // c est un complexe
        return im(*complexe);
    }
    else {
        throw TypeConstanteException("Opération impossible : IM applicable à un Complexe");
        }
}

Litteral* IM::im(const Complexe &c) const{
    if(c.estReel()){
          return c.getIm();
    }
    else return c.getImRationnel();
}








