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


class Eval : public OperationUnaire
{
    public:
        Eval(Litteral& l);
        //virtual Litteral* getResult() const;
};
#endif // OPERATIONUNAIRE_H
