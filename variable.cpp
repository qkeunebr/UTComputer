#include "variable.h"


Variable& VariableManager::getVariable(QString name){
    for(QVector<Variable>::iterator it = var.begin(); it!=var.end(); ++it){
        if(it->getName() == name )
            return *it;
    }
}

VariableManager::Handler VariableManager::handler=VariableManager::Handler();


VariableManager& VariableManager::getInstance(){
    if (handler.instance==nullptr) handler.instance=new VariableManager;
    return *handler.instance;
}

void VariableManager::libererInstance(){
    delete handler.instance;
    handler.instance=nullptr;
}

Variable& VariableManager::addVariable(QString n, Litteral& l){
    var.append(Variable(n, l));
    return var.last();
}

Variable& VariableManager::addVariable(QString n){
    var.append(Variable(n));
    return var.last();
}

void VariableManager::removeVariable(Variable& e){
    var.removeOne(e);
}

bool VariableManager::contains(Variable &e){
    return contains(e.getName());
}

bool VariableManager::contains(QString name){
    for(QVector<Variable>::iterator it = var.begin(); it!=var.end(); ++it){
        Variable temp = *it;
        if(temp.getName() == name )
            return true;
    }
    return false;
}

const QString Programme::toString() const{
    QString res("[");
    for(int i = 0; i<limiteAffichage; i++){
        res+=valeur.at(i);
    }
    res+="...]";
    return res;
}

ProgrammeManager::Handler ProgrammeManager::handler=ProgrammeManager::Handler();


ProgrammeManager& ProgrammeManager::getInstance(){
    if (handler.instance==nullptr) handler.instance=new ProgrammeManager;
    return *handler.instance;
}

void ProgrammeManager::libererInstance(){
    delete handler.instance;
    handler.instance=nullptr;
}

Programme& ProgrammeManager::addProgramme(QString n, QString l){
    prog.append(Programme(n, l));
    return prog.last();
}

void ProgrammeManager::removeProgramme(Programme& e){
    prog.removeOne(e);
}


bool ProgrammeManager::contains(QString name){
    for(QVector<Programme>::iterator it = prog.begin(); it!=prog.end(); ++it){
        if(it->getName() == name )
            return true;
    }
    return false;
}

Programme& ProgrammeManager::getProgramme(QString name){
    for(QVector<Programme>::iterator it = prog.begin(); it!=prog.end(); ++it){
        Programme temp = *it;
        if(temp.getName() == name )
            return temp;
    }
}

void Programme::ajouterChiffre(int chiffre){

}

void Variable::ajouterChiffre(int chiffre){

}
