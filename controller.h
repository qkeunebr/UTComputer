#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "litteral.h"
#include <QString>
#include <QObject>
#include <QTextStream>

class Pile : public QObject {
    Q_OBJECT

    Litteral* items;
    unsigned int nb;
    unsigned int nbMax;
    QString message;
    void agrandissementCapacite();
    unsigned int nbAffiche;
public:
    Pile():items(nullptr),nb(0),nbMax(0),message(""),nbAffiche(4){}
    ~Pile();
    void push(Litteral& e);
    void pop();
    bool estVide() const { return nb==0; }
    unsigned int taille() const { return nb; }
    void affiche(QTextStream& f) const;
    Litteral& top() const;
    void setNbItemsToAffiche(unsigned int n) { nb=n; }
    unsigned int getNbItemsToAffiche() const { return nbAffiche; }
    void setMessage(const QString& m) { message=m; modificationEtat(); }
    QString getMessage() const { return message; }
    class iterator {
        Litteral* current;
        iterator(Litteral* u):current(u){}
        friend class Pile;
    public:
        iterator():current(nullptr){}
        Litteral& operator*() const { return *current; }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ --current; return *this; }
    };
    iterator begin() { return iterator(items+nb-1); }
    iterator end() { return iterator(items-1); }

    class const_iterator {
        Litteral* current;
        const_iterator(Litteral* u):current(u){}
        friend class Pile;
    public:
        const_iterator():current(nullptr){}
        const Litteral& operator*() const { return *current; }
        bool operator!=(const_iterator it) const { return current!=it.current; }
        const_iterator& operator++(){ --current; return *this; }
    };
    const_iterator begin() const { return const_iterator(items+nb-1); }
    const_iterator end() const { return const_iterator(items-1); }

signals:
    void modificationEtat();
};

class Controller{
    static Controller *inst;
    Pile* pile;

    Controller(){
        pile = new Pile();
    }

public :
    static Controller* getController(){
        if(Controller::inst==nullptr) Controller::inst = new Controller();
        return Controller::inst;
    }

    Pile* getPile(){
        return pile;
    }
};

#endif // CONTROLLER_H
