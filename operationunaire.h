#ifndef OPERATIONUNAIRE_H
#define OPERATIONUNAIRE_H

#include "complexe.h"


/**
 * Classe representant une OperationUnaire generique et les elements communs des opérations de l'application
 *
 */


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
        virtual Litteral* getResult() const;
};

class Neg : public OperationUnaire
{
    public:
        Neg(Litteral& l);
        virtual Litteral* getResult() const;
    private:
        Litteral* neg(const Complexe& c) const;
        Litteral* neg(const Rationnel& r) const;
};

class Num : public OperationUnaire
{
    public:
        Num(Litteral& l);
        virtual Litteral* getResult() const;
    private:
        Litteral* num(const Rationnel &r1) const;
};

class Den : public OperationUnaire
{
    public:
        Den(Litteral& l);
        virtual Litteral* getResult() const;
    private:
        Litteral* den(const Rationnel &r1) const;
};

class RE : public OperationUnaire
{
    public:
        RE(Litteral& l);
        virtual Litteral* getResult() const;
    private:
        Litteral* re(const Complexe& c) const;
};

class IM : public OperationUnaire
{
    public:
        IM(Litteral& l);
        virtual Litteral* getResult() const;
    private:
        Litteral* im(const Complexe& c) const;
};

class OperateurLogiqueUnaire : public OperationUnaire
{
public:
    QString str;
    OperateurLogiqueUnaire(Litteral& l1, QString c);
    virtual Litteral* getResult() const;
private:
    Litteral* NOT(const Rationnel& r1) const;
};

#endif // OPERATIONUNAIRE_H
