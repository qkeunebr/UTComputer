#include "operationunaire.h"

/*Eval::Eval(Litteral& l) : OperationUnaire(l)
{
}*/

/*Litteral* Eval::getResult() const {
    Expression* exp = dynamic_cast<Expression*>(unique);
    QStack<Litteral*> pile;
    if (exp != NULL){
        //Le premier élément est un guillemet
        int i = 1;
        QString s = exp->getExp();
        Litteral* result = 0;
        while(i<s.length()){
            //On remplit la pile quand on rencontre un espace;
            if(s[i] == ' '){
                if(result != 0){
                    pile.push(result);
                    result = 0;
                }
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                if(result == 0) result = Addition(Rationnel(0),Rationnel(0)).getResult();
                result->addChiffre(s[i].toAscii() - '0');
            }
            else if(s[i] == '$'){
                if(result == 0) throw ("$ mal placé");
                result->setDollarEntre();
            }
            else if(s[i] == '/'){
                if(result != 0){
                    result->setSlashEntre();
                }
                else{
                    if(p.size() < 2) throw EvalException("Pas assez d'opérandes pour /");
                    Constante *op2 = p.pop(),  *op1 = p.pop();
                    try{
                        result = Division(*op1,*op2,mModeConstante,mModeComplexes).getValue();
                    }
                    catch(DivException e){
                        throw EvalException("division par zéro");
                    }

                    delete op1;
                    delete op2;
                    p.push(result);
                    result = 0;
                }
            }
            else if(s[i] == ',' || s[i] == '.'){
                if(result == 0) throw EvalException(", ou . mal placé");
                result->setVirguleEntree();
            }
            else if(s[i] == '+'){
                if(result!=0){
                    p.push(result);
                    result = 0;
                }
                if(p.size() < 2) throw EvalException("Pas assez d'opérandes pour +");
                Constante *op1 = p.pop(),  *op2 = p.pop();
                result = Addition(*op1,*op2,mModeConstante,mModeComplexes).getValue();
                delete op1;
                delete op2;
                p.push(result);
                result = 0;
            }
            else if(s[i] == '-'){
                if(result!=0){
                    p.push(result);
                    result = 0;
                }
                if(p.size() < 2) throw EvalException("Pas assez d'opérandes pour -");
                Constante *op2 = p.pop(),  *op1 = p.pop();
                result = Soustraction(*op1,*op2,mModeConstante,mModeComplexes).getValue();
                delete op1;
                delete op2;
                p.push(result);
                result = 0;
            }
            else if(s[i] == '*'){
                if(result!=0){
                    p.push(result);
                    result = 0;
                }
                if(p.size() < 2) throw EvalException("Pas assez d'opérandes pour *");
                Constante *op2 = p.pop(),  *op1 = p.pop();
                result = Multiplication(*op1,*op2,mModeConstante,mModeComplexes).getValue();
                delete op1;
                delete op2;
                p.push(result);
                result = 0;
            }
            else{
                throw EvalException("Caractère inconnu");
            }
            i++;
        }
        if(result!=0)p.push(result);
        if(p.size() > 1) throw ("Il manque un opérateur.");
        if(p.size() < 1) throw ("Pile d'évaluation vide.");
        return p.at(0);
    }
    else throw "Ceci n'est pas une expression";
}*/
