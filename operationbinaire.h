#ifndef OPERATIONBINAIRE_H
#define OPERATIONBINAIRE_H

#include "litteral.h"

class OperationBinaire
{
    protected:
        Litteral* first;
        Litteral* second;
    public:
        OperationBinaire(Litteral& l1, Litteral& l2);
};

#endif // OPERATIONBINAIRE_H
