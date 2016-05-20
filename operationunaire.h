#ifndef OPERATIONUNAIRE_H
#define OPERATIONUNAIRE_H

#include "litteral.h"

class OperationUnaire
{
    protected:
        Litteral* unique;
    public:
        OperationUnaire(Litteral& l);
};
#endif // OPERATIONUNAIRE_H
