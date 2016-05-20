#ifndef ADDITION_H
#define ADDITION_H

#include "operationbinaire.h"
#include "litteral.h"

class Addition : public OperationBinaire {
    public:
        Addition(Litteral& l1, Litteral& l2);
};

#endif // ADDITION_H
