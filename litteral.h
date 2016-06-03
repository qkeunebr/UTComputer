#ifndef LITTERAL_H
#define LITTERAL_H

#include <Qstring>

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
