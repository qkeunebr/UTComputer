#include "fenetre.h"

Fenetre::Fenetre():son(true){

    this->resize(420, 280); //...

    cont = Controller::getController();

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

    entree = new QLineEdit("");
    entree->show();
    vLayoutCalc->addWidget(entree);

    // ----------------- Pile
    controleur = Controller::getController();

    message = new QLineEdit();
    vuePile = new QTableWidget();
    commande = new QLineEdit();
    couche = new QVBoxLayout();

    //message non modifiable + couleurs
//    message->setPlaceholderText("PlaceHolder");
    message->setReadOnly(true);
    QPalette palette;
    palette.setColor(QPalette::Base,Qt::blue);
    palette.setColor(QPalette::Text,Qt::yellow);
    message->setPalette(palette);

    //Pile non modifiable + Aspect
    vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vuePile->setStyleSheet("background: darkcyan; color: white");
    vuePile->verticalHeader()->setStyleSheet("color:black");
    vuePile->horizontalHeader()->setVisible(false);
    vuePile->horizontalHeader()->setStretchLastSection(true);

    //A changer pour afficher plus de ligne
    //vuePile->setRowCount(pile->getNbItemsToAffiche());

    QStringList numberList;
    for(unsigned int i = controleur->getPile()->getNbItemsToAffiche();i>0;i--)
    {
        QString str = QString::number(i);
        str+=" :";
        numberList<<str;

        vuePile->setItem(i-1,0,new QTableWidgetItem(""));
    }

    vuePile->setVerticalHeaderLabels(numberList);
    vuePile->setFixedHeight(controleur->getPile()->getNbItemsToAffiche()*vuePile->rowHeight(0)+2);

/*
    vuePile->resizeRowsToContents();

    int height = (vuePile->model()->rowCount() - 1) + vuePile->horizontalHeader()->height();
    for(int row = 0; row < vuePile->model()->rowCount(); row++)
    height = height + vuePile->rowHeight(row);
    vuePile->setMaximumHeight(height);
*/

    QObject::connect(controleur->getPile(), SLOT(modificationEtat()), this, SLOT(refresh()));
    QObject::connect(commande, SIGNAL(returnPressed()), this, SLOT(getNextCommande()));

    couche->addWidget(message);
    couche->addWidget(vuePile);
    couche->addWidget(commande);
    message->show();
    vuePile->show();
    commande->show();

    controleur->getPile()->setMessage("Bienvenue");
    commande->setFocus(Qt::OtherFocusReason);

    vLayoutCalc->addLayout(couche);
    // ---------------------------------------------

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
        connect(b1,SIGNAL(clicked()), this, SLOT(pushB1()));

        QPushButton *b2 = new QPushButton("2");
        b2->show();
        hLayout123->addWidget(b2);
        connect(b2,SIGNAL(clicked()), this, SLOT(pushB2()));

        QPushButton *b3 = new QPushButton("3");
        b3->show();
        hLayout123->addWidget(b3);
        connect(b3,SIGNAL(clicked()), this, SLOT(pushB3()));

        QHBoxLayout *hLayout456  = new QHBoxLayout;
        vLayoutNum->addLayout(hLayout456);
        QPushButton *b4 = new QPushButton("4");
        b4->show();
        hLayout456->addWidget(b4);
        connect(b4,SIGNAL(clicked()), this, SLOT(pushB4()));

        QPushButton *b5 = new QPushButton("5");
        b5->show();
        hLayout456->addWidget(b5);
        connect(b5,SIGNAL(clicked()), this, SLOT(pushB5()));

        QPushButton *b6 = new QPushButton("6");
        b6->show();
        hLayout456->addWidget(b6);
        connect(b6,SIGNAL(clicked()), this, SLOT(pushB6()));

        QHBoxLayout *hLayout789  = new QHBoxLayout;
        vLayoutNum->addLayout(hLayout789);
        QPushButton *b7 = new QPushButton("7");
        b7->show();
        hLayout789->addWidget(b7);
        connect(b7,SIGNAL(clicked()), this, SLOT(pushB7()));

        QPushButton *b8 = new QPushButton("8");
        b8->show();
        hLayout789->addWidget(b8);
        connect(b8,SIGNAL(clicked()), this, SLOT(pushB8()));

        QPushButton *b9 = new QPushButton("9");
        b9->show();
        hLayout789->addWidget(b9);
        connect(b9,SIGNAL(clicked()), this, SLOT(pushB9()));

        QPushButton *b0 = new QPushButton("0");
        b0->show();
        vLayoutNum->addWidget(b0);
        connect(b0,SIGNAL(clicked()), this, SLOT(pushB0()));

        // ----------- operation
        QVBoxLayout *vLayoutOpSigne  = new QVBoxLayout;
        hLayoutPad->addLayout(vLayoutOpSigne);

        QPushButton* bPlus = new QPushButton("+");
        bPlus->show();
        vLayoutOpSigne->addWidget(bPlus);
        connect(bPlus,SIGNAL(clicked()), this, SLOT(pushBPlus()));

        QPushButton* bMoins = new QPushButton("-");
        bMoins->show();
        vLayoutOpSigne->addWidget(bMoins);
        connect(bMoins,SIGNAL(clicked()), this, SLOT(pushBMoins()));

        QPushButton* bFois = new QPushButton("*");
        bFois->show();
        vLayoutOpSigne->addWidget(bFois);
        connect(bFois,SIGNAL(clicked()), this, SLOT(pushBFois()));

        QPushButton* bDiv = new QPushButton("/");
        bDiv->show();
        vLayoutOpSigne->addWidget(bDiv);
        connect(bDiv,SIGNAL(clicked()), this, SLOT(pushBDiv()));

        QVBoxLayout *vLayoutOpLettre  = new QVBoxLayout;
        hLayoutPad->addLayout(vLayoutOpLettre);

        QPushButton* bNeg = new QPushButton("NEG");
        bNeg->show();
        vLayoutOpLettre->addWidget(bNeg);
        connect(bNeg,SIGNAL(clicked()), this, SLOT(pushBNeg()));

        QPushButton* bNum = new QPushButton("NUM");
        bNum->show();
        vLayoutOpLettre->addWidget(bNum);
        connect(bNum,SIGNAL(clicked()), this, SLOT(pushBNum()));

        QPushButton* bDen = new QPushButton("DEN");
        bDen->show();
        vLayoutOpLettre->addWidget(bDen);
        connect(bDen,SIGNAL(clicked()), this, SLOT(pushBDen()));

        QPushButton* bCompl = new QPushButton("$");
        bCompl->show();
        vLayoutOpLettre->addWidget(bCompl);
        connect(bCompl,SIGNAL(clicked()), this, SLOT(pushBCompl()));

        QPushButton* bRe = new QPushButton("RE");
        bRe->show();
        vLayoutOpLettre->addWidget(bRe);
        connect(bRe,SIGNAL(clicked()), this, SLOT(pushBRe()));

        QPushButton* bIm = new QPushButton("IM");
        bIm->show();
        vLayoutOpLettre->addWidget(bIm);
        connect(bIm,SIGNAL(clicked()), this, SLOT(pushBIm()));

        QVBoxLayout *vLayoutOpLog  = new QVBoxLayout;
        hLayoutPad->addLayout(vLayoutOpLog);

        QPushButton* bEg = new QPushButton("=");
        bEg->show();
        vLayoutOpLog->addWidget(bEg);
        connect(bEg,SIGNAL(clicked()), this, SLOT(pushBEg()));

        QPushButton* bNEg = new QPushButton("!=");
        bNEg->show();
        vLayoutOpLog->addWidget(bNEg);
        connect(bNEg,SIGNAL(clicked()), this, SLOT(pushBNeg()));

        QPushButton* bEgSup = new QPushButton(">=");
        bEgSup->show();
        vLayoutOpLog->addWidget(bEgSup);
        connect(bEgSup,SIGNAL(clicked()), this, SLOT(pushBEgSup()));

        QPushButton* bEgInf = new QPushButton("=<");
        bEgInf->show();
        vLayoutOpLog->addWidget(bEgInf);
        connect(bEgInf,SIGNAL(clicked()), this, SLOT(pushBEgInf()));

        QPushButton* bInf = new QPushButton("<");
        bInf->show();
        vLayoutOpLog->addWidget(bInf);
        connect(bInf,SIGNAL(clicked()), this, SLOT(pushBInf()));

        QPushButton* bSup = new QPushButton(">");
        bSup->show();
        vLayoutOpLog->addWidget(bSup);
        connect(bSup,SIGNAL(clicked()), this, SLOT(pushBSup()));

        QPushButton* bAnd = new QPushButton("AND");
        bAnd->show();
        vLayoutOpLog->addWidget(bAnd);
        connect(bAnd,SIGNAL(clicked()), this, SLOT(pushBAnd()));

        QPushButton* bOr = new QPushButton("OR");
        bOr->show();
        vLayoutOpLog->addWidget(bOr);
        connect(bOr,SIGNAL(clicked()), this, SLOT(pushBOr()));

        QPushButton* bNot = new QPushButton("NOT");
        bNot->show();
        vLayoutOpLog->addWidget(bNot);
        connect(bNot,SIGNAL(clicked()), this, SLOT(pushBNot()));

    //-------------------- FIN Panneau calculatrice

    QWidget* option = new QWidget;
    tab->addTab(option,"Option");

    //------------- Panneau option

    QVBoxLayout *vLayoutOption = new QVBoxLayout();
    option->setLayout(vLayoutOption);

    QCheckBox *checkClavier = new QCheckBox("Afficher clavier ");
    checkClavier->setChecked(true);
    connect(checkClavier , SIGNAL(stateChanged(int)),this,SLOT(checkClavierStateChanged(int)));
    vLayoutOption->addWidget(checkClavier);

    QCheckBox *checkSon = new QCheckBox("Bip sonore");
    connect(checkSon , SIGNAL(stateChanged(int)),this,SLOT(checkSonStateChanged(int)));
    vLayoutOption->addWidget(checkSon);

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

void Fenetre::pushB1(){
    Fenetre::entree->setText(Fenetre::entree->text()+"1");
    Beep(523,250);

}

void Fenetre::pushB2(){
    Fenetre::entree->setText(Fenetre::entree->text()+"2");
    Beep(523,250);
}

void Fenetre::pushB3(){
    Fenetre::entree->setText(Fenetre::entree->text()+"3");
    Beep(523,250);
}

void Fenetre::pushB4(){
    Fenetre::entree->setText(Fenetre::entree->text()+"4");
    Beep(523,250);
}

void Fenetre::pushB5(){
    Fenetre::entree->setText(Fenetre::entree->text()+"5");
    Beep(523,250);
}

void Fenetre::pushB6(){
    Fenetre::entree->setText(Fenetre::entree->text()+"6");
    Beep(523,250);
}

void Fenetre::pushB7(){
    Fenetre::entree->setText(Fenetre::entree->text()+"7");
    Beep(523,250);
}

void Fenetre::pushB8(){
    Fenetre::entree->setText(Fenetre::entree->text()+"8");
    Beep(523,250);
}

void Fenetre::pushB9(){
    Fenetre::entree->setText(Fenetre::entree->text()+"9");
    Beep(523,250);
}

void Fenetre::pushB0(){
    Fenetre::entree->setText(Fenetre::entree->text()+"0");
    Beep(523,250);
}

void Fenetre::pushBPlus(){
    Fenetre::entree->setText(Fenetre::entree->text()+"+");
    Beep(523,250);
}

void Fenetre::pushBMoins(){
    Fenetre::entree->setText(Fenetre::entree->text()+"-");
    Beep(523,250);
}

void Fenetre::pushBFois(){
    Fenetre::entree->setText(Fenetre::entree->text()+"*");
    Beep(523,250);
}

void Fenetre::pushBDiv(){
    Fenetre::entree->setText(Fenetre::entree->text()+"/");
    Beep(523,250);
}

void Fenetre::pushBNeg(){
    Fenetre::entree->setText(Fenetre::entree->text()+"");
    Beep(523,250);
}

void Fenetre::pushBNum(){
    Fenetre::entree->setText(Fenetre::entree->text()+"");
    Beep(523,250);
}

void Fenetre::pushBDen(){
    Fenetre::entree->setText(Fenetre::entree->text()+"");
    Beep(523,250);
}

void Fenetre::pushBCompl(){
    Fenetre::entree->setText(Fenetre::entree->text()+"");
    Beep(523,250);
}

void Fenetre::pushBRe(){
    Fenetre::entree->setText(Fenetre::entree->text()+"");
    Beep(523,250);
}

void Fenetre::pushBIm(){
    Fenetre::entree->setText(Fenetre::entree->text()+"");
    Beep(523,250);
}

void Fenetre::pushBEg(){
    Fenetre::entree->setText(Fenetre::entree->text()+"==");
    Beep(523,250);
}

void Fenetre::pushBNEg(){
    Fenetre::entree->setText(Fenetre::entree->text()+"!=");
    Beep(523,250);
}

void Fenetre::pushBEgSup(){
    Fenetre::entree->setText(Fenetre::entree->text()+"=>");
    Beep(523,250);
}

void Fenetre::pushBEgInf(){
    Fenetre::entree->setText(Fenetre::entree->text()+"=<");
    Beep(523,250);
}

void Fenetre::pushBInf(){
    Fenetre::entree->setText(Fenetre::entree->text()+"<");
    Beep(523,250);
}

void Fenetre::pushBSup(){
    Fenetre::entree->setText(Fenetre::entree->text()+">");
    Beep(523,250);
}

void Fenetre::pushBAnd(){
    Fenetre::entree->setText(Fenetre::entree->text()+"&&");
    Beep(523,250);
}

void Fenetre::pushBOr(){
    Fenetre::entree->setText(Fenetre::entree->text()+"||");
    Beep(523,250);
}

void Fenetre::pushBNot(){
    Fenetre::entree->setText(Fenetre::entree->text()+"");
    Beep(523,250);
}
