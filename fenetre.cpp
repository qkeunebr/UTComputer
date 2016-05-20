#include "fenetre.h"

Fenetre::Fenetre():son(true){

    this->resize(420, 280); //...

    QWidget *tabWidget = new QWidget;
    QTabWidget *tab = new QTabWidget(tabWidget);
 //   tabWidget->show();
    tab->setFixedSize(420, 280);

    QWidget *calc = new QWidget;
    tab->addTab(calc,"Calculatrice");
    calc->show();
    //------------- Panneau Calculatrice

    QVBoxLayout *vLayoutCalc = new QVBoxLayout;
    calc->setLayout(vLayoutCalc);

    QLineEdit* entree = new QLineEdit("");
    entree->show();
    vLayoutCalc->addWidget(entree);


/*       QWidget calcEntry;
    vLayoutCalc->addWidget(&calcEntry);
*/
    QHBoxLayout *hLayoutPad = new QHBoxLayout;
    vLayoutCalc->addLayout(hLayoutPad);

        // ------------ Chiffre
        QVBoxLayout *vLayoutNum  = new QVBoxLayout;
        hLayoutPad->addLayout(vLayoutNum);

        QHBoxLayout *hLayout123  = new QHBoxLayout;
        vLayoutNum->addLayout(hLayout123);
        QPushButton *b1 = new QPushButton("1");
        b1->show();
        hLayout123->addWidget(b1);
        QPushButton *b2 = new QPushButton("2");
        b2->show();
        hLayout123->addWidget(b2);
        QPushButton *b3 = new QPushButton("3");
        b3->show();
        hLayout123->addWidget(b3);

        QHBoxLayout *hLayout456  = new QHBoxLayout;
        vLayoutNum->addLayout(hLayout456);
        QPushButton *b4 = new QPushButton("4");
        b4->show();
        hLayout456->addWidget(b4);
        QPushButton *b5 = new QPushButton("5");
        b5->show();
        hLayout456->addWidget(b5);
        QPushButton *b6 = new QPushButton("6");
        b6->show();
        hLayout456->addWidget(b6);

        QHBoxLayout *hLayout789  = new QHBoxLayout;
        vLayoutNum->addLayout(hLayout789);
        QPushButton *b7 = new QPushButton("7");
        b7->show();
        hLayout789->addWidget(b7);
        QPushButton *b8 = new QPushButton("8");
        b8->show();
        hLayout789->addWidget(b8);
        QPushButton *b9 = new QPushButton("9");
        b9->show();
        hLayout789->addWidget(b9);

        QPushButton *b0 = new QPushButton("0");
        b0->show();
        vLayoutNum->addWidget(b0);

        // ----------- operation
        QVBoxLayout *vLayoutOpSigne  = new QVBoxLayout;
        hLayoutPad->addLayout(vLayoutOpSigne);

        QPushButton* bPlus = new QPushButton("+");
        bPlus->show();
        vLayoutOpSigne->addWidget(bPlus);
        QPushButton* bMoins = new QPushButton("-");
        bMoins->show();
        vLayoutOpSigne->addWidget(bMoins);
        QPushButton* bFois = new QPushButton("*");
        bFois->show();
        vLayoutOpSigne->addWidget(bFois);
        QPushButton* bDiv = new QPushButton("/");
        bDiv->show();
        vLayoutOpSigne->addWidget(bDiv);

        QVBoxLayout *vLayoutOpLettre  = new QVBoxLayout;
        hLayoutPad->addLayout(vLayoutOpLettre);

        QPushButton* bNeg = new QPushButton("NEG");
        bNeg->show();
        vLayoutOpLettre->addWidget(bNeg);
        QPushButton* bNum = new QPushButton("NUM");
        bNum->show();
        vLayoutOpLettre->addWidget(bNum);
        QPushButton* bDen = new QPushButton("DEN");
        bDen->show();
        vLayoutOpLettre->addWidget(bDen);
        QPushButton* bCompl = new QPushButton("$");
        bCompl->show();
        vLayoutOpLettre->addWidget(bCompl);
        QPushButton* bRe = new QPushButton("RE");
        bRe->show();
        vLayoutOpLettre->addWidget(bRe);
        QPushButton* bIm = new QPushButton("IM");
        bIm->show();
        vLayoutOpLettre->addWidget(bIm);

        QVBoxLayout *vLayoutOpLog  = new QVBoxLayout;
        hLayoutPad->addLayout(vLayoutOpLog);

        QPushButton* bEg = new QPushButton("=");
        bEg->show();
        vLayoutOpLog->addWidget(bEg);
        QPushButton* bNEg = new QPushButton("!=");
        bNEg->show();
        vLayoutOpLog->addWidget(bNEg);
        QPushButton* bEgSup = new QPushButton(">=");
        bEgSup->show();
        vLayoutOpLog->addWidget(bEgSup);
        QPushButton* bEgInf = new QPushButton("=<");
        bEgInf->show();
        vLayoutOpLog->addWidget(bEgInf);
        QPushButton* bInf = new QPushButton("<");
        bInf->show();
        vLayoutOpLog->addWidget(bInf);
        QPushButton* bSup = new QPushButton(">");
        bSup->show();
        vLayoutOpLog->addWidget(bSup);
        QPushButton* bAnd = new QPushButton("AND");
        bAnd->show();
        vLayoutOpLog->addWidget(bAnd);
        QPushButton* bOr = new QPushButton("OR");
        bOr->show();
        vLayoutOpLog->addWidget(bOr);
        QPushButton* bNot = new QPushButton("NOT");
        bNot->show();
        vLayoutOpLog->addWidget(bNot);

    //-------------------- FIN Panneau calculatrice

    QWidget* option = new QWidget;
    tab->addTab(option,"Option");

    //------------- Panneau option

    QVBoxLayout *vLayoutOption = new QVBoxLayout(option);

/*
    QCheckBox *checkClavier = new QCheckBox("Afficher clavier ");
    connect(checkClavier , SIGNAL(stateChanged(int)),this,SLOT(Fenetre::checkClavierStateChanged(int)));
    vLayoutOption->addWidget(checkClavier);

    QCheckBox *checkSon = new QCheckBox("Bip sonore");
    connect(checkSon , SIGNAL(stateChanged(int)),this,SLOT(Fenetre::checkSonStateChanged(int)));
    vLayoutOption->addWidget(checkSon);
*/
    //------------- FIN Panneau option

    QWidget *variable = new QWidget;
    tab->addTab(variable, "Variable");

    //-------------- Panneau gestion des variables
    // Une liste des variable, je pense qu'on peux les mettre sous la forme -> Nom : (un QLabel) Valeur (Un QLineEdit) X (un QPushButton pour la supprimer) et un QPushButto pour valider le changement de valeur
    // Il faudra peut être avoir en variable des liste de Qlabel et de Qlineedit pour les modifier à l'aide de slots quand l'utilisateur change les variables

    QVBoxLayout *vLayoutListVar = new QVBoxLayout(variable);

    //Boucle for qui parcours les variables




    //-------------- FIN Panneau gestion des variables


    QWidget *programme = new QWidget;
    tab->addTab(programme, "Programme");

    //-------------- Panneau gestion des programmes
    //Je ne sais pas encore comment on les présente, peut être juste avec un QLabel qui contient le nom suivi d'un QTextEdit qui contient le programme

    //-------------- FIN Panneau gestion des programmes


    setCentralWidget(tabWidget);
}
