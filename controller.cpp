#include "controller.h"
#include <iostream>
#include <ostream>

void Pile::pushMod(Litteral& e){
    push(e);
    setMessage("Push "+e.toString());
}

void Pile::popMod(){
    pop();
    setMessage("Pop");

}

bool Controller::estUnOperateurUnaire(const QString s){
    if (s=="RE")  return true;
    if (s=="IM")  return true;
    if (s=="NEG")  return true;
    if (s=="NUM")  return true;
    if (s=="DEN")  return true;
       return false;
}

bool Controller::estUnOperateurBinaire(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    if (s=="$")  return true;
    if (s=="=")  return true;
    if (s=="!=")  return true;
    if (s==">=")  return true;
    if (s=="<=")  return true;
    if (s=="<")  return true;
    if (s==">")  return true;
    if (s=="AND")  return true;
    if (s=="OR")  return true;
    if (s=="NOT")  return true;
    return false;
}

bool Controller::estUnEntier(const QString s){
   bool ok;
   s.toInt(&ok);
   return ok;
}

bool Controller::estUnFloat(const QString s){
   bool ok;
   s.toFloat(&ok);
   return ok;
}

void Controller::commande(const QString& c){
    if (estUnEntier(c)){
        Rationnel rat(c.toInt());
     pile.pushMod(rat);
   }
   else if(estUnFloat(c)){
        Complexe c1(c.toFloat(),0.0);
       pile.pushMod(c1);
   }

       else  if (estUnOperateurBinaire(c)){
            if (pile.size()>=2) {
                Litteral* v2= pile.top();
                pile.popMod();
                Litteral* v1=pile.top();
                pile.popMod();
                Litteral* res;
                if (c=="+") {
                    pile.push(*(Addition(*v1, *v2).getResult()));
                }
                if (c=="-") {
                    pile.push(*(Soustraction(*v1, *v2).getResult()));
                }
                if (c=="*") {
                    pile.push(*(Multiplication(*v1, *v2).getResult()));
                }
                if (c=="/") {
                    pile.push(*(Division(*v1, *v2).getResult()));
                }
                if(c=="$") {
                    pile.push(*(Dollar(*v1, *v2).getResult()));
                }
            }else{
                pile.setMessage("Erreur : pas assez d'arguments");
            }
    }
        else if(estUnOperateurUnaire(c)){
            if (pile.size()>=1) {
                Litteral* val = pile.top();
                if(c=="RE") {
                    pile.push(*(RE(*val).getResult()));
                }
                if(c=="IM") {
                    pile.push(*(IM(*val).getResult()));
                }
                if(c=="DEN") {
                    pile.push(*(Den(*val).getResult()));
                }
                if(c=="NEG") {
                    pile.push(*(Neg(*val).getResult()));
                }
                if(c=="NUM") {
                    pile.push(*(Num(*val).getResult()));
                }
            }
            else{
                pile.setMessage("Erreur : pas assez d'arguments");
            }

        }else pile.setMessage("Erreur : commande inconnue");

}
