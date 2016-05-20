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

class Fenetre : public QMainWindow {
    //Un attribut qui contient l'application/l'objet auquelle on fait appel

    //Attribut affichage clavier
//    QWidget calcButton;
    //Attribut bip sonore
    bool son;
    /*
public slots :
    void checkClavierStateChanged(int state){
        if(state)   calcButton.show();
        else    calcButton.hide();
    }

    void checkSonStateChanged(int state){
        son = state;
    }
    */

public :

    Fenetre();


};


#endif // FENETRE_H
