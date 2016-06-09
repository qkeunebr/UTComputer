#include "fenetre.h"

/**
 * \fn  Fenetre::Fenetre()
 * \brief  Constructeur de \class Fenetre
 *
 */
Fenetre::Fenetre():son(true){

    createActions();
    createStatusBar();

    readSettings();
/*
    QGuiApplication::setFallbackSessionManagementEnabled(false);
    connect(qApp, &QGuiApplication::commitDataRequest,
            this, &Fenetre::commitData);
*/
    this->resize(620, 550); //...

    cont = new Controller;

    QWidget *tabWidget = new QWidget;
    QTabWidget *tab = new QTabWidget(tabWidget);
 //   tabWidget->show();
    tab->setFixedSize(620, 480);

    QWidget *calc = new QWidget;
    tab->addTab(calc,"Calculatrice");
    calc->show();
    //------------- Panneau Calculatrice

    QVBoxLayout *vLayoutCalc = new QVBoxLayout;
    calc->setLayout(vLayoutCalc);

    message = new QLineEdit("");

    // ----------------- Pile
//    vuePile = new QTableWidget();
    vuePile = new QLineEdit();
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
    vuePile->setReadOnly(true);
//    vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vuePile->setStyleSheet("background: darkcyan; color: white");
//    vuePile->verticalHeader()->setVisible(false);
//    vuePile->verticalHeader()->setStyleSheet("color:black");
//    vuePile->horizontalHeader()->setVisible(false);
//    vuePile->horizontalHeader()->setStretchLastSection(true);

    //A changer pour afficher plus de ligne
//    vuePile->setRowCount(cont->getPile()->getNbItemsToAffiche());
//    vuePile->setColumnCount(2);

//    QStringList numberList;
/*    for(unsigned int i = cont->getPile()->getNbItemsToAffiche();i>0;i--)
    {
        QString str = QString::number(i);
        str+=" :";
//        numberList<<str;

        vuePile->setItem(i-1,0,new QTableWidgetItem(str));
    }

//    vuePile->setVerticalHeaderLabels(numberList);
    vuePile->setFixedHeight(30*cont->getPile()->getNbItemsToAffiche()/*vuePile->rowHeight(0)+2);
*/
    vuePile->setText(cont->getPile()->getStackAff());
/*
    vuePile->resizeRowsToContents();
    int height = (vuePile->model()->rowCount() - 1) + vuePile->horizontalHeader()->height();
    for(int row = 0; row < vuePile->model()->rowCount(); row++)
    height = height + vuePile->rowHeight(row);
    vuePile->setMaximumHeight(height);
*/

    connect(cont->getPile(), SIGNAL(modificationEtat()), this, SLOT(refresh()));
    connect(commande, SIGNAL(returnPressed()), this, SLOT(getNextCommande()));

    couche->addWidget(message);
    couche->addWidget(vuePile);
    couche->addWidget(commande);
    message->show();
    vuePile->show();
    commande->show();

    cont->getPile()->setMessage("Bienvenue");
    commande->setFocus(Qt::OtherFocusReason);
    connect(cont,SIGNAL(changeCommande(QString)),this,SLOT(setCommande(QString)));

    vLayoutCalc->addLayout(couche);
    // ---------------------------------------------

/*       QWidget calcEntry;
    vLayoutCalc->addWidget(&calcEntry);
*/
    QHBoxLayout *hLayoutPad = new QHBoxLayout;
        calcButton = new QWidget();
    vLayoutCalc->addWidget(calcButton);
    calcButton->setLayout(hLayoutPad);

        // ------------ Systeme
    QVBoxLayout *vLayoutSys = new QVBoxLayout;
    hLayoutPad->addLayout(vLayoutSys);

    QPushButton* bEntree = new QPushButton("Entree");
    bEntree->show();
    vLayoutSys->addWidget(bEntree);
    connect(bEntree,SIGNAL(clicked()), this, SLOT(pushBEntree()));

    QPushButton* bSpace = new QPushButton("Espace");
    bSpace->show();
    vLayoutSys->addWidget(bSpace);
    connect(bSpace,SIGNAL(clicked()), this, SLOT(pushBSpace()));

    QPushButton* bCorr = new QPushButton("Correction");
    bCorr->show();
    vLayoutSys->addWidget(bCorr);
    connect(bCorr,SIGNAL(clicked()), this, SLOT(pushBCorr()));

    QPushButton* bEdit = new QPushButton("Edit");
    bEdit->show();
    vLayoutSys->addWidget(bEdit);
    connect(bEdit,SIGNAL(clicked()), this, SLOT(pushBEdit()));

    QPushButton* bEval = new QPushButton("Eval");
    bEval->show();
    vLayoutSys->addWidget(bEval);
    connect(bEval,SIGNAL(clicked()), this, SLOT(pushBEval()));

    QPushButton* bForget = new QPushButton("Forget");
    bForget->show();
    vLayoutSys->addWidget(bForget);
    connect(bForget,SIGNAL(clicked()), this, SLOT(pushBForget()));

    QPushButton* bSto = new QPushButton("Sto");
    bSto->show();
    vLayoutSys->addWidget(bSto);
    connect(bSto,SIGNAL(clicked()), this, SLOT(pushBSto()));

    QPushButton* bIft = new QPushButton("Ift");
    bIft->show();
    vLayoutSys->addWidget(bIft);
    connect(bIft,SIGNAL(clicked()), this, SLOT(pushBIft()));

    QPushButton* bDup = new QPushButton("Dup");
    bDup->show();
    vLayoutSys->addWidget(bDup);
    connect(bDup,SIGNAL(clicked()), this, SLOT(pushBDup()));

    QPushButton* bDrop = new QPushButton("Drop");
    bDrop->show();
    vLayoutSys->addWidget(bDrop);
    connect(bDrop,SIGNAL(clicked()), this, SLOT(pushBDrop()));

    QPushButton* bSwap = new QPushButton("Swap");
    bSwap->show();
    vLayoutSys->addWidget(bSwap);
    connect(bSwap,SIGNAL(clicked()), this, SLOT(pushBSwap()));

    QPushButton* bLastOp = new QPushButton("LastOp");
    bLastOp->show();
    vLayoutSys->addWidget(bLastOp);
    connect(bLastOp,SIGNAL(clicked()), this, SLOT(pushBLastOp()));

    QPushButton* bLastArgs = new QPushButton("LastArgs");
    bLastArgs->show();
    vLayoutSys->addWidget(bLastArgs);
    connect(bLastArgs,SIGNAL(clicked()), this, SLOT(pushBLastArgs()));

    QPushButton* bUndo = new QPushButton("Undo");
    bUndo->show();
    vLayoutSys->addWidget(bUndo);
    connect(bUndo,SIGNAL(clicked()), this, SLOT(pushBUndo()));

    QPushButton* bRedo = new QPushButton("Redo");
    bRedo->show();
    vLayoutSys->addWidget(bRedo);
    connect(bRedo,SIGNAL(clicked()), this, SLOT(pushBRedo()));

    QPushButton* bClear = new QPushButton("Clear");
    bClear->show();
    vLayoutSys->addWidget(bClear);
    connect(bClear,SIGNAL(clicked()), this, SLOT(pushBClear()));


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

        QPushButton* bDiff = new QPushButton("!=");
        bDiff->show();
        vLayoutOpLog->addWidget(bDiff);
        connect(bDiff,SIGNAL(clicked()), this, SLOT(pushBDiff()));

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
    checkSon->setChecked(true);
    connect(checkSon , SIGNAL(stateChanged(int)),this,SLOT(checkSonStateChanged(int)));
    vLayoutOption->addWidget(checkSon);

    //------------- FIN Panneau option


    QWidget *variable = createVarView();
    tab->addTab(variable, "Variable");


    //-------------- Panneau gestion des variables
    // Une liste des variable, je pense qu'on peux les mettre sous la forme -> Nom : (un QLabel) Valeur (Un QLineEdit) X (un QPushButton pour la supprimer) et un QPushButto pour valider le changement de valeur
    // Il faudra peut être avoir en variable des liste de Qlabel et de Qlineedit pour les modifier à l'aide de slots quand l'utilisateur change les variables


    //Boucle for qui parcours les variables



    //-------------- FIN Panneau gestion des variables


    QWidget *programme = createProgView();
    tab->addTab(programme, "Programme");

    //-------------- Panneau gestion des programmes
    //Je ne sais pas encore comment on les présente, peut être juste avec un QLabel qui contient le nom suivi d'un QTextEdit qui contient le programme

    //-------------- FIN Panneau gestion des programmes


    setCentralWidget(tabWidget);
}

