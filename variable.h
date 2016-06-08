#include "variable.h"

/**
 * \fn  Variable& VariableManager::getVariable(QString name)
 * \brief  Retourne la variable d'après son nom
 *
 * \param  name Le nom
 * \return  La variable
 */
Variable& VariableManager::getVariable(QString name){
    for(QVector<Variable>::iterator it = var.begin(); it!=var.end(); ++it){
        if(it->getName() == name )
            return *it;
    }
}

VariableManager::Handler VariableManager::handler=VariableManager::Handler();

/**
 * \fn  VariableManager& VariableManager::getInstance()
 * \brief  Retourne l'unique manager de variable
 *
 * \return  Le manager de variable
 */
VariableManager& VariableManager::getInstance(){
    if (handler.instance==nullptr) handler.instance=new VariableManager;
    return *handler.instance;
}

/**
 * \fn  void VariableManager::libererInstance()
 * \brief  Libère l'unique manager de variable
 *
 */
void VariableManager::libererInstance(){
    delete handler.instance;
    handler.instance=nullptr;
}

/**
 * \fn  Variable& VariableManager::addVariable(QString n, Litteral& l)
 * \brief  Créer une varialbe et la rajoute au manager
 *
 * \param  n Le nom
 * \param  l La littéral
 * \return  La variable
 */
Variable& VariableManager::addVariable(QString n, Litteral& l){
    var.append(Variable(n, l));
    return var.last();
}

/**
 * \fn  void VariableManager::removeVariable(Variable& e)
 * \brief  Enlève la variable du manager
 *
 * \param  e La variable à enlever
 */
void VariableManager::removeVariable(Variable& e){
    var.removeOne(e);
}

/**
 * \fn  bool VariableManager::contains(Variable& e)
 * \brief  Vérifie si le manager contient la variable
 *
 * \param  e La variable recherchée
 * \return vrai si contenu
 */
bool VariableManager::contains(Variable &e){
    return contains(e.getName());
}

/**
 * \fn  bool VariableManager::contains(QString name)
 * \brief  Vérifie si le manager contient la variable
 *
 * \param  name Le nom de la variable recherchée
 * \return vrai si contenu
 */
bool VariableManager::contains(QString name){
    for(QVector<Variable>::iterator it = var.begin(); it!=var.end(); ++it){
        Variable temp = *it;
        if(temp.getName() == name )
            return true;
    }
    return false;
}

/**
 * \fn  const QString Programme::toString() const
 * \brief  Le nom du programme en QString
 *
 * \return Le nom du programme
 */
const QString Programme::toString() const{
    return QString(nom);

}

const QString Programme::aff() const{
    QString res("[");
    for(int i = 0; i<limiteAffichage; i++){
        res+=valeur.at(i);
    }
    res+="...]";
    return res;
}

ProgrammeManager::Handler ProgrammeManager::handler=ProgrammeManager::Handler();


/**
 * \fn   ProgrammeManager&  ProgrammeManager::getInstance()
 * \brief  Retourne l'unique manager de  Programme
 *
 * \return  Le manager de  Programme
 */
ProgrammeManager& ProgrammeManager::getInstance(){
    if (handler.instance==nullptr) handler.instance=new ProgrammeManager;
    return *handler.instance;
}

/**
 * \fn  void  ProgrammeManager::libererInstance()
 * \brief  Libère l'unique manager de  Programme
 *
 */
void ProgrammeManager::libererInstance(){
    delete handler.instance;
    handler.instance=nullptr;
}

/**
 * \fn   Programme&  ProgrammeManager::add Programme(QString n, Litteral& l)
 * \brief  Créer un programme et le rajoute au manager
 *
 * \param  n Le nom
 * \param  l La littéral
 * \param  lim La limite de l'affichage
 * \return  Le Programme
 */
Programme& ProgrammeManager::addProgramme(QString n, QString l){
    prog.append(Programme(n, l));
    return prog.last();
}

/**
 * \fn  void  ProgrammeManager::remove Programme( Programme& e)
 * \brief  Enlève le programme du manager
 *
 * \param  e Le Programme à enlever
 */
void ProgrammeManager::removeProgramme(Programme& e){
    prog.removeOne(e);
}

/**
 * \fn  bool  ProgrammeManager::contains(QString name)
 * \brief  Vérifie si le manager contient le Programme
 *
 * \param  name Le nom de la  Programme recherchée
 * \return vrai si contenu
 */
bool ProgrammeManager::contains(QString name){
    for(QVector<Programme>::iterator it = prog.begin(); it!=prog.end(); ++it){
        if(it->getName() == name )
            return true;
    }
    return false;
}

/**
 * \fn   Programme&  ProgrammeManager::get Programme(QString name)
 * \brief  Retourne le Programme d'après son nom
 *
 * \param  name Le nom
 * \return  Le Programme
 */
Programme& ProgrammeManager::getProgramme(QString name){
    for(QVector<Programme>::iterator it = prog.begin(); it!=prog.end(); ++it){
        Programme temp = *it;
        if(temp.getName() == name )
            return temp;
    }
}
