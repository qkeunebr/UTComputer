#include "operationbinaire.h"

OperateurLogique::OperateurLogique(Litteral& l1, Litteral& l2, QString c):OperationBinaire(l1,l2), str(c){}

Litteral* OperateurLogique::egal(const Complexe& c1, const Complexe& c2)const{
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

Litteral* OperateurLogique::egal(const Rationnel& r1, const Rationnel& r2)const{
    Litteral* result;
    if((r1.getNumerateur()==r2.getNumerateur()) && (r1.getDenominateur()==r2.getDenominateur())){
        result = new Rationnel(1,1);
    }
    else
         result = new Rationnel(0,0);
    return result;
}

Litteral* OperateurLogique::diff(const Complexe& c1, const Complexe& c2)const{
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

Litteral* OperateurLogique::diff(const Rationnel& r1, const Rationnel& r2)const{
    Litteral* result;
    if((r1.getNumerateur()==r2.getNumerateur()) && (r1.getDenominateur()==r2.getDenominateur())){
        result = new Rationnel(0,0);
    }
    else
         result = new Rationnel(1,1);
    return result;
}

 Litteral* OperateurLogique::sup(const Complexe& c1, const Complexe& c2)const{
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

 Litteral* OperateurLogique::sup(const Rationnel& r1, const Rationnel& r2)const{
     Litteral* result;
     if((r1.getNumerateur()>r2.getNumerateur()) && (r1.getDenominateur()>=r2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
          result = new Rationnel(0,0);
     return result;
 }

 Litteral* OperateurLogique::supeg(const Rationnel& r1, const Rationnel& r2)const{
     Litteral* result;
     if((r1.getNumerateur()>=r2.getNumerateur()) && (r1.getDenominateur()>=r2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
          result = new Rationnel(0,0);
     return result;
 }



 Litteral* OperateurLogique::supeg(const Complexe& c1, const Complexe& c2)const{
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

 Litteral* OperateurLogique::inf(const Complexe& c1, const Complexe& c2) const{
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

 Litteral* OperateurLogique::infeg(const Complexe& c1, const Complexe& c2)const{
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


 Litteral* OperateurLogique::inf(const Rationnel& r1, const Rationnel& r2) const{
     Litteral* result;
     if((r1.getNumerateur()<r2.getNumerateur()) && (r1.getDenominateur()<=r2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
          result = new Rationnel(0,0);
     return result;
 }

 Litteral* OperateurLogique::infeg(const Rationnel& r1, const Rationnel& r2) const{
     Litteral* result;
     if((r1.getNumerateur()<=r2.getNumerateur()) && (r1.getDenominateur()<=r2.getDenominateur())){
         result = new Rationnel(1,1);
     }
     else
          result = new Rationnel(0,0);
     return result;
 }

 Litteral* OperateurLogique::ET(const Rationnel& c1, const Rationnel& c2)const{
     Litteral* result;
     if(c1.getNumerateur()==1 && (c2.getNumerateur()==1)){
         result = new Rationnel(1,1);
     }
     else
         result = new Rationnel(0,0);
     return result;
 }
 Litteral* OperateurLogique::OU(const Rationnel& c1, const Rationnel& c2)const {
     Litteral* result;
     if(c1.getNumerateur()==1 || (c1.getNumerateur()==1)){
         result = new Rationnel(1,1);
     }
     else
         result = new Rationnel(0,0);
     return result;
 }


 Litteral* OperateurLogique::getResult() const{
     Complexe* complexefirst = dynamic_cast<Complexe*>(first);
        if(complexefirst != NULL){
            Complexe* complexesecond = dynamic_cast<Complexe*>(second);
            if(complexesecond != NULL){
                if(str == "=") return egal(*complexefirst, *complexesecond);
                if(str == "!=") return diff(*complexefirst, *complexesecond);
                if(str == "<") return inf(*complexefirst, *complexesecond);
                if(str == ">") return sup(*complexefirst, *complexesecond);
                if(str == "<=") return infeg(*complexefirst, *complexesecond);
                if(str == ">=") return supeg(*complexefirst, *complexesecond);
            }
            else {
                throw "Litteral invalide";
                return new Rationnel(0,0);
            }
        }
      else{
            Rationnel* rationnelfirst = dynamic_cast<Rationnel*>(first);
            if(rationnelfirst!=NULL){
                Rationnel* rationnelsecond = dynamic_cast<Rationnel*>(second);
                if(rationnelsecond!=NULL){
                    if(str == "==") return egal(*rationnelfirst, *rationnelsecond);
                    if(str == "!=") return diff(*rationnelfirst, *rationnelsecond);
                    if(str == "<") return inf(*rationnelfirst, *rationnelsecond);
                    if(str == ">") return sup(*rationnelfirst, *rationnelsecond);
                    if(str == "<=") return infeg(*rationnelfirst, *rationnelsecond);
                    if(str == ">=") return supeg(*rationnelfirst, *rationnelsecond);
                    if(str == "AND") return ET(*rationnelfirst, *rationnelsecond);
                    if(str== "OR") return OU(*rationnelfirst, *rationnelsecond);
                }
            }
            else {
                throw "Litteral invalide";
                return new Rationnel(0,0);
            }
         }
    }

