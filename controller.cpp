#include "controller.h"
#include <iostream>
#include <ostream>
#include <QChar>
#include <QTextStream>

/**
 * \fn  void Pile::pushMod(Litteral& e)
 * \brief  Rajoute un \class Litteral litteral.h dans le pile et change l'affichage.
 *
 * \param  e Litteral a ajouté.
 */
void Pile::pushMod(Litteral& e){
    push(e);
    setMessage("Push "+e.toString());
}

/**
 * \fn  void Pile::popMod(Litteral& e)
 * \brief  Enlève un \class Litteral litteral.h de la pile et change l'affichage.
 *
 */
void Pile::popMod(){
    pop();
    setMessage("Pop");

}

/**
 * \fn  QString Pile::getStackAff()
 * \brief  Stock le contenu de la pile dans un QString
 *
 * \return  Contenu de la pile
 */
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

/**
 * \fn  bool Controller::operateurRestant(const QString s)
 * \brief  Teste les operateurs qui ne prennent pas d'arguments
 *
 * \param  s L'entrée à comparer au commandes
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::operateurRestant(const QString s){
    if (s=="DROP")  return true;
    if (s=="DUP")  return true;
    if (s=="SWAP")  return true;
    if (s=="LASTOP")  return true;
    if (s=="LASTARGS")  return true;
 //   if (s=="UNDO")  return true;
//    if (s=="REDO")  return true;
    return false;
}

/**
 * \fn  bool Controller::estUnOperateurLogique(const QString s)
 * \brief  Teste les operateurs logiques qui prennent deux arguments
 *
 * \param  s L'entrée à comparer aux commandes
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::estUnOperateurLogique(const QString s){
    if (s=="==")  return true;
    if (s=="!=")  return true;
    if (s==">=")  return true;
    if (s=="<=")  return true;
    if (s=="<")  return true;
    if (s==">")  return true;
    if (s=="AND")  return true;
    if (s=="OR")  return true;
    return false;
}


/**
 * \fn  bool Controller::estUnOperateurUnaire(const QString s)
 * \brief  Teste les operateurs qui prennent un argument
 *
 * \param  s L'entrée à comparer aux commandes
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::estUnOperateurUnaire(const QString s){
    if (s=="RE")  return true;
    if (s=="IM")  return true;
    if (s=="NEG")  return true;
    if (s=="NUM")  return true;
    if (s=="DEN")  return true;
    if (s=="EDIT")  return true;
    if (s=="EVAL")  return true;
    if (s=="FORGET")  return true;
    if (s=="NOT")  return true;
    return false;
}

/**
 * \fn  bool Controller::estUnOperateurBinaire(const QString s)
 * \brief  Teste les operateurs qui prennent deux arguments
 *
 * \param  s L'entrée à comparer aux commandes
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::estUnOperateurBinaire(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    if (s=="$")  return true;
    if (s=="==")  return true;
    if (s=="!=")  return true;
    if (s==">=")  return true;
    if (s=="<=")  return true;
    if (s=="<")  return true;
    if (s==">")  return true;
    if (s=="AND")  return true;
    if (s=="OR")  return true;
    if (s=="STO")  return true;
    if (s=="IFT")  return true;
    return false;
}

/**
 * \fn  bool Controller::estUnEntier(const QString s)
 * \brief  Teste si l'entrée est un entier
 *
 * \param  s L'entrée à déterminer
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::estUnEntier(const QString s){
   bool ok;
   s.toInt(&ok);
   return ok;
}

/**
 * \fn  bool Controller::estUnFloat(const QString s)
 * \brief  Teste si l'entrée est un float
 *
 * \param  s L'entrée à déterminer
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::estUnFloat(const QString s){
   bool ok;
   s.toFloat(&ok);
   return ok;
}

/**
 * \fn  bool Controller::estUnComplexe(const QString s)
 * \brief  Teste si l'entrée est un complexe
 *
 * \param  s L'entrée à déterminer
 * \return  booléen si c'est une entrée de ce type
 */
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

/**
 * \fn  bool Controller::estUneExpression(const QString s)
 * \brief  Teste si l'entrée est une expression
 *
 * \param  s L'entrée à déterminer
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::estUneExpression(const QString s){
    bool result = false;
    if(s.size()>0 && s.at(0)==QChar('\"') && s.at(s.size() - 1)==QChar('\"'))
        result = true;
    return result;
}

/**
 * \fn  bool Controller::estUnProgramme(const QString s)
 * \brief  Teste si l'entrée est un programme
 *
 * \param  s L'entrée à déterminer
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::estUnProgramme(const QString s){
    if(s.size()>0 && s.at(0)==QChar('[') && s.at(s.size() - 1)==QChar(']')) return true;
    return false;
}

/**
 * \fn  bool Controller::estUnAtomeProgramme(const QString s)
 * \brief  Teste si l'entrée est un atome de programme
 *
 * \param  s L'entrée à déterminer
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::estUnAtomeProgramme(const QString s){
    if(progM.contains(s)){
        return true;
    }
    return false;
}

/**
 * \fn  bool Controller::estUneVariable(const QString s)
 * \brief  Teste si l'entrée est une variable
 *
 * \param  s L'entrée à déterminer
 * \return  booléen si c'est une entrée de ce type
 */
