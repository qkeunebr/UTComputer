#ifndef VARIABLE_H
#define VARIABLE_H
#include "litteral.h"
#include <QVector>
#include <QString>

/**
 * \file variable.h
 * \brief Variable et Programme
 * \author Robin Trouvé
 * \version 1.0
 * \date 3 juin 2016
 *
 * \details Contient les classes \class Variable et \class Programme que hérite de \class Litteral litteral.h ainsi que
 * leurs managers.
 *
 */


class Variable : public Litteral {
    QString nom;
    Litteral* valeur;
    Variable(QString n, Litteral& l):nom(n),valeur(&l){}
    friend class VariableManager;
public :
    Litteral& getValue() const {return *valeur;}
    const QString& getName() const {return nom;}
    const QString toString() const { return QString(nom);}
    bool operator== (const Variable& var2){return this->getName() == var2.getName();}
    Variable():nom(QString("")){}
    Variable(QString n):nom(n){}
};

class VariableManager{
    QVector<Variable> var;

    struct Handler{
            VariableManager* instance;
            Handler():instance(nullptr){}
            // destructeur appelé à la fin du programme
            ~Handler(){ delete instance; }
        };
        static Handler handler;
public :
        Variable& addVariable(QString n, Litteral& l);
        Variable& addVariable(QString n);
        void removeVariable(Variable& e);
        bool contains(Variable& e);
        bool contains(QString e);
        QVector<Variable>& getList(){return var;}
        Variable& getVariable(QString name);
        static VariableManager& getInstance();
        static void libererInstance();

};

class Programme : public Litteral {
    QString nom;
    QString valeur;
    int limiteAffichage;
    Programme(QString n, QString l, int lim=10):nom(n),valeur(l),limiteAffichage(lim){}
    friend class ProgrammeManager;
public :
    const QString& getValue() const {return valeur;}
    const QString& getName() const {return nom;}
    const QString toString() const;
    const QString aff() const;
    bool operator== (const Programme& var2){return this->getName() == var2.getName();}
    Programme():nom(""),valeur(""),limiteAffichage(9){}
};

/**
 *
 *
 */
class ProgrammeManager{
    QVector<Programme> prog;

    struct Handler{
            ProgrammeManager* instance;
            Handler():instance(nullptr){}
            // destructeur appelé à la fin du programme
            ~Handler(){ delete instance; }
        };
        static Handler handler;
public :
        Programme& addProgramme(QString n, QString l);
        void removeProgramme(Programme& e);
        bool contains(QString e);
        QVector<Programme>& getList(){return prog;}
        Programme& getProgramme(QString name);
        static ProgrammeManager& getInstance();
        static void libererInstance();
};
#endif // VARIABLE_H