QWidget* Fenetre::createVarView(){
    QWidget *variable = new QWidget;
    QVBoxLayout *vLayoutListVar = new QVBoxLayout;
    QVector<QVBoxLayout*> listVar;
    VariableManager var = VariableManager::getInstance();

    for(QVector<Variable>::iterator it = var.getList().begin(); it!=var.getList().end(); ++it){
        QVBoxLayout *temp = new QVBoxLayout;
        Variable contenu = *it;

        QLabel *nom = new QLabel(QString("Nom : "));
        QLineEdit *entNom = new QLineEdit(contenu.getName());
        QLabel *value = new QLabel(QString("Valeur : "));
        QLineEdit *entValue = new QLineEdit(contenu.getValue().toString());
        QCheckBox *select = new QCheckBox("Sélectionner");

        listVarCheck.append(select);
        listVarName.append(entNom);
        listVarValue.append(entValue);

        select->setChecked(false);
//        connect(select , SIGNAL(stateChanged(int)),this,SLOT(checkClavierStateChanged(int)));

        temp->addWidget(nom);
        temp->addWidget(entNom);
        temp->addWidget(value);
        temp->addWidget(entValue);
        temp->addWidget(select);

        listVar.append(temp);

    }

    for(int i=0; i<listVar.size(); i++)
        vLayoutListVar->addLayout(listVar.at(0));

    QPushButton* BMod = new QPushButton("Modifer la sélection");
    BMod->show();
    vLayoutListVar->addWidget(BMod);
    connect(BMod,SIGNAL(clicked()), this, SLOT(pushBModVar()));

    QPushButton* BSup = new QPushButton("Supprimer la sélection");
    BSup->show();
    vLayoutListVar->addWidget(BSup);
    connect(BSup,SIGNAL(clicked()), this, SLOT(pushBSupVar()));

    QLabel *nom = new QLabel(QString("Nom : "));
    entNomVar = new QLineEdit();
    QLabel *value = new QLabel(QString("Valeur : "));
    entValueVar = new QLineEdit();

    vLayoutListVar->addWidget(nom);
    vLayoutListVar->addWidget(entNomVar);
    vLayoutListVar->addWidget(value);
    vLayoutListVar->addWidget(entValueVar);

    QPushButton* BCreer = new QPushButton("Créer");
    BCreer->show();
    vLayoutListVar->addWidget(BCreer);
    connect(BCreer,SIGNAL(clicked()), this, SLOT(pushBCreerVar()));

    variable->setLayout(vLayoutListVar);
    return variable;
}

