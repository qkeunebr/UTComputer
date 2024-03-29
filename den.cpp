#include "operationunaire.h"
#include <QTextStream>

/**
 * \fn Den::Den(Litteral& l):unique(l)
 * \brief Fonction de construction de l'objet Den.
 *
 * \param Un objet de type littérale.
 * \return Opération unaire composée d'une unique litterale.
 */
Den::Den(Litteral& l):OperationUnaire(l){}

/**
 * \fn Litteral* Num::num(const Rationnel& r) const
 * \brief Fonction pour appliquer den sur un objet de type Rationnel.
 *
 * \param Un objet de type Rationnel.
 * \return Litteral de type Rationnel.
 */
Litteral* Den::den(const Rationnel& r) const{
    Litteral* result;
    if(r.getDenominateur()==1){
        //r est un entier
        result = new Rationnel(1, 1);
    }
    else{
        QTextStream out(stdout);
                   out << "LA";

        result = new  Rationnel(r.getDenominateur(), 1);
    }
    return result;
}

/**
 * \fn Litteral* Den::getResult() const
 * \brief Fonction qui appelle les différentes méthodes den selon le type de Littérale considéré
 *
 *
 * \return Objet de type littéral.
 */
Litteral* Den::getResult() const {
            Rationnel* rationnelunique = dynamic_cast<Rationnel*>(unique);
                if(rationnelunique!=NULL){
                    // unique est un rationnel
                    return den(*rationnelunique);
                }
                else{
                    throw "Litteral invalide";
                }
}

