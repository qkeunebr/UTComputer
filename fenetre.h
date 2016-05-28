#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QCheckBox>
#include <QWidget>
#include <iostream>
#include <windows.h>
#include <QTableWidget>
#include <QHeaderView>
#include "controller.h"
#include "litteral.h"


class Fenetre : public QMainWindow {
Q_OBJECT
    Controller* cont;
    QLineEdit* entree;
    //Un attribut qui contient l'application/l'objet auquelle on fait appel

    //Attribut affichage clavier
    QWidget* calcButton;
    //Attribut bip sonore
    bool son;

    QLineEdit* message;
    QTableWidget* vuePile;
    QLineEdit* commande;
    QVBoxLayout* couche;
    Controller* controleur;
public slots :
    void checkClavierStateChanged(int state){
        if(state)   calcButton->show();
        else    calcButton->hide();
    }

    void checkSonStateChanged(int state){
        son = state;
    }

    void pushB1();
    void pushB2();
    void pushB3();
    void pushB4();
    void pushB5();
    void pushB6();
    void pushB7();
    void pushB8();
    void pushB9();
    void pushB0();
    void pushBPlus();
    void pushBMoins();
    void pushBFois();
    void pushBDiv();
    void pushBNeg();
    void pushBNum();
    void pushBDen();
    void pushBCompl();
    void pushBRe();
    void pushBIm();
    void pushBEg();
    void pushBNEg();
    void pushBEgSup();
    void pushBEgInf();
    void pushBSup();
    void pushBInf();
    void pushBOr();
    void pushBAnd();
    void pushBNot();
public :

    Fenetre();
};


#endif // FENETRE_H