QWidget* Fenetre::createProgView(){
    QWidget *programme = new QWidget;
    QVBoxLayout *vLayoutListProg = new QVBoxLayout;
    QVector<QVBoxLayout*> listProg;
    ProgrammeManager prog = ProgrammeManager::getInstance();

    for(QVector<Programme>::iterator it = prog.getList().begin(); it!=prog.getList().end(); ++it){
        QVBoxLayout *temp = new QVBoxLayout;
        Programme contenu = *it;

        QLabel *nom = new QLabel(QString("Nom : "));
        QLineEdit *entNom = new QLineEdit(contenu.getName());
        QLabel *value = new QLabel(QString("Valeur : "));
        QLineEdit *entValue = new QLineEdit(contenu.getValue());
        QCheckBox *select = new QCheckBox("Sélectionner");

        listProgCheck.append(select);
        listProgName.append(entNom);
        listProgValue.append(entValue);

        select->setChecked(false);
//        connect(select , SIGNAL(stateChanged(int)),this,SLOT(checkClavierStateChanged(int)));

        temp->addWidget(nom);
        temp->addWidget(entNom);
        temp->addWidget(value);
        temp->addWidget(entValue);
        temp->addWidget(select);

        listProg.append(temp);

    }

    for(int i=0; i<listProg.size(); i++)
        vLayoutListProg->addLayout(listProg.at(0));

    QPushButton* BMod = new QPushButton("Modifer la sélection");
    BMod->show();
    vLayoutListProg->addWidget(BMod);
    connect(BMod,SIGNAL(clicked()), this, SLOT(pushBModProg()));

    QPushButton* BSup = new QPushButton("Supprimer la sélection");
    BSup->show();
    vLayoutListProg->addWidget(BSup);
    connect(BSup,SIGNAL(clicked()), this, SLOT(pushBSupProg()));

    QLabel *nom = new QLabel(QString("Nom : "));
    entNomProg = new QLineEdit();
    QLabel *value = new QLabel(QString("Valeur : "));
    entValueProg = new QLineEdit();

    vLayoutListProg->addWidget(nom);
    vLayoutListProg->addWidget(entNomProg);
    vLayoutListProg->addWidget(value);
    vLayoutListProg->addWidget(entValueProg);

    QPushButton* BCreer = new QPushButton("Créer");
    BCreer->show();
    vLayoutListProg->addWidget(BCreer);
    connect(BCreer,SIGNAL(clicked()), this, SLOT(pushBCreerProg()));

    programme->setLayout(vLayoutListProg);
    return programme;
}


