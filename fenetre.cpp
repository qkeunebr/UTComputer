#include "fenetre.h"

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
    vuePile->verticalHeader()->setVisible(false);
//    vuePile->verticalHeader()->setStyleSheet("color:black");
    vuePile->horizontalHeader()->setVisible(false);
    vuePile->horizontalHeader()->setStretchLastSection(true);

    //A changer pour afficher plus de ligne
    vuePile->setRowCount(cont->getPile()->getNbItemsToAffiche());
    vuePile->setColumnCount(2);

//    QStringList numberList;
    for(unsigned int i = cont->getPile()->getNbItemsToAffiche();i>0;i--)
    {
        QString str = QString::number(i);
        str+=" :";
//        numberList<<str;

        vuePile->setItem(i-1,0,new QTableWidgetItem(str));
    }

//    vuePile->setVerticalHeaderLabels(numberList);
    vuePile->setFixedHeight(30*cont->getPile()->getNbItemsToAffiche()/*vuePile->rowHeight(0)+2*/);

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


// ----------------------------  Save & ToolBar
void Fenetre::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

void Fenetre::newFile()
{
    if (maybeSave()) {
        vuePile->clear();
        message->clear();
        commande->clear();
        setCurrentFile(QString());
    }
}

void Fenetre::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}

bool Fenetre::save()
{
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool Fenetre::saveAs()
{
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return saveFile(dialog.selectedFiles().first());
}

void Fenetre::documentWasModified()
{
    setWindowModified(message->isModified() && commande->isModified());
}

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

void Fenetre::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

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

void Fenetre::writeSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
}

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

QString Fenetre::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}


void Fenetre::refresh()
{

    //Display pile
    message->setText(cont->getPile()->getMessage());

    vuePile->setRowCount(cont->getPile()->getNbItemsToAffiche());

    for(unsigned int i = cont->getPile()->getNbItemsToAffiche();i>0;i--)
    {
        QString str = QString::number(i);
        str+=" :";
        vuePile->setItem(cont->getPile()->getNbItemsToAffiche()-i,0,new QTableWidgetItem(str));
    }

    unsigned int nbAff = cont->getPile()->getNbItemsToAffiche();
//    unsigned int nbAff = 0;
    int ind;
/*  -----------------------    Essai avec l'iterator de QStack
    for(QStack<Litteral*>::Iterator it = cont->getPile()->begin(); it!=cont->getPile()->end() ;++it,nbAff++){
        if(nbAff < cont->getPile()->getNbItemsToAffiche()){
            Litteral* temp = *it;
            vuePile->item(cont->getPile()->getNbItemsToAffiche()-1-nbAff,0)->setText(temp->toString());
        }
    }
*//*  ---------------------    Essai avec .value de QStack
    for(unsigned int i=cont->getPile()->getNbItemsToAffiche(); i>0; i--) {
        if ( i<= cont->getPile()->size()) vuePile->setItem(cont->getPile()->getNbItemsToAffiche()-i , 1, new QTableWidgetItem(cont->getPile()->value(cont->getPile()->size()-i)->toString()));
    }
    *//*        -------------------- Essai de transvaser au fur et à mesure ce que l'on veut afficher dans un autre stack (ne marche ni avec std::stack, ni QStack
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

void Fenetre::getNextCommande()
{
    QString c = commande->text();
    cont->getPile()->setMessage(c);
    QTextStream stream(&c);
    QString com;
    do{
        stream>>com;
        if(com!="") cont->commande(com);
    }while(com!="");
    commande->clear();
}

void Fenetre::pushB1(){
    Fenetre::commande->setText(Fenetre::commande->text()+"1");
    //Beep(523,250);

}

void Fenetre::pushB2(){
    Fenetre::commande->setText(Fenetre::commande->text()+"2");
    //Beep(523,250);
}

void Fenetre::pushB3(){
    Fenetre::commande->setText(Fenetre::commande->text()+"3");
    //Beep(523,250);
}

void Fenetre::pushB4(){
    Fenetre::commande->setText(Fenetre::commande->text()+"4");
    //Beep(523,250);
}

void Fenetre::pushB5(){
    Fenetre::commande->setText(Fenetre::commande->text()+"5");
    //Beep(523,250);
}

void Fenetre::pushB6(){
    Fenetre::commande->setText(Fenetre::commande->text()+"6");
    //Beep(523,250);
}

void Fenetre::pushB7(){
    Fenetre::commande->setText(Fenetre::commande->text()+"7");
    //Beep(523,250);
}

void Fenetre::pushB8(){
    Fenetre::commande->setText(Fenetre::commande->text()+"8");
    //Beep(523,250);
}

void Fenetre::pushB9(){
    Fenetre::commande->setText(Fenetre::commande->text()+"9");
    //Beep(523,250);
}

void Fenetre::pushB0(){
    Fenetre::commande->setText(Fenetre::commande->text()+"0");
    //Beep(523,250);
}

void Fenetre::pushBPlus(){
    Fenetre::commande->setText(Fenetre::commande->text()+"+");
    //Beep(523,250);
}

void Fenetre::pushBMoins(){
    Fenetre::commande->setText(Fenetre::commande->text()+"-");
    //Beep(523,250);
}

void Fenetre::pushBFois(){
    Fenetre::commande->setText(Fenetre::commande->text()+"*");
    //Beep(523,250);
}

void Fenetre::pushBDiv(){
    Fenetre::commande->setText(Fenetre::commande->text()+"/");
    //Beep(523,250);
}

void Fenetre::pushBNeg(){
    Fenetre::commande->setText(Fenetre::commande->text()+"NEG");
    //Beep(523,250);
}

void Fenetre::pushBNum(){
    Fenetre::commande->setText(Fenetre::commande->text()+"NUM");
    //Beep(523,250);
}

void Fenetre::pushBDen(){
    Fenetre::commande->setText(Fenetre::commande->text()+"DEN");
    //Beep(523,250);
}

void Fenetre::pushBCompl(){
    Fenetre::commande->setText(Fenetre::commande->text()+"$");
    //Beep(523,250);
}

void Fenetre::pushBRe(){
    Fenetre::commande->setText(Fenetre::commande->text()+"RE");
    //Beep(523,250);
}

void Fenetre::pushBIm(){
    Fenetre::commande->setText(Fenetre::commande->text()+"IM");
    //Beep(523,250);
}

void Fenetre::pushBEg(){
    Fenetre::commande->setText(Fenetre::commande->text()+"==");
    //Beep(523,250);
}

void Fenetre::pushBNEg(){
    Fenetre::commande->setText(Fenetre::commande->text()+"!=");
    //Beep(523,250);
}

void Fenetre::pushBEgSup(){
    Fenetre::commande->setText(Fenetre::commande->text()+"=>");
    //Beep(523,250);
}

void Fenetre::pushBEgInf(){
    Fenetre::commande->setText(Fenetre::commande->text()+"=<");
    //Beep(523,250);
}

void Fenetre::pushBInf(){
    Fenetre::commande->setText(Fenetre::commande->text()+"<");
    //Beep(523,250);
}

void Fenetre::pushBSup(){
    Fenetre::commande->setText(Fenetre::commande->text()+">");
    //Beep(523,250);
}

void Fenetre::pushBAnd(){
    Fenetre::commande->setText(Fenetre::commande->text()+"&&");
    //Beep(523,250);
}

void Fenetre::pushBOr(){
    Fenetre::commande->setText(Fenetre::commande->text()+"||");
    //Beep(523,250);
}

void Fenetre::pushBNot(){
    Fenetre::commande->setText(Fenetre::commande->text()+"");
    //Beep(523,250);
}
