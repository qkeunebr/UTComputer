#include "operationunaire.h"
#include "operationbinaire.h"
#include <QStack>
#include <QTextStream>
#include "controller.h"

Eval::Eval(Litteral& l) : OperationUnaire(l)
{
}

Litteral* Eval::getResult() const {
    Expression* exp = dynamic_cast<Expression*>(unique);
    Pile p;
    if (exp != NULL){
        int i = 0;
        QString s = exp->getExp();
        Litteral * result = 0;
        while(i<s.length()){
           if(s[i] >= '0' && s[i] <= '9'){
                Litteral* r1 = new Rationnel(0,1);
                Litteral* r2 = new Rationnel(0,1);
                if(result == 0)result = Addition(*r1,*r2).getResult();
                result->ajouterChiffre(s[i].digitValue());
            }
            else if(s[i] == '$'){
                if(result == 0) throw ("$ mal placé");
                //result->setDollarEntre();
            }
            else if(s[i] == '/'){
                if(result != 0){
                    //result->setSlashEntre();
                }
                else{
                    if(p.size() < 2) throw ("Pas assez d'opérandes pour /");
                    Litteral *op2 = p.top(),  *op1 = p.top();

                    result = Division(*op1,*op2).getResult();


                    delete op1;
                    delete op2;
                    p.push(*result);
                    result = 0;
                }
            }
            else if(s[i] == ',' || s[i] == '.'){
                if(result == 0) throw (", ou . mal placé");
                //result->setVirguleEntree();
            }
            else if(s[i] == '+'){
                if(result!=0){
                    p.push(*result);
                    result = 0;
                }
                if(p.size() < 2) throw ("Pas assez d'opérandes pour +");
                Litteral *op1 = p.top();
                QTextStream out(stdout);
                           out << op1->toString();
                Litteral *op2 = p.top();
                           out << op2->toString();
                result = Addition(*op1,*op2).getResult();
                delete op1;
                delete op2;
                p.push(*result);
                result = 0;
            }
            else if(s[i] == '-'){
                if(result!=0){
                    p.push(*result);
                    result = 0;
                }
                if(p.size() < 2) throw ("Pas assez d'opérandes pour -");
                Litteral* op2 = p.top(), * op1 = p.top();
                result = Soustraction(*op1,*op2).getResult();
                delete op1;
                delete op2;
                p.push(*result);
                result = 0;
            }
            else if(s[i] == '*'){
                if(result!=0){
                    p.push(*result);
                    result = 0;
                }
                if(p.size() < 2) throw ("Pas assez d'opérandes pour *");
                Litteral *op2 = p.top(),  *op1 = p.top();
                result = Multiplication(*op1,*op2).getResult();
                delete op1;
                delete op2;
                p.push(*result);
                result = 0;
            }
            else{
                throw ("Caractère inconnu");
            }
            i++;
        }
        if(result!=0)p.push(*result);
        if(p.size() > 1) throw ("Il manque un opérateur.");
        if(p.size() < 1) throw ("Pile d'évaluation vide.");
        return p.at(0);
    }
    else throw ("Ceci n'est pas une expression");
}

