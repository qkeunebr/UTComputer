#ifndef LITTERAL_H
#define LITTERAL_H

#include <Qstring>

/**
 * Classe representant une Litterale generique et les elements communs des Litterales de l'application
 * Les methodes sont virtuelles permettent la manipulation de littérales en dehors de la classe sans
 * connaitre leur type exact
 */

class Litteral
{
    float valuef;
    int valueint;
public:
    Litteral(float f):valuef(f){}
    Litteral(int i):valueint(i){}
    float getFloat() const{return valuef;}
    int getInt() const{return valueint;}
    virtual ~Litteral() {}
    virtual const QString toString() const;
};

#endif // LITTERAL_H
