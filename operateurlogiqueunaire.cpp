#include "operationunaire.h"

OperateurLogiqueUnaire::OperateurLogiqueUnaire(Litteral &l1):OperationUnaire(l1){}

Litteral* OperateurLogiqueUnaire::NOT(const Rationnel &r1) const{
    Litteral* result;
    if(r1.getDenominateur()==1){
        result = new Rationnel(0,0);
    }
    else
        result = new Rationnel(1,1);
    return result;
}

Litteral* OperateurLogiqueUnaire::getResult() const{
Rationnel* rationnelunique = dynamic_cast<Rationnel*>(unique);
    if(rationnelunique!=NULL){
        // unique est un rationnel
        return NOT(*rationnelunique);
    }
    else{
        throw "Litteral invalide";
    }
}
