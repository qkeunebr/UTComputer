#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "litteral.h"
#include <QString>
#include <QObject>
#include <QVector>
#include "operationbinaire.h"
#include "variable.h"
#include "operationunaire.h"

class Pile : public QObject  {
    Q_OBJECT

    QVector<Litteral*> stack;
    QString message;
    unsigned int nbAffiche;
public:
    Pile():stack(),message(""),nbAffiche(4){}
    void pushMod(Litteral& e);
    void popMod();
    void push(Litteral& e){stack.push_back(&e);}
    void pop(){ stack.pop_back();}
    unsigned int size(){return stack.size();}
    void clear(){stack.clear();}
    QString getStackAff();
    Litteral* top(){return stack.last();}
    Litteral* at(int i){return stack.at(i);}
    void setNbItemsToAffiche(unsigned int n) { nbAffiche=n; }
    unsigned int getNbItemsToAffiche() const { return nbAffiche; }
    void setMessage(const QString& m) { message=m; modificationEtat(); }
    QString getMessage() const { return message; }
    Pile& operator=(Pile p){
        stack = p.stack;
        message = p.message;
        nbAffiche = p.nbAffiche;
        return *this;
    }
    Pile(const Pile& p){
        stack = p.stack;
        message = p.message;
        nbAffiche = p.nbAffiche;
    }

signals:
    void modificationEtat();
};

class Controller : public QObject{
    Q_OBJECT

    Pile pile;
    VariableManager varM;
    ProgrammeManager progM;
    Pile pileSave;
    VariableManager varMSave;
    ProgrammeManager progMSave;
    QString lastop;
    QVector<Litteral*> lastargs;
public :
    Controller():pile(){varM = VariableManager::getInstance(); progM = ProgrammeManager::getInstance();}

    Pile* getPile(){
        return &pile;
    }
    void commande(const QString& c);
    VariableManager* getVariableManager(){
        return &varM;
    }
    ProgrammeManager* getProgrammeManager(){
        return &progM;
    }

    void save(){
        pileSave = pile;
        varMSave = varM;
        progMSave = progM;
    }
    void load(){
        pile = pileSave;
        varM = varMSave;
        progM = progMSave;
    }

    bool estUnOperateurLogique(const QString s);
    bool estUnOperateurUnaire(const QString s);
    bool estUnOperateurBinaire(const QString s);
    bool operateurRestant(const QString s);
    bool estUnEntier(const QString s);
    bool estUnFloat(const QString s);
    bool estUnComplexe(const QString s);
    bool estUneExpression(const QString s);
    bool estUnAtomeProgramme(const QString s);
    bool estUnProgramme(const QString s);
    bool estUneVariable(const QString s);
 signals:
    void changeCommande(QString);
    void changeTab(QString);

};
#endif // CONTROLLER_H