bool Controller::estUneVariable(const QString s){
    if(varM.contains(s)){
        return true;
    }
    return false;
}

/**
 * \fn  void Controller::commande(const QString& c)
 * \brief  Détermine l'action suivant l'entrée et appelle les bonnes méthodes
 *
 * \param  c la ligne de commnde à exécuter
 */
void Controller::commande(const QString& c){/*
    if(c=="UNDO" || c=="REDO"){
        load();
    }
    else{
    save();*/
    if (estUnEntier(c)){
     Litteral * r1 = new Rationnel(c.toInt());
     pile.pushMod(*r1);
   }
   else if(estUnFloat(c)){
        Litteral* c1 = new Complexe(c.toFloat(),0.0);
       pile.pushMod(*c1);
   }
   else if(estUnComplexe(c)){
        QStringList part = c.split("$");
        Litteral* c2 = new Complexe(part.first().toInt(), part.last().toInt());
        Litteral* c3 = new Complexe(part.first().toFloat(), part.last().toFloat());
        if(part.size() == 2){
            if(estUnEntier(part.first()) && estUnEntier(part.last()))
                pile.pushMod(*c2);
            if(estUnFloat(part.first()) && estUnFloat(part.last()))
                pile.pushMod(*c3);
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
                    pile.pushMod(*(Addition(*v1, *v2).getResult()));
                    op="Addition";
                }
                if (c=="-") {
                    pile.pushMod(*(Soustraction(*v1, *v2).getResult()));
                    op="Soustraction";
                }
                if (c=="*") {
                    pile.pushMod(*(Multiplication(*v1, *v2).getResult()));
                    op="Multiplication";
                }
                if (c=="/") {
                    pile.pushMod(*(Division(*v1, *v2).getResult()));
                    op="Division";
                }
                if(c=="$") {
                    pile.pushMod(*(Dollar(*v1, *v2).getResult()));
                    op="Complexe";
                }
                if(c=="STO"){
                    if(estUnProgramme(v1->toString()))
                        progM.addProgramme(v2->toString(), v1->toString());
                    else
                        varM.addVariable(v2->toString(), *v1);
                }


                if(estUnOperateurLogique(c)){

                    pile.pushMod(*(OperateurLogique(*v1, *v2, c).getResult()));
                }
                if(c=="IFT") {

                }
                if(!lastargs.empty())
                    lastargs.clear();
                lastargs.append(v2);
                lastargs.append(v1);
                lastop = c;

                //pile.setMessage(op+v1->toString()+" and "+v2->toString());
            }else{
                pile.setMessage("Erreur : pas assez d'arguments");
            }
    }
        else if(estUnOperateurUnaire(c)){
            if (pile.size()>=1) {
                Litteral* val = pile.top();
               if(c=="RE") {
                    pile.pushMod(*(RE(*val).getResult()));
                }
                if(c=="IM") {
                    pile.pushMod(*(IM(*val).getResult()));
                }
                if(c=="DEN") {
                    pile.pushMod(*(Den(*val).getResult()));
                }
                if(c=="NEG") {
                    pile.pushMod(*(Neg(*val).getResult()));
                }
                if(c=="NUM") {
                    pile.pushMod(*(Num(*val).getResult()));
                }
              if(c=="EDIT") {
                    if(estUneVariable(val->toString())){
                        changeTab("Variable");
                    }
                    if(estUnAtomeProgramme(val->toString())){
                        changeTab("Programme");
                    }
                }
                if(c=="EVAL") {
                    pile.pushMod(*(Eval(*val).getResult()));
                }
                if (c=="NOT"){
                    pile.pushMod(*(OperateurLogiqueUnaire(*val, c).getResult()));
                }
                if(c=="FORGET") {
                    if(estUnProgramme(val->toString()))
                        progM.removeProgramme(progM.getProgramme(val->toString()));
                    else if(estUneVariable(val->toString()))
                        varM.removeVariable(varM.getVariable(val->toString()));
                }
                lastop = c;
                lastargs.append(val);
            }

            else{
                pile.setMessage("Erreur : pas assez d'arguments");
            }

    }   else if(estUneExpression(c)){
        Expression* exp = new Expression(c.mid(1,c.size()-2));
        pile.pushMod(*exp);
    }   else if(estUnAtomeProgramme(c)){
        changeCommande(progM.getProgramme(c).getName());
    }   else if(estUnProgramme(c)){
        Expression* exp = new Expression(c.mid(1,c.size()-2));
        pile.pushMod(*exp);
    }   else if(estUneVariable(c)){
        pile.pushMod(varM.getVariable(c).getValue());
    }   else if(operateurRestant(c)){
        if(c=="DROP") {
            pile.popMod();
        }
        if(c=="DUP") {
            Litteral* temp = pile.top();
            pile.pushMod(*temp);
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
            changeCommande(lastop);
        }
        if(c=="LASTARGS") {
            while(!lastargs.empty()){
                pile.pushMod(*lastargs.last());
                lastargs.pop_back();
            }
        }
        lastop = c;
    }
    else pile.setMessage("Erreur : commande inconnue");
//    }

}
