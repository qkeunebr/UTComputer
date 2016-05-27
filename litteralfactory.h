#ifndef LITTERALFACTORY_H
#define LITTERALFACTORY_H

#include "litteral.h"

class LitteralFactory
{
public:
    virtual Litteral* CreateLitteral() = 0;
};



#endif // LITTERALFACTORY_H
