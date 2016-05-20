#ifndef ADDITION_H
#define ADDITION_H

#include "operationbinaire.h"

class Addition : public OperationBinaire {
    public:
        Addition(Litteral& l1, Litteral& l2);
        Litteral* addition(const Rationnel& r1, const Rationnel& r2);
        Litteral* addition(const Complexe& c1, const Complexe& c2);
};

#endif // ADDITION_H
