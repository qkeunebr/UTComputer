#ifndef VARIABLE_H
#define VARIABLE_H
#include "litteral.h"
#include <QVector>
#include <QString>

class Variable : public Litteral {
    QString nom;
    Litteral* valeur;
    Variable(QString n, Litteral& l):nom(n),valeur(&l){}
    friend class VariableManager;
public :
    Litteral& getValue() const {return *valeur;}
    const QString& getName() const {return nom;}
    const QString toString() const { return QString(nom+" : "+valeur->toString());}
    bool operator== (const Variable& var2){return this->getName() == var2.getName();}
    Variable():nom(QString("")){}
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
    Programme(QString n, QString l, int lim):nom(n),valeur(l),limiteAffichage(lim){}
    friend class ProgrammeManager;
public :
    const QString& getValue() const {return valeur;}
    const QString& getName() const {return nom;}
    const QString toString() const;
    bool operator== (const Programme& var2){return this->getName() == var2.getName();}
    Programme():nom(""),valeur(""),limiteAffichage(9){}
};

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
        Programme& addProgramme(QString n, QString l, int lim);
        void removeProgramme(Programme& e);
        bool contains(QString e);
        QVector<Programme>& getList(){return prog;}
        QString getProgramme(QString name);
        static ProgrammeManager& getInstance();
        static void libererInstance();
};
#endif // VARIABLE_H
