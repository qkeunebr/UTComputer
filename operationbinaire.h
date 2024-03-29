#ifndef OPERATIONBINAIRE_H
#define OPERATIONBINAIRE_H

#include "complexe.h"
#include "expression.h"

/**
 * Classe representant une OperationBinaire generique et les elements communs des opérations de l'application
 */


class OperationBinaire
{
    protected:
        Litteral* first;
        Litteral* second;
    public:
        OperationBinaire(Litteral& l1, Litteral& l2);
        //Méthode virtuelle permettant d'appeler les opérations et de renvoyer le résultat. Exemple : Addition(...).getResult()
        virtual Litteral* getResult() const = 0;
};


class Addition : public OperationBinaire {
    public:
        Addition(Litteral& l1, Litteral& l2);
        virtual Litteral* getResult() const;
    private:
        //Passer par le constructeur et la méthode getResult() pour faire ces opérations
        Litteral* addition(const Rationnel& r1, const Rationnel& r2) const;
        Litteral* addition(const Complexe& c1, const Complexe& c2) const;
        Litteral* addition(const Complexe& c1, const Rationnel& r1) const;
        Litteral* addition(const Rationnel& r1, const Complexe& c1) const;
        Litteral* addition(const Expression& e1, const Expression& e2) const;
        Litteral* addition(const Expression& e1, const Rationnel& r1) const;
        Litteral* addition(const Expression& e1, const Complexe& c1) const;
        Litteral* addition(const Rationnel& r1, const Expression& e1) const;
        Litteral* addition(const Complexe& c1, const Expression& e1) const;

};

class Soustraction : public OperationBinaire {
    public:
        Soustraction(Litteral& l1, Litteral& l2);
        virtual Litteral* getResult() const;
    private:
        //Passer par le constructeur et la méthode getResult() pour faire ces opérations
        Litteral* soustraction(const Rationnel& r1, const Rationnel& r2) const;
        Litteral* soustraction(const Complexe& c1, const Complexe& c2) const;
        Litteral* soustraction(const Complexe& c1, const Rationnel& r1) const;
        Litteral* soustraction(const Rationnel& r1, const Complexe& c1) const;
        Litteral* soustraction(const Expression& e1, const Expression& e2) const;
        Litteral* soustraction(const Expression& e1, const Rationnel& r1) const;
        Litteral* soustraction(const Expression& e1, const Complexe& c1) const;
        Litteral* soustraction(const Rationnel& r1, const Expression& e1) const;
        Litteral* soustraction(const Complexe& c1, const Expression& e1) const;

};

class Multiplication : public OperationBinaire {
    public:
        Multiplication(Litteral& l1, Litteral& l2);
        virtual Litteral* getResult() const;
    private:
        //Passer par le constructeur et la méthode getResult() pour faire ces opérations
        Litteral* multiplication(const Rationnel& r1, const Rationnel& r2) const;
        Litteral* multiplication(const Complexe& c1, const Complexe& c2) const;
        Litteral* multiplication(const Complexe& c1, const Rationnel& r1) const;
        Litteral* multiplication(const Rationnel& r1, const Complexe& c1) const;
        Litteral* multiplication(const Expression& e1, const Expression& e2) const;
        Litteral* multiplication(const Expression& e1, const Rationnel& r1) const;
        Litteral* multiplication(const Expression& e1, const Complexe& c1) const;
        Litteral* multiplication(const Rationnel& r1, const Expression& e1) const;
        Litteral* multiplication(const Complexe& c1, const Expression& e1) const;
};

class Division : public OperationBinaire {
    public:
        Division(Litteral& l1, Litteral& l2);
        virtual Litteral* getResult() const;
    private:
        //Passer par le constructeur et la méthode getResult() pour faire ces opérations
        Litteral* division(const Rationnel& r1, const Rationnel& r2) const;
        Litteral* division(const Complexe& c1, const Complexe& c2) const;
        Litteral* division(const Complexe& c1, const Rationnel& r1) const;
        Litteral* division(const Rationnel& r1, const Complexe& c1) const;
        Litteral* division(const Expression& e1, const Expression& e2) const;
        Litteral* division(const Expression& e1, const Rationnel& r1) const;
        Litteral* division(const Expression& e1, const Complexe& c1) const;
        Litteral* division(const Rationnel& r1, const Expression& e1) const;
        Litteral* division(const Complexe& c1, const Expression& e1) const;

};

class DivisionEntiere : public OperationBinaire {
    public:
        DivisionEntiere(Litteral& l1, Litteral& l2);
        virtual Litteral* getResult() const;
    private:
        //Passer par le constructeur et la méthode getResult() pour faire ces opérations
        Litteral* divisionentiere(const Rationnel& r1, const Rationnel& r2) const;
        Litteral* divisionentiere(const Complexe& c1, const Complexe& c2) const;
        Litteral* divisionentiere(const Complexe& c1, const Rationnel& r1) const;
        Litteral* divisionentiere(const Rationnel& r1, const Complexe& c1) const;
        Litteral* divisionentiere(const Expression& e1, const Expression& e2) const;
        Litteral* divisionentiere(const Expression& e1, const Rationnel& r1) const;
        Litteral* divisionentiere(const Expression& e1, const Complexe& c1) const;
        Litteral* divisionentiere(const Rationnel& r1, const Expression& e1) const;
        Litteral* divisionentiere(const Complexe& c1, const Expression& e1) const;
};

class Dollar : public OperationBinaire
{
    public:
        Dollar(Litteral& l1, Litteral& l2);
        virtual Litteral* getResult() const;

    private:
        Litteral* dollar(const Complexe& c1, const Complexe& c2) const;
};

class OperateurLogique : public OperationBinaire
{
public:
    QString str;
    OperateurLogique(Litteral& l1, Litteral& l2, QString c);
    virtual Litteral* getResult() const;
private:
    Litteral* egal(const Complexe& c1, const Complexe& c2) const;
    Litteral* egal(const Rationnel& r1, const Rationnel& r2) const;
    Litteral* diff(const Complexe& c1, const Complexe& c2) const;
    Litteral* diff(const Rationnel& r1, const Rationnel& r2) const ;
    Litteral* inf(const Complexe& c1, const Complexe& c2) const;
    Litteral* inf(const Rationnel& r1, const Rationnel& r2) const;
    Litteral* sup(const Complexe& c1, const Complexe& c2) const;
    Litteral* sup(const Rationnel& r1, const Rationnel& r2) const;
    Litteral* infeg(const Complexe& c1, const Complexe& c2) const;
    Litteral* infeg(const Rationnel& r1, const Rationnel& r2) const;
    Litteral* supeg(const Complexe& c1, const Complexe& c2) const;
    Litteral* supeg(const Rationnel& r1, const Rationnel& r2) const;
    Litteral* ET(const Rationnel& c1, const Rationnel& c2) const;
    Litteral* OU(const Rationnel& c1, const Rationnel& c2) const;

};

#endif // OPERATIONBINAIRE_H
