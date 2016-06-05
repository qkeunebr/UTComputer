#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "litteral.h"
#include <QString>
#include <QObject>
#include <stack>
#include "operationbinaire.h"
#include "operationunaire.h"

class Pile : public QObject  {
    Q_OBJECT

    std::stack<Litteral*> sta;
    QString message;
    unsigned int nbAffiche;
public:
    Pile():sta(),message(""),nbAffiche(4){}
    void pushMod(Litteral& e);
    void popMod();
    void push(Litteral& e){sta.push(&e);}
    void pop(){ sta.pop();}
    int size(){return sta.size();}
    Litteral* top(){return sta.top();}
//    QStack<Litteral*>::Iterator begin(){return sta.begin();}
//    QStack<Litteral*>::Iterator end(){return sta.end();}
//    const Litteral* value(int i){return sta.value(i);}
    void setNbItemsToAffiche(unsigned int n) { nbAffiche=n; }
    unsigned int getNbItemsToAffiche() const { return nbAffiche; }
    void setMessage(const QString& m) { message=m; modificationEtat(); }
    QString getMessage() const { return message; }
signals:
    void modificationEtat();
};

class Controller{
    Pile pile;
public :
    Controller():pile(){}

    Pile* getPile(){
        return &pile;
    }
    void commande(const QString& c);


    bool estUnOperateurUnaire(const QString s);
    bool estUnOperateurBinaire(const QString s);
    bool estUnEntier(const QString s);
    bool estUnFloat(const QString s);

};
#endif // CONTROLLER_H