// ----------------------------  Save & ToolBar
/**
 * \fn void Fenetre::closeEvent(QCloseEvent *event)
 * \brief  Teste et sauvegarde si il le faut lors de la fermeture
 *
 * \param  event l'évenement de la fermeture
 */
void Fenetre::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

/**
 * \fn  void Fenetre::newFile()
 * \brief  Créer un nouveau fichier
 *
 */
void Fenetre::newFile()
{
    if (maybeSave()) {
        vuePile->clear();
        message->clear();
        commande->clear();
        setCurrentFile(QString());
    }
}

/**
 * \fn  void Fenetre::open()
 * \brief  Ouvre le fichier
 *
 */
void Fenetre::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}

/**
 * \fn  bool Fenetre::save()
 * \brief  Sauvegarde dans le fichier
 *
 * \return  booléen si sauvegarde se passe bien
 */
bool Fenetre::save()
{
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

/**
 * \fn  bool Fenetre::saveAs()
 * \brief  Sauvegarde dans le fichier
 *
 * \return  booléen si sauvegarde se passe bien
 */
bool Fenetre::saveAs()
{
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return saveFile(dialog.selectedFiles().first());
}

/**
 * \fn  void Fenetre::documentWasModified()
 * \brief  Vérifier si les données qui doivent être stocker ont changés
 *
 */
void Fenetre::documentWasModified()
{
    setWindowModified(message->isModified() && commande->isModified());
}



/**
 * \fn  void Fenetre::createActions()
 * \brief  Créer la bar d'action
 *
 */
void Fenetre::createActions()
{

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));
    QAction *newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &Fenetre::newFile);
    fileMenu->addAction(newAct);
    fileToolBar->addAction(newAct);

    QAction *openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &Fenetre::open);
    fileMenu->addAction(openAct);
    fileToolBar->addAction(openAct);

    QAction *saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save in a file"));
    connect(saveAct, &QAction::triggered, this, &Fenetre::save);
    fileMenu->addAction(saveAct);
    fileToolBar->addAction(saveAct);

    QAction *saveAsAct = new QAction(tr("&Save As"), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save in a file"));
    connect(saveAsAct, &QAction::triggered, this, &Fenetre::saveAs);
    fileMenu->addAction(saveAsAct);
    fileToolBar->addAction(saveAsAct);
}

