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

QString Pile::getStackAff(){

    QString res("|| ");
/*    for(QVector<Litteral*>::Iterator it = stack.end() ; it != stack.begin() ; ++it){
        Litteral* temp = it;
        if(temp!=NULL)
            res.append(temp->toString());
        res.append(" || ");
    }
    */
    return res;
}

bool Controller::operateurRestant(const QString s){
    if (s=="DROP")  return true;
    if (s=="DUP")  return true;
    if (s=="SWAP")  return true;
    if (s=="LASTOP")  return true;
    if (s=="LASTARGS")  return true;
    return false;
}

bool Controller::estUnOperateurUnaire(const QString s){
    if (s=="RE")  return true;
    if (s=="IM")  return true;
    if (s=="NEG")  return true;
    if (s=="NUM")  return true;
    if (s=="DEN")  return true;
    if (s=="EDIT")  return true;
    if (s=="EVAL")  return true;
    if (s=="FORGET")  return true;
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

bool Controller::estUnComplexe(const QString s){
    if (s.contains('$')){
        QStringList part = s.split("$");
        if(part.size() == 2){
            if(estUnEntier(part.at(0)) && estUnEntier(part.at(1)))
                return true;
            if(estUnFloat(part.at(0)) && estUnFloat(part.at(1)))
                return true;
        }
    }
    return false;
}

bool Controller::estUneExpression(const QString s){
    if(s.size()>0 && s.at(0)=="'" && s.at(s.size() - 1)=="'") return true;
    return false;
}

bool Controller::estUnProgramme(const QString s){
    if(s.size()>0 && s.at(0)=="[" && s.at(s.size() - 1)=="]") return true;
    return false;
}

bool Controller::estUnAtomeProgramme(const QString s){
    if(progM.contains(s)){
        return true;
    }
    return false;
}

bool Controller::estUneVariable(const QString s){
    if(varM.contains(s)){
        return true;
    }
    return false;
}

void Controller::commande(const QString& c){
    if (estUnEntier(c)){
     pile.pushMod(Rationnel(c.toInt()));
   }
   else if(estUnFloat(c)){
       pile.pushMod(Complexe(c.toFloat(),0.0));
   }
   else if(estUnComplexe(c)){
        QStringList part = c.split("$");
        if(part.size() == 2){
            if(estUnEntier(part.first()) && estUnEntier(part.last()))
                pile.pushMod(Complexe(part.first().toInt(), part.last().toInt()));
            if(estUnFloat(part.first()) && estUnFloat(part.last()))
                pile.pushMod(Complexe(part.first().toFloat(), part.last().toFloat()));
        }
    }
   else  if (estUnOperateurBinaire(c)){
            if (pile.size()>=2) {
                Litteral* v2= pile.top();
                pile.pop();
                Litteral* v1=pile.top();
                pile.pop();
                QString op;
                if (c=="+") {
                    pile.push(*(Addition(*v1, *v2).getResult()));
                    op="Addition";
                }
                if (c=="-") {
                    pile.push(*(Soustraction(*v1, *v2).getResult()));
                    op="Soustraction";
                }
                if (c=="*") {
                    pile.push(*(Multiplication(*v1, *v2).getResult()));
                    op="Multiplication";
                }
                if (c=="/") {
                    pile.push(*(Division(*v1, *v2).getResult()));
                    op="Division";
                }
                if(c=="$") {
 //                   pile.push(*(Dollar(*v1, *v2).getResult()));
                    op="Complexe";
                }
                if(c=="IFT") {

                }
                lastop = c;

                pile.setMessage(op+v1->toString()+" and "+v2->toString());
            }else{
                pile.setMessage("Erreur : pas assez d'arguments");
            }
    }
        else if(estUnOperateurUnaire(c)){
            if (pile.size()>=1) {
                Litteral* val = pile.top();
/*                if(c=="RE") {
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
*/              if(c=="EDIT") {

                }
                if(c=="EVAL") {

                }
                if(c=="FORGET") {
                        varM.removeVariable(varM.getVariable(val->toString()));
                }
                lastop = c;
            }

            else{
                pile.setMessage("Erreur : pas assez d'arguments");
            }

    }   else if(estUneExpression(c)){
        //Traduire en commande normale puis changeCommande
    }   else if(estUnAtomeProgramme(c)){
        emit changeCommande(progM.getProgramme(c));
    }   else if(estUnProgramme(c)){
        emit changeCommande(c.left(1).right(1));
    }   else if(estUneVariable(c)){
        pile.pushMod(varM.getVariable(c).getValue());
    }   else if(operateurRestant(c)){
        if(c=="DROP") {
            pile.popMod();
        }
        if(c=="DUP") {
            pile.pushMod(*pile.top());
        }
        if(c=="SWAP") {
            Litteral* v2= pile.top();
            pile.pop();
            Litteral* v1=pile.top();
            pile.pop();
            pile.pushMod(*v2);
            pile.pushMod(*v1);
        }
        if(c=="LASTOP") {
            emit changeCommande(lastop);
        }
        if(c=="LASTARGS") {
        }
        if(c=="UNDO") {
            load();
        }
        if(c=="REDO") {

        }
        lastop = c;
    }
    else pile.setMessage("Erreur : commande inconnue");
    save();

}
