#include "operationunaire.h"

/**
 * \fn Neg::Num(Litteral& l):unique(l)
 * \brief Fonction de construction de l'objet Num.
 *
 * \param Un objet de type littérale.
 * \return Opération unaire composée d'une unique litterale.
 */
Neg::Num(Litteral& l):unique(l){}

/**
 * \fn Litteral* Num::num(const Rationnel& r) const
 * \brief Fonction pour appliquer num sur un objet de type Rationnel.
 *
 * \param Un objet de type Rationnel.
 * \return Litteral de type Rationnel.
 */
Litteral* Num::num(const Rationnel& r) const{
    if(r.getDenominateur()==1){
        //r est un entier
        return r;
    }
    else{
        return Rationnel(r.getNumerateur(), 1);
    }
}

/**
 * \fn Litteral* Num::getResult() const
 * \brief Fonction qui appelle les différentes méthodes num selon le type de Littérale considéré
 *
 *
 * \return Objet de type littéral.
 */
Litteral* Num::getResult() const {
            Rationnel* rationnelunique = dynamic_cast<Rationnel*>(unique);
                if(rationnelunique!=NULL){
                    // unique est un rationnel
                    return num(*rationnelunique);
                }
                else{
                    throw "Litteral invalide";
                }
}