/**
 * \fn  void Fenetre::createStatusBar()
 * \brief  Créer la bar de statut
 */
void Fenetre::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

/**
 * \fn  void Fenetre::readSettings()
 * \brief  Lis les paramètres
 *
 */
void Fenetre::readSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2,
             (availableGeometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}

/**
 * \fn  void Fenetre::writeSettings()
 * \brief  Ecris les paramètres
 */
void Fenetre::writeSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
}

/**
 * \fn  bool Fenetre::maybeSave()
 * \brief  Teste la sauvegarde
 *
 * \return  booléen si sauvegarde
 */
bool Fenetre::maybeSave()
{
    if (!commande->isModified())
        return true;
    const QMessageBox::StandardButton ret
        = QMessageBox::warning(this, tr("Application"),
                               tr("La commande a été changé.\n"
                                  "Voulez-vous sauvegarder ces changements?"),
                               QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
        return save();
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}

/**
 * \fn  void Fenetre::loadFile(const QString &fileName)
 * \brief  Lis dans de fichier et charge
 *
 * \param  fileName nom du fichier
 */
void Fenetre::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    commande->setText(in.readLine());
    message->setText(in.readLine());
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}

bool Fenetre::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName),
                                  file.errorString()));
        return false;
    }

    QTextStream out(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    out << commande->text() ;
    out << "\n";
    out << message->text();

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

/**
 * \fn  void Fenetre::setCurrentFile(const QString &fileName)
 * \brief  Définis le nom du fichier de sauvegarde
 *
 * \param  fileName nom du fichier
 */
void Fenetre::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    commande->setModified(false);
    message->setModified(false);
    setWindowModified(false);

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName = "untitled.txt";
    setWindowFilePath(shownName);
}

/**
 * \fn  QString Fenetre::strippedName(const QString &fullFileName)
 * \brief  Enlève le chemin du nom du fichier
 *
 * \param  fullFileName Nom du fichier (avec chemin)
 * \return  nom du fichier raccourci
 */
QString Fenetre::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

/**
 * \fn  void Fenetre::refresh()
 * \brief  Mis à jour de l'affichage
 *
 */
void Fenetre::refresh()
{

    //Display pile
    message->setText(cont->getPile()->getMessage());
    vuePile->setText(cont->getPile()->getStackAff());
/*
    vuePile->setRowCount(cont->getPile()->getNbItemsToAffiche());

    for(unsigned int i = cont->getPile()->getNbItemsToAffiche();i>0;i--)
    {
        QString str = QString::number(i);
        str+=" :";
        vuePile->setItem(cont->getPile()->getNbItemsToAffiche()-i,0,new QTableWidgetItem(str));
    }

    unsigned int nbAff = cont->getPile()->getNbItemsToAffiche();
//    unsigned int nbAff = 0;
    int indAff, indPile;

/*  -----------------------    Essai avec l'iterator de QStack
    for(QStack<Litteral*>::Iterator it = cont->getPile()->begin(); it!=cont->getPile()->end() ;++it,nbAff++){
        if(nbAff < cont->getPile()->getNbItemsToAffiche()){
            Litteral* temp = *it;
            vuePile->item(cont->getPile()->getNbItemsToAffiche()-1-nbAff,0)->setText(temp->toString());
        }
    }

*//*  ---------------------    Essai 2
    QString s;

    unsigned int size = cont->getPile()->size();
            unsigned int aff = cont->getPile()->getNbItemsToAffiche();
    unsigned int maxtest = std::min<unsigned int>( size, aff);
    for(unsigned int i = 0 ; i < maxtest ; i++){
        s = cont->getPile()->at(i)->toString();
        QTableWidgetItem* temp = new QTableWidgetItem(s);
        vuePile->setItem(cont->getPile()->getNbItemsToAffiche()-i , 1, temp);
    }
  */  /* ---------------------------------- Essai 1
       unsigned int i=1;

     while(i <= cont->getPile()->getNbItemsToAffiche()) {
        if ( i <= cont->getPile()->size()) {

            indAff = cont->getPile()->getNbItemsToAffiche()-i;
            indPile = cont->getPile()->size()-i;
            if(indPile < cont->getPile()->size() && indPile>=0){
            Litteral * lit = cont->getPile()->at(indPile);
            QString stringTemp = lit->toString();
            QTableWidgetItem* temp = new QTableWidgetItem(stringTemp);
            vuePile->setItem(indAff , 1, temp);
            }
        }
        i++;
    }
    /*        -------------------- Essai de transvaser au fur et à mesure ce que l'on veut afficher dans un autre stack (ne marche ni avec std::stack, ni QStack
    std::stack<Litteral>* temp = new std::stack<Litteral>();
    while( nbAff > 0 )
    {
        ind = cont->getPile()->size() - nbAff;
        if (ind >= 0)
        {
            vuePile->item(cont->getPile()->getNbItemsToAffiche()-nbAff , 1)->setText((cont->getPile()->top()->toString()));
            temp->push(*(cont->getPile()->top()));
            cont->getPile()->pop();
        }
        nbAff--;
    }
    while(!temp->empty()){
        cont->getPile()->push((temp->top()));
        temp->pop();
    }
*/

}

