#include "operationunaire.h"

/**
 * \fn IM::IM(Litteral& l):unique(l)
 * \brief Fonction de construction de l'objet IM.
 *
 * \param Un objet de type littérale.
 * \return Opération unaire composée d'une unique litterale.
 */
IM::IM(Litteral& l):unique(l){}

/**
 * \fn Litteral*  IM::im(const Complexe& c) const
 * \brief Fonction pour appliquer la méthode re sur un objet de type Complexe.
 *
 * \param Un objet de type Complexe.
 * \return Litteral de type Complexe.
 */
Litteral*  IM::im(const Complexe& c) const{
    if(!c.getSymboleDollar()){
        //partie imaginaire nulle
        return Complexe(0.0, c.getImReel());
    }
    else if (c.estReel){
        //c est composé de réels
        return Complexe(0.0, c.getImReel());
    }
    else if(c.estEntier()){
        //c est composé d'entiers
        return Complexe(0, c.getImEntier());
    }
    else{
        //c est un Rationnel
        return Complexe(Rationnel(1,1),
                        Rationnel(c.getImRationnel().getNumerateur(), c.getImRationnel().getDenominateur()));
    }
}


/**
 * \fn Litteral* IM::getResult() const
 * \brief Fonction qui appelle les différentes méthodes im selon le type de Littérale considéré
 *
 *
 * \return Objet de type littéral.
 */
Litteral* IM::getResult() const {
     Complexe* complexeunique = dynamic_cast<Complexe*>(unique);
           if (complexeunique != NULL) {
                // unique est un complexe
                return im(*complexeunique);
            }
            else {
                return unique;
            }
}

