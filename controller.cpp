#include "controller.h"
#include <iostream>
#include <ostream>

void Pile::pushMod(Litteral& e){
    sta.push(&e);
    setMessage("Push "+e.toString());
}

void Pile::popMod(){
    sta.pop();
    setMessage("Pop");

}

bool Controller::estUnOperateurUnaire(const QString s){
       if(s=="") return true;
       return false;
}

bool Controller::estUnOperateurBinaire(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    if (s=="NEG")  return true;
    if (s=="NUM")  return true;
    if (s=="DEN")  return true;
    if (s=="$")  return true;
    if (s=="RE")  return true;
    if (s=="IM")  return true;
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
     pile.pushMod(Rationnel(c.toInt()));
   }
   else if(estUnFloat(c)){
       pile.pushMod(Complexe(c.toFloat(),0.0));
   }

       else  if (estUnOperateurBinaire(c)){
            if (pile.size()>=2) {
                Litteral* v2= pile.top();
                pile.popMod();
                Litteral* v1=pile.top();
                pile.popMod();
                Litteral* res;
                if (c=="+") {
                    pile.setMessage("before");

                    pile.push(*(Addition(*v1, *v2).getResult()));
                    pile.setMessage("after");

                }
                if (c=="-") {
                    Soustraction sous(*v1, *v2);
                    res = sous.getResult();
                }
                if (c=="*") {
                    Multiplication mult(*v1, *v2);
                    res = mult.getResult();
                }
                if (c=="/") {
                    Division div(*v1, *v2);
                    res = div.getResult();
                }
 //               pile.pushMod(*res);
            }else{
                pile.setMessage("Erreur : pas assez d'arguments");
            }
    }
        else if(estUnOperateurUnaire(c)){
            if (pile.size()>=1) {
                Litteral* val = pile.top();
            }
            else{
                pile.setMessage("Erreur : pas assez d'arguments");
            }

        }else pile.setMessage("Erreur : commande inconnue");

}
