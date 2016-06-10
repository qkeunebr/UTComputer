#include "operationunaire.h"

/**
 * \fn OperateurLogiqueUnaire::OperateurLogiqueUnaire(Litteral &l1, QString c)
 * \brief Fonction de construction de l'objet OperateurLogiqueUnaire.
 *
 * \param Deux objets de type littérale et une variable de type QString.
 * \return Opération Logique Unaire composée de deux littérales.
 */
OperateurLogiqueUnaire::OperateurLogiqueUnaire(Litteral &l1, QString c):OperationUnaire(l1), str(c){}

/**
 * \fn Litteral* OperateurLogiqueUnaire::NOT(const Rationnel &r1) const
 * \brief Fonction pour appliquer l'opérateur NOT sur un objet de type Rationnel.
 *
 * \param Un objet de type Rationnel.
 * \return Littéral de type Rationnel.
 */
Litteral* OperateurLogiqueUnaire::NOT(const Rationnel &r1) const{
    Litteral* result;
    if(r1.getDenominateur()==1 && r1.getNumerateur()==1){
        result = new Rationnel(0,0);
    }
    else
        result = new Rationnel(1,1);
    return result;
}

/**
 * \fn Litteral* OperateurLogiqueUnaire::getResult() const
 * \brief Fonction qui appelle l'opérateur logique unaire NOT
 *
 *
 * \return Objet de type littéral.
 */
Litteral* OperateurLogiqueUnaire::getResult() const{
Rationnel* rationnelunique = dynamic_cast<Rationnel*>(unique);
    if(rationnelunique!=NULL){
        // unique est un rationnel
        return NOT(*rationnelunique);
    }
    else{
        throw "Litteral invalide";
    }
}
