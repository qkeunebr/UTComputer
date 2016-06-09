#include "operationunaire.h"

/**
 * \fn RE::RE(Litteral& l):unique(l)
 * \brief Fonction de construction de l'objet RE.
 *
 * \param Un objet de type littérale.
 * \return Opération unaire composée d'une unique litterale.
 */
RE::RE(Litteral& l):OperationUnaire(l){}

/**
 * \fn Litteral*  RE::re(const Complexe& c) const
 * \brief Fonction pour appliquer la méthode re sur un objet de type Complexe.
 *
 * \param Un objet de type Complexe.
 * \return Litteral de type Complexe.
 */
Litteral*  RE::re(const Complexe& c) const{
    Litteral* result;
    if(!c.getSymboleDollar()){
        //partie imaginaire nulle
        result = new Complexe(c.getReReel(), 0.0);
    }
    else if (c.estReel()){
        //c est composé de réels
        result = new Complexe(c.getReReel(), 0.0);
    }
    else if(c.estEntier()){
        //c est composé d'entiers
        result = new Complexe(c.getReEntier(), 0);
    }
    else{
        //c est un Rationnel
        result = new Complexe(Rationnel(c.getReRationnel().getNumerateur(), c.getReRationnel().getDenominateur()),
                        Rationnel(1, 1));
    }
   return result;
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

