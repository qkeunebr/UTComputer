#include "operationbinaire.h"

OperateurLogique::OperateurLogique(Litteral &l1, Litteral &l2):OperationBinaire(l1,l2){}

Litteral* egal(const Complexe& c1, const Complexe& c2){
    Litteral* result;
    if(!(c1.getSymboleDollar())){
        //c1 est réel
        if(!(c2.getSymboleDollar())){
            //c2 est réel
            if(c1.getReReel() == c2.getReReel())
                result = new Rationnel(1,1);
            else
                result = new Rationnel(0,0);
        }
        else{
            result = new Rationnel(0,0);
        }
    }
    else if(c1.estReel()){
        //c1 est composé de réels
        if(c2.estReel()){
            if((c1.getReReel()==c2.getReReel()) && (c1.getImReel()==c2.getImReel()))
                result = new Rationnel(1,1);
            else
                result = new Rationnel(0,0);
        }
        else
            result = new Rationnel(0,0);
    }
    else if (c1.estEntier()){
        //c1 est composé d'entiers
        if(c2.estEntier()){
            if((c1.getReEntier()==c2.getReEntier()) && (c1.getImEntier()==c2.getImEntier()))
                result = new Rationnel(1,1);
            else
                result = new Rationnel(0,0);
        }
        else
            result = new Rationnel(0,0);
    }
    else {
        //c1 est composé de Rationnels
        if(!(c2.getSymboleDollar()) || c2.estReel() || c2.estEntier()){
            result = new Rationnel(0,0);
        }
        else{
            if(c1.getReRationnel().getNumerateur()==c1.getReRationnel().getNumerateur() && c1.getReRationnel().getDenominateur()==c1.getReRationnel().getDenominateur() && (c1.getImRationnel().getNumerateur()==c2.getImRationnel().getNumerateur()) && (c1.getImRationnel().getDenominateur()==c2.getImRationnel().getDenominateur()) ){
              result = new Rationnel(1,1);
            }
            else
                result = new Rationnel(0,0);
        }
    }
    return result;
}

Litteral* egal(const Rationnel& r1, const Rationnel& r2){
    Litteral* result;
    if((r1.getNumerateur()==r2.getNumerateur()) && (r1.getDenominateur()==r2.getDenominateur())){
        result = new Rationnel(1,1);
    }
    else
         result = new Rationnel(0,0);
    return result;
}

Litteral* diff(const Complexe& c1, const Complexe& c2){
    Litteral* result;
    if(!(c1.getSymboleDollar())){
        //c1 est réel
        if(!(c2.getSymboleDollar())){
            //c2 est réel
            if(c1.getReReel() == c2.getReReel())
                result = new Rationnel(0,0);
            else
                result = new Rationnel(1,1);
        }
        else{
            result = new Rationnel(1,1);
        }
    }
    else if(c1.estReel()){
        //c1 est composé de réels
        if(c2.estReel()){
            if((c1.getReReel()==c2.getReReel()) && (c1.getImReel()==c2.getImReel()))
                result = new Rationnel(0,0);
            else
                result = new Rationnel(1,1);
        }
        else
            result = new Rationnel(1,1);
    }
    else if (c1.estEntier()){
        //c1 est composé d'entiers
        if(c2.estEntier()){
            if((c1.getReEntier()==c2.getReEntier()) && (c1.getImEntier()==c2.getImEntier()))
                result = new Rationnel(0,0);
            else
                result = new Rationnel(1,1);
        }
        else
            result = new Rationnel(1,1);
    }
    else {
        //c1 est composé de Rationnels
        if(!(c2.getSymboleDollar()) || c2.estReel() || c2.estEntier()){
            result = new Rationnel(1,1);
        }
        else{
            if(c1.getReRationnel().getNumerateur()==c1.getReRationnel().getNumerateur() && c1.getReRationnel().getDenominateur()==c1.getReRationnel().getDenominateur() && (c1.getImRationnel().getNumerateur()==c2.getImRationnel().getNumerateur()) && (c1.getImRationnel().getDenominateur()==c2.getImRationnel().getDenominateur()) ){
              result = new Rationnel(0,0);
            }
            else
                result = new Rationnel(1,1);
        }
    }
    return result;
}

