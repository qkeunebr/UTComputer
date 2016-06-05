#include "operationunaire.h"

/**
 * \fn Neg::Neg(Litteral& l):unique(l)
 * \brief Fonction de construction de l'objet Neg.
 *
 * \param Un objet de type littérale.
 * \return Opération unaire composée d'une unique litterale.
 */
Neg::Neg(Litteral& l):OperationUnaire(l){}

/**
 * \fn Litteral*  Neg::neg(const Complexe& c) const
 * \brief Fonction pour appliquer la negation sur un objet de type Complexe.
 *
 * \param Un objet de type Complexe.
 * \return Litteral de type Complexe.
 */
Litteral*  Neg::neg(const Complexe& c) const{
    Litteral* result;
    if(!c.getSymboleDollar()){
        //partie imaginaire nulle
        result = new Complexe(-c.getReReel(),0.0);
    }
    else if (c.estReel()){
        //c est composé de réels
        result = new Complexe(-c.getReReel(), -c.getImReel());
    }
    else if(c.estEntier()){
        //c est composé d'entiers
        result = new Complexe(-c.getReEntier(), -c.getImEntier());
    }
    else{
        //c est un Rationnel
        result = new Complexe(Rationnel(-c.getReRationnel().getNumerateur(), c.getReRationnel().getDenominateur()),
                        Rationnel(-c.getImRationnel().getNumerateur(), c.getImRationnel().getDenominateur()));
    }
}

/**
 * \fn Litteral* Neg::neg(const Rationnel& r) const
 * \brief Fonction pour appliquer la negation sur un objet de type Rationnel.
 *
 * \param Un objet de type Rationnel.
 * \return Litteral de type Rationnel.
 */
Litteral* Neg::neg(const Rationnel& r) const{
    Litteral* result;
    if(r.getDenominateur()==1){
        //r est un entier
        result = new Rationnel(-r.getNumerateur(), 1);
    }
    else{
        result = new Rationnel(-r.getNumerateur(), r.getDenominateur());
    }
}

/**
 * \fn Litteral* Neg::getResult() const
 * \brief Fonction qui appelle les différentes méthodes negation selon le type de Littérale considéré
 *
 *
 * \return Objet de type littéral.
 */
Litteral* Neg::getResult() const {
     Complexe* complexeunique = dynamic_cast<Complexe*>(unique);
           if (complexeunique != NULL) {
                // unique est un complexe
                return neg(*complexeunique);
            }
            else {
                Rationnel* rationnelunique = dynamic_cast<Rationnel*>(unique);
                    // unique est un rationnel
                    return neg(*rationnelunique);
            }
}

