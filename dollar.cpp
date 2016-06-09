/**
 * \file dollar.cpp
 * \brief Operation Dollar
 * \author Quentin Keunebroek
 * \version 1.0
 * \date 3 juin 2016
 *
 * Opération Dollar pour tout type de Littérale.
 *
 */

#include "operationbinaire.h"
#include <QTextStream>

Dollar::Dollar(Litteral& l1, Litteral& l2):OperationBinaire(l1,l2){}

Litteral* Dollar::dollar(const Complexe& c1, const Complexe& c2) const{
    Litteral* result;
    if (c1.estReel() || !(c1.getSymboleDollar())) {
        if(c2.estReel() || !(c2.getSymboleDollar())){
            result = new Complexe(c1.getReReel(), c2.getReReel());
        }
        else if (c2.estEntier()){
            result = new Complexe(c1.getReReel(), (float)c2.getImEntier());
        }
        else {
            result = new Complexe(Rationnel((int)c1.getReReel(),1), Rationnel(c2.getImRationnel().getNumerateur(), c2.getImRationnel().getDenominateur()));
        }
    }
    else if (c1.estEntier()){


        if(c2.estReel() || !(c2.getSymboleDollar())){
            result = new Complexe((float)c1.getReEntier(), c2.getImReel());
        }
        else if (c2.estEntier()){
            result = new Complexe((float)c1.getReEntier(), (float)c2.getImEntier());
        }
        else {
            result = new Complexe(Rationnel(c1.getReEntier(),1), Rationnel(c2.getImRationnel().getNumerateur(), c2.getImRationnel().getDenominateur()));
        }
    }
    else{
        //Le complexe c1 est un rationnel
        if(c2.estReel() || !(c2.getSymboleDollar())){
            result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur(), c1.getReRationnel().getDenominateur()),
                            Rationnel((int)c2.getImReel(),1));
        }
        else if (c2.estEntier()){
            result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur(), c1.getReRationnel().getDenominateur()),
                            Rationnel((int)c2.getImEntier(),1));
        }
        else {
            result = new Complexe(Rationnel(c1.getReRationnel().getNumerateur(), c1.getReRationnel().getDenominateur()),
                            Rationnel(c2.getImRationnel().getNumerateur(),c2.getImRationnel().getDenominateur()));
        }
    }
    return result;
}

Litteral* Dollar::getResult()const {
     Complexe* complexefirst = dynamic_cast<Complexe*>(first);
         if (complexefirst != NULL) {
                // first est un complexe
                Complexe* complexesecond = dynamic_cast<Complexe*>(second);
                if(complexesecond != NULL){
                    return dollar(*complexefirst, *complexesecond);
                }
         }
         else {
               throw "Litteral non valide";
            }
}