/**
 * \fn  void Fenetre::setCommande(QString s)
 * \brief  Change la ligne de commande
 *
 * \param  s Nouvelle commande
 */
void Fenetre::setCommande(QString s)
{
    commande->setText(s);
    getNextCommande();
}

/**
 * \fn  void Fenetre::getNextCommande()
 * \brief  Donne la ligne de commande au \class Controller controller.h
 *
 */
void Fenetre::getNextCommande()
{
    QString c = commande->text();
//    cont->getPile()->setMessage(c);
    QTextStream stream(&c);
    QString com;
    QString suite;
    do{
        stream>>com;

        if(com.contains("[")){
            stream>>suite;
            com+=" "+suite;
            while(!com.contains("]")){
                stream>>suite;
                com+=" "+suite;
            }
        }
        if(com!="") cont->commande(com);
    }while(com!="");
    commande->clear();
}

 /**
 * \fn  void Fenetre::pushB1()
 * \brief  Slot pour le bouton pushB1
 */
void Fenetre::pushB1(){
    Fenetre::commande->setText(Fenetre::commande->text()+"1");
    //Beep(523,250);

}

 /**
 * \fn  void Fenetre::pushB2()
 * \brief  Slot pour le bouton pushB2
 */
void Fenetre::pushB2(){
    Fenetre::commande->setText(Fenetre::commande->text()+"2");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushB3()
 * \brief  Slot pour le bouton pushB3
 */ void Fenetre::pushB3(){
    Fenetre::commande->setText(Fenetre::commande->text()+"3");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushB4()
 * \brief  Slot pour le bouton pushB4
 */
void Fenetre::pushB4(){
    Fenetre::commande->setText(Fenetre::commande->text()+"4");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushB5()
 * \brief  Slot pour le bouton pushB5
 */
void Fenetre::pushB5(){
    Fenetre::commande->setText(Fenetre::commande->text()+"5");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushB6()
 * \brief  Slot pour le bouton pushB6
 */
void Fenetre::pushB6(){
    Fenetre::commande->setText(Fenetre::commande->text()+"6");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushB7()
 * \brief  Slot pour le bouton pushB7
 */
void Fenetre::pushB7(){
    Fenetre::commande->setText(Fenetre::commande->text()+"7");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushB8()
 * \brief  Slot pour le bouton pushB8
 */
void Fenetre::pushB8(){
    Fenetre::commande->setText(Fenetre::commande->text()+"8");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushB9()
 * \brief  Slot pour le bouton pushB9
 */
void Fenetre::pushB9(){
    Fenetre::commande->setText(Fenetre::commande->text()+"9");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushB0()
 * \brief  Slot pour le bouton pushB0
 */
void Fenetre::pushB0(){
    Fenetre::commande->setText(Fenetre::commande->text()+"0");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushBPlus()
 * \brief  Slot pour le bouton pushBPlus
 */
void Fenetre::pushBPlus(){
    Fenetre::commande->setText(Fenetre::commande->text()+"+");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushBMoins()
 * \brief  Slot pour le bouton pushBMoins
 */
void Fenetre::pushBMoins(){
    Fenetre::commande->setText(Fenetre::commande->text()+"-");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushBFois()
 * \brief  Slot pour le bouton pushBFois
 */
void Fenetre::pushBFois(){
    Fenetre::commande->setText(Fenetre::commande->text()+"*");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushBDiv()
 * \brief  Slot pour le bouton pushBDiv
 */
void Fenetre::pushBDiv(){
    Fenetre::commande->setText(Fenetre::commande->text()+"/");
    //Beep(523,250);
}

 /**
 * \fn  void Fenetre::pushBNeg()
 * \brief  Slot pour le bouton pushBNeg
 */
void Fenetre::pushBNeg(){
    Fenetre::commande->setText(Fenetre::commande->text()+"NEG");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBNum()
 * \brief  Slot pour le bouton pushBNum
 */
void Fenetre::pushBNum(){
    Fenetre::commande->setText(Fenetre::commande->text()+"NUM");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBDen()
 * \brief  Slot pour le bouton pushBDen
 */
void Fenetre::pushBDen(){
    Fenetre::commande->setText(Fenetre::commande->text()+"DEN");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBCompl()
 * \brief  Slot pour le bouton pushBCompl
 */
void Fenetre::pushBCompl(){
    Fenetre::commande->setText(Fenetre::commande->text()+"$");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBRe()
 * \brief  Slot pour le bouton pushBRe
 */
void Fenetre::pushBRe(){
    Fenetre::commande->setText(Fenetre::commande->text()+"RE");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBIm()
 * \brief  Slot pour le bouton pushBIm
 */
void Fenetre::pushBIm(){
    Fenetre::commande->setText(Fenetre::commande->text()+"IM");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBEg()
 * \brief  Slot pour le bouton pushBEg
 */
void Fenetre::pushBEg(){
    Fenetre::commande->setText(Fenetre::commande->text()+"==");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBDiff()
 * \brief  Slot pour le bouton pushBDiff
 */
void Fenetre::pushBDiff(){
    Fenetre::commande->setText(Fenetre::commande->text()+"!=");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBEgSup()
 * \brief  Slot pour le bouton pushBEgSup
 */
void Fenetre::pushBEgSup(){
    Fenetre::commande->setText(Fenetre::commande->text()+">=");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBEgInf()
 * \brief  Slot pour le bouton pushBEgInf
 */
void Fenetre::pushBEgInf(){
    Fenetre::commande->setText(Fenetre::commande->text()+"<=");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBInf()
 * \brief  Slot pour le bouton pushBInf
 */
void Fenetre::pushBInf(){
    Fenetre::commande->setText(Fenetre::commande->text()+"<");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBSup()
 * \brief  Slot pour le bouton pushBSup
 */
void Fenetre::pushBSup(){
    Fenetre::commande->setText(Fenetre::commande->text()+">");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBAnd()
 * \brief  Slot pour le bouton pushBAnd
 */
void Fenetre::pushBAnd(){
    Fenetre::commande->setText(Fenetre::commande->text()+"AND");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBOr()
 * \brief  Slot pour le bouton pushBOr
 */
void Fenetre::pushBOr(){
    Fenetre::commande->setText(Fenetre::commande->text()+"OR");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBNot()
 * \brief  Slot pour le bouton pushBNot
 */
void Fenetre::pushBNot(){
    Fenetre::commande->setText(Fenetre::commande->text()+"NOT");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBSpace()
 * \brief  Slot pour le bouton pushBSpace
 */
void Fenetre::pushBSpace(){
    Fenetre::commande->setText(Fenetre::commande->text()+" ");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBEntree()
 * \brief  Slot pour le bouton pushBEntree
 */
void Fenetre::pushBEntree(){
    emit commande->returnPressed();
}

/**
 * \fn  void Fenetre::pushBCorr()
 * \brief  Slot pour le bouton pushBCorr
 */
void Fenetre::pushBCorr(){
    Fenetre::commande->setText(Fenetre::commande->text().remove(Fenetre::commande->text().size()-1,1));
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBEdit()
 * \brief  Slot pour le bouton pushBEdit
 */
void Fenetre::pushBEdit(){
    Fenetre::commande->setText(Fenetre::commande->text()+"EDIT");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBEval()
 * \brief  Slot pour le bouton pushBEval
 */
void Fenetre::pushBEval(){
    Fenetre::commande->setText(Fenetre::commande->text()+"EVAL");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBForget()
 * \brief  Slot pour le bouton pushBForget
 */
void Fenetre::pushBForget(){
    Fenetre::commande->setText(Fenetre::commande->text()+"FORGET");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBSto()
 * \brief  Slot pour le bouton pushBSto
 */
void Fenetre::pushBSto(){
    Fenetre::commande->setText(Fenetre::commande->text()+"STO");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBIft()
 * \brief  Slot pour le bouton pushBIft
 */
void Fenetre::pushBIft(){
    Fenetre::commande->setText(Fenetre::commande->text()+"IFT");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBDup()
 * \brief  Slot pour le bouton pushBDup
 */
void Fenetre::pushBDup(){
    Fenetre::commande->setText(Fenetre::commande->text()+"DUP");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBDrop()
 * \brief  Slot pour le bouton pushBDrop
 */
void Fenetre::pushBDrop(){
    Fenetre::commande->setText(Fenetre::commande->text()+"DROP");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBSwap()
 * \brief  Slot pour le bouton pushBSwap
 */
void Fenetre::pushBSwap(){
    Fenetre::commande->setText(Fenetre::commande->text()+"SWAP");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBLastOp()
 * \brief  Slot pour le bouton pushBLastOp
 */
void Fenetre::pushBLastOp(){
    Fenetre::commande->setText(Fenetre::commande->text()+"LASTOP");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBLastArgs()
 * \brief  Slot pour le bouton pushBLastArgs
 */
void Fenetre::pushBLastArgs(){
    Fenetre::commande->setText(Fenetre::commande->text()+"LASTARGS");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBUndo()
 * \brief  Slot pour le bouton pushBUndo
 */
void Fenetre::pushBUndo(){
    Fenetre::commande->setText(Fenetre::commande->text()+"UNDO");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBRedo()
 * \brief  Slot pour le bouton pushBRedo
 */
void Fenetre::pushBRedo(){
    Fenetre::commande->setText(Fenetre::commande->text()+"REDO");
    //Beep(523,250);
}

/**
 * \fn  void Fenetre::pushBClear()
 * \brief  Slot pour le bouton pushBClear
 */
void Fenetre::pushBClear(){
    cont->getPile()->clear();
}

void Fenetre::pushBCreerVar(){
    Fenetre::commande->setText(entValueVar->text()+" '"+entNomVar->text()+"' STO");
    getNextCommande();

}
void Fenetre::pushBCreerProg(){

}
void Fenetre::pushBSupVar(){
    for(int i=0; i<listVarCheck.size(); i++){
        if(listVarCheck.at(i)->isChecked())
             Fenetre::commande->setText(listVarName.at(i)->text()+" FORGET ");
    }
    getNextCommande();
}
void Fenetre::pushBSupProg(){

}
void Fenetre::pushBModVar(){

}
void Fenetre::pushBModProg(){

}
