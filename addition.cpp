#include "addition.h"

Addition::Addition(Litteral& l1, Litteral& l2) : OperationBinaire(l1, l2){}

Litteral* addition(const Rationnel& r1, const Rationnel& r2){
    Litteral* result;
    Rationnel ra(r1.getNumerateur()*r2.getDenominateur()+r2.getNumerateur()*r1.getDenominateur(), r1.getDenominateur()*r2.getDenominateur());
    result = new Rationnel(ra.getNumerateur()/ra.getDenominateur());
    return result;
}

Litteral* addition(const Complexe& c1, const Complexe& c2){
    Litteral* result;

}