Litteral* diff(const Rationnel& r1, const Rationnel& r2){
    Litteral* result;
    if((r1.getNumerateur()==r2.getNumerateur()) && (r1.getDenominateur()==r2.getDenominateur())){
        result = new Rationnel(0,0);
    }
    else
         result = new Rationnel(1,1);
    return result;
}

 Litteral* sup(const Complexe& c1, const Complexe& c2){
     Litteral* result;
     if(!(c1.getSymboleDollar())){
         //c1 est réel
         if(!(c2.getSymboleDollar())){
             //c2 est réel
             if(c1.getReReel() > c2.getReReel())
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else{
             result = new Rationnel(0,0);
         }
     }
     else if(c1.estReel()){
         //c1 est composé de réels
         if(c2.estReel()){
             if((c1.getReReel()>c2.getReReel()) && (c1.getImReel()>c2.getImReel()))
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else
             result = new Rationnel(0,0);
     }
     else if (c1.estEntier()){
         //c1 est composé d'entiers
         if(c2.estEntier()){
             if((c1.getReEntier()>c2.getReEntier()) && (c1.getImEntier()>c2.getImEntier()))
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else
             result = new Rationnel(0,0);
     }
     else {
         //c1 est composé de Rationnels
         if(!(c2.getSymboleDollar()) || c2.estReel() || c2.estEntier()){
             result = new Rationnel(0,0);
         }
         else{
             if(c1.getReRationnel().getNumerateur()>c1.getReRationnel().getNumerateur() && c1.getReRationnel().getDenominateur()>c1.getReRationnel().getDenominateur() && (c1.getImRationnel().getNumerateur()>c2.getImRationnel().getNumerateur()) && (c1.getImRationnel().getDenominateur()>c2.getImRationnel().getDenominateur()) ){
               result = new Rationnel(1,1);
             }
             else
                 result = new Rationnel(0,0);
         }
     }
     return result;
 }

 Litteral* sup(const Rationnel& r1, const Rationnel& r2){
     Litteral* result;
     if((r1.getNumerateur()>r2.getNumerateur()) && (r1.getDenominateur()>r2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
          result = new Rationnel(0,0);
     return result;
 }

 Litteral* supeg(const Rationnel& r1, const Rationnel& r2){
     Litteral* result;
     if((r1.getNumerateur()>=r2.getNumerateur()) && (r1.getDenominateur()>=r2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
          result = new Rationnel(0,0);
     return result;
 }



 Litteral* supeg(const Complexe& c1, const Complexe& c2){
     Litteral* result;
     if(!(c1.getSymboleDollar())){
         //c1 est réel
         if(!(c2.getSymboleDollar())){
             //c2 est réel
             if(c1.getReReel() >= c2.getReReel())
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else{
             result = new Rationnel(0,0);
         }
     }
     else if(c1.estReel()){
         //c1 est composé de réels
         if(c2.estReel()){
             if((c1.getReReel()>=c2.getReReel()) && (c1.getImReel()>=c2.getImReel()))
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else
             result = new Rationnel(0,0);
     }
     else if (c1.estEntier()){
         //c1 est composé d'entiers
         if(c2.estEntier()){
             if((c1.getReEntier()>=c2.getReEntier()) && (c1.getImEntier()>=c2.getImEntier()))
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else
             result = new Rationnel(0,0);
     }
     else {
         //c1 est composé de Rationnels
         if(!(c2.getSymboleDollar()) || c2.estReel() || c2.estEntier()){
             result = new Rationnel(0,0);
         }
         else{
             if(c1.getReRationnel().getNumerateur()>=c1.getReRationnel().getNumerateur() && c1.getReRationnel().getDenominateur()>=c1.getReRationnel().getDenominateur() && (c1.getImRationnel().getNumerateur()>=c2.getImRationnel().getNumerateur()) && (c1.getImRationnel().getDenominateur()>=c2.getImRationnel().getDenominateur()) ){
               result = new Rationnel(1,1);
             }
             else
                 result = new Rationnel(0,0);
         }
     }
     return result;
 }

 Litteral* inf(const Complexe& c1, const Complexe& c2) {
     Litteral* result;
     if(!(c1.getSymboleDollar())){
         //c1 est réel
         if(!(c2.getSymboleDollar())){
             //c2 est réel
             if(c1.getReReel() < c2.getReReel())
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else{
             result = new Rationnel(0,0);
         }
     }
     else if(c1.estReel()){
         //c1 est composé de réels
         if(c2.estReel()){
             if((c1.getReReel()<c2.getReReel()) && (c1.getImReel()<c2.getImReel()))
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else
             result = new Rationnel(0,0);
     }
     else if (c1.estEntier()){
         //c1 est composé d'entiers
         if(c2.estEntier()){
             if((c1.getReEntier()<c2.getReEntier()) && (c1.getImEntier()<c2.getImEntier()))
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else
             result = new Rationnel(0,0);
     }
     else {
         //c1 est composé de Rationnels
         if(!(c2.getSymboleDollar()) || c2.estReel() || c2.estEntier()){
             result = new Rationnel(0,0);
         }
         else{
             if(c1.getReRationnel().getNumerateur()<c1.getReRationnel().getNumerateur() && c1.getReRationnel().getDenominateur()<c1.getReRationnel().getDenominateur() && (c1.getImRationnel().getNumerateur()<c2.getImRationnel().getNumerateur()) && (c1.getImRationnel().getDenominateur()<c2.getImRationnel().getDenominateur()) ){
               result = new Rationnel(1,1);
             }
             else
                 result = new Rationnel(0,0);
         }
     }
     return result;
 }

 Litteral* infeg(const Complexe& c1, const Complexe& c2){
     Litteral* result;
     if(!(c1.getSymboleDollar())){
         //c1 est réel
         if(!(c2.getSymboleDollar())){
             //c2 est réel
             if(c1.getReReel() < c2.getReReel())
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else{
             result = new Rationnel(0,0);
         }
     }
     else if(c1.estReel()){
         //c1 est composé de réels
         if(c2.estReel()){
             if((c1.getReReel()<=c2.getReReel()) && (c1.getImReel()<=c2.getImReel()))
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else
             result = new Rationnel(0,0);
     }
     else if (c1.estEntier()){
         //c1 est composé d'entiers
         if(c2.estEntier()){
             if((c1.getReEntier()<=c2.getReEntier()) && (c1.getImEntier()<=c2.getImEntier()))
                 result = new Rationnel(1,1);
             else
                 result = new Rationnel(0,0);
         }
         else
             result = new Rationnel(0,0);
     }
     else {
         //c1 est composé de Rationnels
         if(!(c2.getSymboleDollar()) || c2.estReel() || c2.estEntier()){
             result = new Rationnel(0,0);
         }
         else{
             if(c1.getReRationnel().getNumerateur()<=c1.getReRationnel().getNumerateur() && c1.getReRationnel().getDenominateur()<=c1.getReRationnel().getDenominateur() && (c1.getImRationnel().getNumerateur()<=c2.getImRationnel().getNumerateur()) && (c1.getImRationnel().getDenominateur()<=c2.getImRationnel().getDenominateur()) ){
               result = new Rationnel(1,1);
             }
             else
                 result = new Rationnel(0,0);
         }
     }
     return result;
 }


 Litteral* inf(const Rationnel& r1, const Rationnel& r2){
     Litteral* result;
     if((r1.getNumerateur()<r2.getNumerateur()) && (r1.getDenominateur()<r2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
          result = new Rationnel(0,0);
     return result;
 }

 Litteral* infeg(const Rationnel& r1, const Rationnel& r2){
     Litteral* result;
     if((r1.getNumerateur()<=r2.getNumerateur()) && (r1.getDenominateur()<=r2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
          result = new Rationnel(0,0);
     return result;
 }

 Litteral* ET(const Rationnel& c1, const Rationnel& c2){
     Litteral* result;
     if(c1.getNumerateur()==c2.getDenominateur() && (c2.getNumerateur()==c2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
         result = new Rationnel(0,0);
     return result;
 }
 Litteral* OU(const Rationnel& c1, const Rationnel& c2) {
     Litteral* result;
     if(c1.getNumerateur()==c2.getDenominateur() || (c2.getNumerateur()==c2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
         result = new Rationnel(0,0);
     return result;
 }
