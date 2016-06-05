#include "operationunaire.h"

/**
 * \fn RE::RE(Litteral& l):unique(l)
 * \brief Fonction de construction de l'objet RE.
 *
 * \param Un objet de type littérale.
 * \return Opération unaire composée d'une unique litterale.
 */
RE::RE(Litteral& l):unique(l){}

/**
 * \fn Litteral*  RE::re(const Complexe& c) const
 * \brief Fonction pour appliquer la méthode re sur un objet de type Complexe.
 *
 * \param Un objet de type Complexe.
 * \return Litteral de type Complexe.
 */
Litteral*  RE::re(const Complexe& c) const{
    if(!c.getSymboleDollar()){
        //partie imaginaire nulle
        return Complexe(c.getReReel(), 0.0);
    }
    else if (c.estReel){
        //c est composé de réels
        return Complexe(c.getReReel(), 0.0);
    }
    else if(c.estEntier()){
        //c est composé d'entiers
        return Complexe(c.getReEntier(), 0);
    }
    else{
        //c est un Rationnel
        return Complexe(Rationnel(c.getReRationnel().getNumerateur(), c.getReRationnel().getDenominateur()),
                        Rationnel(1, 1));
    }
}


/**
 * \fn Litteral* RE::getResult() const
 * \brief Fonction qui appelle les différentes méthodes re selon le type de Littérale considéré
 *
 *
 * \return Objet de type littéral.
 */
Litteral* RE::getResult() const {
     Complexe* complexeunique = dynamic_cast<Complexe*>(unique);
           if (complexeunique != NULL) {
                // unique est un complexe
                return re(*complexeunique);
            }
            else {
                return unique;
            }
}

