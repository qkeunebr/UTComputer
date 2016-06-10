#ifndef FENETRE_H
#define FENETRE_H

#include <algorithm>
#include <QMainWindow>
#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QWidget>
#include <iostream>
#include <exception>
//#include <windows.h>
#include <QHeaderView>
#include <QCloseEvent>
#include <QSessionManager>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QTextStream>
#include <QDesktopWidget>
#include <QLabel>
#include "controller.h"
#include "litteral.h"
#include "variable.h"


class Fenetre : public QMainWindow {
Q_OBJECT
    Controller* cont;


    //Attribut affichage clavier
    QWidget* calcButton;
    //Attribut bip sonore
    bool son;
    
    QTabWidget* tab;


    QLineEdit* message;
//    QTableWidget* vuePile;
    QLineEdit* vuePile;
    QLineEdit* commande;
    QVBoxLayout* couche;

    QVector<QCheckBox*> listVarCheck;
    QVector<QLineEdit*> listVarName;
    QVector<QLineEdit*> listVarValue;

    QVector<QCheckBox*> listProgCheck;
    QVector<QLineEdit*> listProgName;
    QVector<QLineEdit*> listProgValue;

    QLineEdit *entNomVar ;
    QLineEdit *entValueVar;

    QLineEdit *entNomProg ;
    QLineEdit *entValueProg;

    QWidget* createVarView();
    QWidget* createProgView();
public slots :
    void checkClavierStateChanged(int state){
        if(state)   calcButton->show();
        else    calcButton->hide();
    }

    void checkSonStateChanged(int state){
        son = state;
    }
    void refresh();
    void getNextCommande();
    void setCommande(QString s);
    
    void setActiveTab(QString tab);


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
    void pushBDiff();
    void pushBEgSup();
    void pushBEgInf();
    void pushBSup();
    void pushBInf();
    void pushBOr();
    void pushBAnd();
    void pushBNot();

    void pushBEntree();
    void pushBSpace();
    void pushBCorr();
    void pushBEdit();
    void pushBEval();
    void pushBForget();
    void pushBSto();
    void pushBIft();
    void pushBDup();
    void pushBDrop();
    void pushBSwap();
    void pushBLastOp();
    void pushBLastArgs();
    void pushBUndo();
    void pushBRedo();
    void pushBClear();

    void pushBCreerVar();
    void pushBCreerProg();
    void pushBSupVar();
    void pushBSupProg();
    void pushBModVar();
    void pushBModProg();
public :

    Fenetre();
    void loadFile(const QString &filename);
protected :
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void documentWasModified();
//    void commitData(QSessionManager &);

private:
    void createActions();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QString curFile;

};


#endif // FENETRE_H
