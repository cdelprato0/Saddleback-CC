#include "mainwindow.h" //includes stadiumvisitplan.h
#include "adminlogin.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlTableModel>

// Will be the indexes of the pages on the pages stack widget
enum page{
    // If you create a new page, please make an enum for it.
    WelcomePage,
    PlanPage,
    CustomPlanPage,
    PurchaseSouvenirsPage,
    ViewPurchasesAndPlanPage,
    ViewInformationPage,
    AdminWelcomePage,
    AdminSouvenirManagementPage,
    AdminStadiumManagementPage,
    ViewTablesPage
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    adminLoggedIn = false;
    slideShowIndex = 0;
    currentPlan = new StadiumVisitPlan();

    // Will set to the 0th index of the pages stack instead of last seen
    // page of the ui file.
    SetIndex(WelcomePage);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete currentPlan;
}

// If a mainwindow is created elsewhere, this will set the page index.
// Also helps with the back button.
void MainWindow::SetIndex(int passedIndex)
{
    if(passedIndex == AdminWelcomePage){
        adminLoggedIn = true;
        visitedPages.clear();
    }
    visitedPages.push_back(ui->pages->currentIndex());
    ui->pages->setCurrentIndex(passedIndex);
}

// Menubar: Login Go will check if an admin is already logged in or not.
void MainWindow::on_actiongo_triggered()
{
    if(adminLoggedIn){
        qDebug() << "\nAdmin Already Logged In Exception.\n";
        QMessageBox::information(this, "Uh oh!", "You are already Logged In!");
    }else{
        AdminLogin *a = new AdminLogin(this);
        a->show();
    }
}

// Back Buttons: Used to go back to the previous page.
void MainWindow::go_to_previous_page()
{
    ui->pages->setCurrentIndex(visitedPages.back());
    visitedPages.pop_back();
}

// WelcomePage: Will send user to custom plan page.
void MainWindow::on_button_CustomPlanPage_clicked()
{
    ui->label_error_onCustom->hide();
    ui->comboBox_selectStart_onCustom->clear();

    //Populates the stadium combo box
    std::vector<QString> stadiumNames = Database::getInstance()->getAllStadiumNamesAsVector();
    std::vector<QString>::iterator stadiumIt = stadiumNames.begin();
    while(stadiumIt != stadiumNames.end()){
        ui->comboBox_selectStart_onCustom->addItem(*stadiumIt);
        stadiumIt++;
    }

    //Populates the stadium list using a listWidget
    ui->listWidget_stadiumsToVisit_onCustom->clear();
    QListWidgetItem *listptr;

    for(int i = 0; i < int(stadiumNames.size()); i++){
        listptr = new QListWidgetItem;
        listptr->setText(stadiumNames.at(i));
        if(listptr->text() != ui->comboBox_selectStart_onCustom->currentText()){
            ui->listWidget_stadiumsToVisit_onCustom->addItem(listptr);
        }
    }

    SetIndex(CustomPlanPage);
}

// WelcomePage: Will send user to the information page
void MainWindow::on_button_InformationPage_clicked()
{
    ui->tabWidget_displayStadiums->setCurrentIndex(0);
    SetIndex(ViewInformationPage);

    // Set combo boxes:
    ui->comboBox_specificTeam->clear();
    ui->comboBox_specificTypology->clear();
    QStringList teamlist = Database::getInstance()->getTeamsComboBox();
    QStringList typelist = Database::getInstance()->getTypologyComboBox();
    ui->comboBox_specificTeam->addItems(teamlist);
    ui->comboBox_specificTypology->addItems(typelist);
    ui->comboBox_selectTeam->addItem("Select a team to view");
    ui->comboBox_selectTeam->addItems(teamlist);
    ui->comboBox_selectTeam->setCurrentIndex(0);

    // Initialize all the tables for the page
    QSqlTableModel *model1 = new QSqlTableModel(this, *Database::getInstance());
    model1->setTable("Stadiums");
    model1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model1->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model1->setHeaderData(1, Qt::Horizontal, tr("Capacity"));
    model1->setHeaderData(2, Qt::Horizontal, tr("Address"));
    model1->setHeaderData(3, Qt::Horizontal, tr("Surface"));
    model1->setHeaderData(4, Qt::Horizontal, tr("Team"));
    model1->setHeaderData(5, Qt::Horizontal, tr("Date Opened"));
    model1->setHeaderData(6, Qt::Horizontal, tr("Typology"));
    model1->setHeaderData(7, Qt::Horizontal, tr("League"));
    ui->tableView_allInformation->setModel(model1);
    ui->tableView_allInformation->setSortingEnabled(true);
    ui->tableView_allInformation->resizeColumnsToContents();
    ui->tableView_allInformation->setColumnWidth(1, 85);
    ui->tableView_allInformation->setColumnWidth(5, 100);
    ui->tableView_allInformation->verticalHeader()->setVisible(false);
    ui->tableView_allInformation->sortByColumn(0, Qt::AscendingOrder);
    ui->tableView_allInformation->setEditTriggers(QAbstractItemView::NoEditTriggers);


    auto model = Database::getInstance()->getAllStadiumsAndLocations();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("Address"));
    ui->tableView_allStadiums->setModel(model);
    ui->tableView_allStadiums->resizeColumnsToContents();
    ui->tableView_allStadiums->verticalHeader()->setVisible(false);

    model1 = new QSqlTableModel(this, *Database::getInstance());
    model1->setTable("Stadiums");
    model1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model1->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model1->setHeaderData(4, Qt::Horizontal, tr("Team"));
    ui->tableView_allTeams->setModel(model1);
    ui->tableView_allTeams->hideColumn(1);
    ui->tableView_allTeams->hideColumn(2);
    ui->tableView_allTeams->hideColumn(5);
    ui->tableView_allTeams->hideColumn(6);
    ui->tableView_allTeams->hideColumn(7);
    ui->tableView_allTeams->hideColumn(3);
    ui->tableView_allTeams->setSortingEnabled(true);
    ui->tableView_allTeams->resizeColumnsToContents();
    ui->tableView_allTeams->verticalHeader()->setVisible(false);
    ui->tableView_allTeams->sortByColumn(0, Qt::AscendingOrder);
    ui->tableView_allTeams->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    model = Database::getInstance()->getTeamsAndStadiums();
//    model->setHeaderData(0, Qt::Horizontal, tr("Team Names"));
//    model->setHeaderData(1, Qt::Horizontal, tr("Stadium Name"));
//    ui->tableView_allTeams->setModel(model);
//    ui->tableView_allTeams->verticalHeader()->setVisible(false);
//    ui->tableView_allTeams->resizeColumnsToContents();

    model = Database::getInstance()->getAllSurfaces();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("Surface"));
    ui->tableView_allGrass->setModel(model);
    ui->tableView_allGrass->verticalHeader()->setVisible(false);
    ui->tableView_allGrass->resizeColumnsToContents();   
    ui->lineEdit_totalGrass->setText(QString::number(Database::getInstance()->totalGrass()));

//    model = Database::getInstance()->getAllCapacity();
//    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
//    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
//    model->setHeaderData(2, Qt::Horizontal, tr("Seat Capacity"));
//    ui->tableView_allCapacity->setModel(model);
//    ui->tableView_allCapacity->resizeColumnsToContents();
//    ui->tableView_allCapacity->setColumnWidth(2, 100);
//    ui->tableView_allCapacity->verticalHeader()->setVisible(false);

    model1 = new QSqlTableModel(this, *Database::getInstance());
    model1->setTable("Stadiums");
    model1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model1->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model1->setHeaderData(1, Qt::Horizontal, tr("Capacity"));
    model1->setHeaderData(4, Qt::Horizontal, tr("Teams"));
    ui->tableView_allCapacity->setModel(model1);
    ui->tableView_allCapacity->hideColumn(2);
    ui->tableView_allCapacity->hideColumn(3);
    ui->tableView_allCapacity->hideColumn(5);
    ui->tableView_allCapacity->hideColumn(6);
    ui->tableView_allCapacity->hideColumn(7);
    ui->tableView_allCapacity->setSortingEnabled(true);
    ui->tableView_allCapacity->resizeColumnsToContents();
    ui->tableView_allCapacity->setColumnWidth(1, 85);
    ui->tableView_allCapacity->setColumnWidth(5, 100);
    ui->tableView_allCapacity->verticalHeader()->setVisible(false);
    ui->tableView_allCapacity->sortByColumn(1, Qt::AscendingOrder);
    ui->tableView_allCapacity->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lineEdit_totalCapacity->setText(QString::number(Database::getInstance()->totalCapacity()));


//    model = Database::getInstance()->getAllOpenedDates();
//    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Names"));
//    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
//    model->setHeaderData(2, Qt::Horizontal, tr("Opened Dates"));
//    ui->tableView_allOpenedDates->setModel(model);
//    ui->tableView_allOpenedDates->resizeColumnsToContents();
//    ui->tableView_allOpenedDates->setColumnWidth(2, 100);
//    ui->tableView_allOpenedDates->verticalHeader()->setVisible(false);

    model1 = new QSqlTableModel(this, *Database::getInstance());
    model1->setTable("Stadiums");
    model1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model1->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model1->setHeaderData(5, Qt::Horizontal, tr("Opened Dates"));
    model1->setHeaderData(4, Qt::Horizontal, tr("Teams"));
    ui->tableView_allOpenedDates->setModel(model1);
    ui->tableView_allOpenedDates->hideColumn(1);
    ui->tableView_allOpenedDates->hideColumn(2);
    ui->tableView_allOpenedDates->hideColumn(3);
    ui->tableView_allOpenedDates->hideColumn(6);
    ui->tableView_allOpenedDates->hideColumn(7);
    ui->tableView_allOpenedDates->setSortingEnabled(true);
    ui->tableView_allOpenedDates->resizeColumnsToContents();
    ui->tableView_allOpenedDates->setColumnWidth(1, 85);
    ui->tableView_allOpenedDates->setColumnWidth(5, 100);
    ui->tableView_allOpenedDates->verticalHeader()->setVisible(false);
    ui->tableView_allOpenedDates->sortByColumn(5, Qt::AscendingOrder);
    ui->tableView_allOpenedDates->setEditTriggers(QAbstractItemView::NoEditTriggers);


    model = Database::getInstance()->getAllLeagues();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("League"));
    ui->tableView_allLeagues->setModel(model);
    ui->tableView_allLeagues->resizeColumnsToContents();
    ui->tableView_allLeagues->verticalHeader()->setVisible(false);


    model = Database::getInstance()->getAllTypology();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("Typology"));
    ui->tableView_allTypology->setModel(model);
    ui->tableView_allTypology->verticalHeader()->setVisible(false);
    ui->tableView_allTypology->resizeColumnsToContents();

    model = Database::getInstance()->getAllSouvenirs();
    model->setHeaderData(0, Qt::Horizontal, tr("Item"));
    model->setHeaderData(1, Qt::Horizontal, tr("Price"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team Name"));
    ui->tableView_allSouvenirs->setModel(model);
    ui->tableView_allSouvenirs->resizeColumnsToContents();
    ui->tableView_allSouvenirs->setColumnWidth(1, 85);
    ui->tableView_allSouvenirs->verticalHeader()->setVisible(false);


}

 // WelcomePage: sets the pages stack widget to the proper page and fills
// the tableview up with the stadium names.
void MainWindow::on_button_PlanPage_clicked()
{
    SetIndex(PlanPage);

    // gets model from database method and then sets the table view.
    auto model = Database::getInstance()->getAllStadiumNames();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    ui->tableView_everyStadium->setModel(model);
}

// PlanPage: Will set the currentPlan to every stadium name starting at comerica park
void MainWindow::on_button_comericaPark_clicked()
{
    currentPlan->clearPlan();

    std::vector<QString> temp = Database::getInstance()->getAllStadiumNamesAsVector();
    for(auto itr = temp.begin(); itr != temp.end(); itr++){
        currentPlan->pushStadium(*itr);
    }

    QString hold = currentPlan->planAt(0);
    currentPlan->removeStadium("Comerica Park");
    currentPlan->setStartingStadium("Comerica Park");
    currentPlan->pushStadium(hold);

    currentPlan->Dijkstras();

    //Goes to the purchase page and sets everything up for first stadium visited
    SetIndex(PurchaseSouvenirsPage);
    ui->label_error_onPurchase->hide();
    ui->label_success_onPurchase->hide();
    ui->pushButton_finish_onPurchase->hide();
    ui->pushButton_next_onPurchase->show();

    //Populates the current stadium lineEdit
    currentStadium = 0;
    ui->lineEdit_currentStadium_onPurchase->setText(currentPlan->planAt(currentStadium));
    ui->progressBar_onPurchase->setMaximum(currentPlan->planSize());
    ui->progressBar_onPurchase->setValue(currentStadium + 1);
    std::vector<QString> stadiumNames = Database::getInstance()->getAllStadiumNamesAsVector();

    //Populates the souvenir list using a tablewidget
    QSqlQuery myQuery(*(Database::getInstance()));
    QString stadiumName = currentPlan->planAt(currentStadium);
    myQuery.prepare("SELECT item AS \"Souvenir Name\", price AS \"Price ($)\" FROM Souvenirs WHERE team = (SELECT team FROM Stadiums WHERE name = \"" + stadiumName +"\")");
    myQuery.exec();

    //Creates vectors to populate table
    std::vector<QString> souvenirNames;
    std::vector<double> souvenirPrices;
    std::vector<int> sounvenirQuantities;

    while(myQuery.next()){
        souvenirNames.push_back(myQuery.value(0).toString());
        souvenirPrices.push_back(myQuery.value(1).toDouble());
    }

    QTableWidgetItem *nameptr;
    QTableWidgetItem *priceptr;
    QSpinBox *spinptr;
    ui->tableWidget_souvenirs_onPurchase->setRowCount(souvenirNames.size());
    ui->tableWidget_souvenirs_onPurchase->setColumnCount(3);
    ui->tableWidget_souvenirs_onPurchase->verticalHeader()->setVisible(false);
    ui->tableWidget_souvenirs_onPurchase->setColumnWidth(0, 300);
    ui->tableWidget_souvenirs_onPurchase->setColumnWidth(1, 100);

    for(int i = 0; unsigned(i) < souvenirNames.size(); i++){
        nameptr = new QTableWidgetItem;
        priceptr = new QTableWidgetItem;
        spinptr = new QSpinBox(this);
        nameptr->setText(souvenirNames.at(i));
        priceptr->setText("$" + QString::number(souvenirPrices.at(i)));
        spinptr->setValue(0);
        ui->tableWidget_souvenirs_onPurchase->setItem(i, 0, nameptr);
        ui->tableWidget_souvenirs_onPurchase->setItem(i, 1, priceptr);
        ui->tableWidget_souvenirs_onPurchase->setCellWidget(i, 2, spinptr);
    }
}

// Custom Plan Page: will change the starting stadium and populate the
// stadium list with proper stadiums to choose from.
void MainWindow::on_comboBox_selectStart_onCustom_currentIndexChanged(const QString &arg1)
{
    std::vector<QString> stadiumNames = Database::getInstance()->getAllStadiumNamesAsVector();

    //Populates the stadium list using a listWidget
    ui->listWidget_stadiumsToVisit_onCustom->clear();
    QListWidgetItem *listptr;

    for(int i = 0; unsigned(i) < stadiumNames.size(); i++){
        listptr = new QListWidgetItem;
        listptr->setText(stadiumNames.at(i));
        if(listptr->text() != arg1){
            ui->listWidget_stadiumsToVisit_onCustom->addItem(listptr);
        }
    }
}

// Custom Plan Page: Will add the stadiums selected to the plan
void MainWindow::on_pushButton_confirm_onCustom_clicked()
{
    QList<QListWidgetItem*> selectedStadiums = ui->listWidget_stadiumsToVisit_onCustom->selectedItems();

    if(selectedStadiums.size() != 0){
        currentPlan->clearPlan();
        currentPlan->pushStadium(ui->comboBox_selectStart_onCustom->currentText());
        for(int i = 0; i < selectedStadiums.size(); i++){
            currentPlan->pushStadium((selectedStadiums.at(i)->text()));
        }

        //put dijsktras here
        currentPlan->Dijkstras();

        //Goes to the purchase page and sets everything up for first stadium visited
        SetIndex(PurchaseSouvenirsPage);
        ui->label_error_onPurchase->hide();
        ui->label_success_onPurchase->hide();
        ui->pushButton_finish_onPurchase->hide();
        ui->pushButton_next_onPurchase->show();

        //Populates the current stadium lineEdit
        currentStadium = 0;
        ui->lineEdit_currentStadium_onPurchase->setText(currentPlan->planAt(currentStadium));
        ui->progressBar_onPurchase->setMaximum(currentPlan->planSize());
        ui->progressBar_onPurchase->setValue(currentStadium + 1);
        std::vector<QString> stadiumNames = Database::getInstance()->getAllStadiumNamesAsVector();

        //Populates the souvenir list using a tablewidget
        QSqlQuery myQuery(*(Database::getInstance()));
        QString stadiumName = currentPlan->planAt(currentStadium);
        myQuery.prepare("SELECT item AS \"Souvenir Name\", price AS \"Price ($)\" FROM Souvenirs WHERE team = (SELECT team FROM Stadiums WHERE name = \"" + stadiumName +"\")");
        myQuery.exec();

        //Creates vectors to populate table
        std::vector<QString> souvenirNames;
        std::vector<double> souvenirPrices;
        std::vector<int> sounvenirQuantities;

        while(myQuery.next()){
            souvenirNames.push_back(myQuery.value(0).toString());
            souvenirPrices.push_back(myQuery.value(1).toDouble());
        }

        QTableWidgetItem *nameptr;
        QTableWidgetItem *priceptr;
        QSpinBox *spinptr;
        ui->tableWidget_souvenirs_onPurchase->setRowCount(souvenirNames.size());
        ui->tableWidget_souvenirs_onPurchase->setColumnCount(3);
        ui->tableWidget_souvenirs_onPurchase->verticalHeader()->setVisible(false);
        ui->tableWidget_souvenirs_onPurchase->setColumnWidth(0, 300);
        ui->tableWidget_souvenirs_onPurchase->setColumnWidth(1, 100);

        for(int i = 0; unsigned(i) < souvenirNames.size(); i++){
            nameptr = new QTableWidgetItem;
            priceptr = new QTableWidgetItem;
            spinptr = new QSpinBox(this);
            nameptr->setText(souvenirNames.at(i));
            priceptr->setText("$" + QString::number(souvenirPrices.at(i)));
            spinptr->setValue(0);
            ui->tableWidget_souvenirs_onPurchase->setItem(i, 0, nameptr);
            ui->tableWidget_souvenirs_onPurchase->setItem(i, 1, priceptr);
            ui->tableWidget_souvenirs_onPurchase->setCellWidget(i, 2, spinptr);
        }
    }else{
        ui->label_error_onCustom->show();
    }
}

// Purchase Souvenirs Page: Will let you move on to the next stadium
// in the stadium visit plan.
void MainWindow::on_pushButton_next_onPurchase_clicked()
{
    currentStadium++;
    //Resets page for next stadium in trip
    ui->label_success_onPurchase->hide();

    //Populates the current stadium lineEdit
    ui->lineEdit_currentStadium_onPurchase->setText(currentPlan->planAt(currentStadium));
    ui->progressBar_onPurchase->setMaximum(currentPlan->planSize());
    ui->progressBar_onPurchase->setValue(currentStadium + 1);

    if((currentStadium + 1) == currentPlan->planSize()){
        ui->pushButton_next_onPurchase->hide();
        ui->pushButton_finish_onPurchase->show();
    }

    //Populates the souvenir list using a tablewidget
    QSqlQuery myQuery(*(Database::getInstance()));
    QString stadiumName = currentPlan->planAt(currentStadium);
    myQuery.prepare("SELECT item AS \"Souvenir Name\", price AS \"Price ($)\" FROM Souvenirs WHERE team = (SELECT team FROM Stadiums WHERE name = \"" + stadiumName +"\")");
    myQuery.exec();

    //Creates vectors to populate table
    std::vector<QString> souvenirNames;
    std::vector<double> souvenirPrices;

    while(myQuery.next()){
        souvenirNames.push_back(myQuery.value(0).toString());
        souvenirPrices.push_back(myQuery.value(1).toDouble());
    }

    QTableWidgetItem *nameptr;
    QTableWidgetItem *priceptr;
    QSpinBox *spinptr;
    ui->tableWidget_souvenirs_onPurchase->setRowCount(souvenirNames.size());
    ui->tableWidget_souvenirs_onPurchase->setColumnCount(3);
    ui->tableWidget_souvenirs_onPurchase->verticalHeader()->setVisible(false);
    ui->tableWidget_souvenirs_onPurchase->setColumnWidth(0, 300);
    ui->tableWidget_souvenirs_onPurchase->setColumnWidth(1, 100);

    for(int i = 0; unsigned(i) < souvenirNames.size(); i++){
        nameptr = new QTableWidgetItem;
        priceptr = new QTableWidgetItem;
        spinptr = new QSpinBox(this);
        nameptr->setText(souvenirNames.at(i));
        priceptr->setText("$" + QString::number(souvenirPrices.at(i)));
        spinptr->setValue(0);
        ui->tableWidget_souvenirs_onPurchase->setItem(i, 0, nameptr);
        ui->tableWidget_souvenirs_onPurchase->setItem(i, 1, priceptr);
        ui->tableWidget_souvenirs_onPurchase->setCellWidget(i, 2, spinptr);
    }

    ui->tableWidget_souvenirs_onPurchase->clearFocus();
}

// Purchase Souvenirs Page: Will finish purchasing the food and
// send the user to the "Summary Page" and also initialize
// the summary page.
void MainWindow::on_pushButton_finish_onPurchase_clicked()
{
    ui->listWidget_AllStadiums->clear();
    ui->listWidget_dijkstrasInformation->clear();
    ui->listWidget_history->clear();
    ui->listWidget_MST->clear();
    ui->tabWidget_summary->setCurrentIndex(0);

    QString picture = "assets/TeamLogos/";
    QString stadiumName = currentPlan->planAt(0);
    stadiumName.replace(" ", "_");
    stadiumName.replace("&", "_");
    picture.append(stadiumName);
    picture.append(".png");

    QPixmap pixmap(picture);
    ui->label_stadiumArt->setPixmap(pixmap);


    // Initializes listWidget_AllStadiums
    for(int i = currentPlan->planSize()-1; i >= 0; i--){
        ui->listWidget_AllStadiums->insertItem(0, currentPlan->planAt(i));
    }

    // Outputs MST
    StadiumVisitPlan *newPlan = new StadiumVisitPlan;
    std::vector<QString> temp = Database::getInstance()->getAllStadiumNamesAsVector();
    for(auto itr = temp.begin(); itr != temp.end(); itr++){
        newPlan->pushStadium(*itr);
    }

    QString hold = newPlan->planAt(0);
    newPlan->removeStadium("Comerica Park");
    newPlan->setStartingStadium("Comerica Park");
    newPlan->pushStadium(hold);
    newPlan->Dijkstras();
    std::vector<QString> mst = newPlan->MST();
    for(int i = mst.size()-1; i >= 0; i--){
        ui->listWidget_MST->insertItem(0, mst.at(i));
    }
    ui->listWidget_MST->insertItem(0, "Using Prims:");
    ui->listWidget_MST->insertItem(0, " ");
    ui->listWidget_MST->insertItem(0, QString::number(newPlan->getTotalDistance()).append(" mi"));
    ui->listWidget_MST->insertItem(0, "Total Distance: ");
    ui->listWidget_MST->insertItem(0, "MST of entire database of information");

    // Outputs Dijkstras
    std::vector<QString> ends;
    std::vector<QString> paths;
    QString appender;
    int distance = 0;
    int total = 0;

    std::vector<QString> testing;

    for(int i = 1; i < currentPlan->planSize(); i++){

        ends.push_back(currentPlan->planAt(i));

        testing = currentPlan->Dijkstras(currentPlan->planAt(0), ends, distance);

        appender = " ";
        appender.append(ends.at(0));
        appender.append("   ");
        appender.append(QString::number(distance).append(" mi"));
        paths.push_back(appender);

        qDebug() << " Path ";
        for(auto i = testing.begin(); i != testing.end(); i++){
            qDebug() << *i;
        }
        qDebug() << "end Path";

        ends.pop_back();
        total += distance;
        distance = 0;
    }

    for(int i = int(paths.size())-1; i >= 0; i--){
        ui->listWidget_dijkstrasInformation->insertItem(0, paths.at(i));
    }
    QString blah = "From ";
    blah.append(currentPlan->planAt(0));
    blah.append(" to: ");
    ui->listWidget_dijkstrasInformation->insertItem(0, blah);

    ui->listWidget_dijkstrasInformation->insertItem(0, " ");
    ui->listWidget_dijkstrasInformation->insertItem(0, QString("Sum of all shortest paths from Starting Stadium: ").append(QString::number(total)).append(" mi"));
    ui->listWidget_dijkstrasInformation->insertItem(0, QString("Distance traveled along trip : ").append(QString::number(currentPlan->getTotalDistance())).append(" mi"));

    // Outputs History
    std::vector<souvenir> purchased;
    double totalPrice = 0.0;
    double price = 0.0;

    for(int i = currentPlan->planSize()-1; i >=0; i--){
        purchased = currentPlan->getPurchasedVectorAt(i);


        if(purchased.size() >0){
            for(auto s = purchased.begin(); s!= purchased.end(); s++){
                appender = "   ";
                appender.append(s->souvenirName).append("   x ").append(QString::number(s->quantity));
                price += (Database::getInstance()->getPriceOf(s->souvenirName,
                          Database::getInstance()->getTeam(currentPlan->planAt(i)))) * s->quantity;
                appender.append("  $");
                appender.append((QString::number(Database::getInstance()->getPriceOf(s->souvenirName,
                                                Database::getInstance()->getTeam(currentPlan->planAt(i)))* s->quantity)));
                ui->listWidget_history->insertItem(0, appender);
            }
            ui->listWidget_history->insertItem(0, "   Total Spent Here:  $" + QString::number(price));
            totalPrice+= price;
            price = 0;

            appender = "Purchased at ";
            ui->listWidget_history->insertItem(0, appender.append(currentPlan->planAt(i)) + ":");
            ui->listWidget_history->insertItem(0, " ");
        }
    }

    ui->listWidget_history->insertItem(0, "Total Cost:  $" + QString::number(totalPrice));

    SetIndex(ViewPurchasesAndPlanPage);
}

// Purchase Souvneirs Page: Will push the purchased souvenirs on to the
// plan vector.
void MainWindow::on_pushButton_confirm_onPurchase_clicked()
{
    QWidget* currentWidget;
    QSpinBox* spinBox;
    int quantity = 0;
    int totalQuantity = 0;

    //Gets list of souvenir names
    QSqlQuery myQuery(*(Database::getInstance()));
    QString stadiumName = currentPlan->planAt(currentStadium);
    myQuery.prepare("SELECT item AS \"Souvenir Name\", price AS \"Price ($)\" FROM Souvenirs WHERE team = (SELECT team FROM Stadiums WHERE name = \"" + stadiumName +"\")");
    myQuery.exec();
    std::vector<QString> souvenirNames;

    while(myQuery.next()){
        souvenirNames.push_back(myQuery.value(0).toString());
    }

    for(int i = 0; i < ui->tableWidget_souvenirs_onPurchase->rowCount(); i++){
        currentWidget = ui->tableWidget_souvenirs_onPurchase->cellWidget(i, 2); // retrieve widget from cell
        spinBox = static_cast<QSpinBox*>(currentWidget);   // cast widget to double spin box
        quantity = spinBox->value();   // get value from spinbox

        totalQuantity += quantity;

        if(quantity > 0){
            currentPlan->pushSouvenir(souvenirNames.at(i), currentStadium);
            currentPlan->changeQuantityAt(currentStadium, souvenirNames.at(i),quantity);

            ui->label_success_onPurchase->show();
            ui->label_error_onPurchase->hide();
        }
    }

    if(totalQuantity == 0){
        ui->label_error_onPurchase->show();
    }
}

// Purchase Souvenirs Page: Will cancel the plan and send the user back to
// the main menu welcome screen.
void MainWindow::on_pushButton_cancel_onPurchase_clicked()
{
    currentPlan->clearPlan();
    SetIndex(WelcomePage);
}


//View Purchases and Plan Page methods: Will move right on the slideshow
// of the stadiums visited.
void MainWindow::on_button_moveRight_clicked()
{
    if(slideShowIndex == currentPlan->planSize()-1){
        slideShowIndex = 0;
    }else{
        slideShowIndex++;
    }

    QString picture = "assets/TeamLogos/";
    QString stadiumName = currentPlan->planAt(slideShowIndex);
    stadiumName.replace(" ", "_");
    stadiumName.replace("&", "_");
    picture.append(stadiumName);
    picture.append(".png");

    QPixmap pixmap(picture);
    ui->label_stadiumArt->setPixmap(pixmap);
}

// View Purchases and Plan Page methods: will move left on the slideshow
// of stadiums that the user visited
void MainWindow::on_button_moveLeft_clicked()
{
    if(slideShowIndex == 0){
        slideShowIndex = currentPlan->planSize()-1;
    }else{
        slideShowIndex--;
    }

    QString picture = "assets/TeamLogos/";
    QString stadiumName = currentPlan->planAt(slideShowIndex);
    stadiumName.replace(" ", "_");
    stadiumName.replace("&", "_");
    picture.append(stadiumName);
    picture.append(".png");

    QPixmap pixmap(picture);
    ui->label_stadiumArt->setPixmap(pixmap);
}

// View Purchases and Plan Page methods: Will restart the entire plan.
void MainWindow::on_button_restartPlan_clicked()
{
    currentPlan->clearPlan();
    visitedPages.clear();
    SetIndex(WelcomePage);
}


// View Information Page: Will display both teams and
// stadiums on the teams tab (tableView_allTeams)
void MainWindow::on_button_both_clicked()
{
    QSqlTableModel *model1 = new QSqlTableModel(this, *Database::getInstance());
    model1->setTable("Stadiums");
    model1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model1->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model1->setHeaderData(4, Qt::Horizontal, tr("Team"));
    ui->tableView_allTeams->setModel(model1);
    ui->tableView_allTeams->hideColumn(1);
    ui->tableView_allTeams->hideColumn(2);
    ui->tableView_allTeams->hideColumn(5);
    ui->tableView_allTeams->hideColumn(6);
    ui->tableView_allTeams->hideColumn(7);
    ui->tableView_allTeams->hideColumn(3);
    ui->tableView_allTeams->setSortingEnabled(true);
    ui->tableView_allTeams->resizeColumnsToContents();
    ui->tableView_allTeams->verticalHeader()->setVisible(false);
    ui->tableView_allTeams->sortByColumn(0, Qt::AscendingOrder);
    ui->tableView_allTeams->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

// View Information Page: Will display just teams
// on the teams tab (tableView_allTeams)
void MainWindow::on_button_teams_clicked()
{
    auto model = Database::getInstance()->getAllTeams();
    model->setHeaderData(0, Qt::Horizontal, tr("Team Names"));
    ui->tableView_allTeams->setModel(model);
    ui->tableView_allTeams->verticalHeader()->setVisible(false);
    ui->tableView_allTeams->resizeColumnsToContents();
}

// View Information Page: Will display only stadiums with grass
// on the surface tab of the view information page. (tableView_allGrass)
void MainWindow::on_button_grass_clicked()
{
    auto model = Database::getInstance()->getAllStadiumsWithGrass();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("Surface"));
    ui->tableView_allGrass->setModel(model);
    ui->tableView_allGrass->verticalHeader()->setVisible(false);
//    ui->tableView_allGrass->resizeColumnsToContents();
}

// View Information Page: Will display only stadiums with surfaces
// that isn't grass on the surface tab of the view information page. (tableView_allGrass)
void MainWindow::on_button_other_clicked()
{
    auto model = Database::getInstance()->getAllStadiumsWithoutGrass();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("Surface"));
    ui->tableView_allGrass->setModel(model);
    ui->tableView_allGrass->verticalHeader()->setVisible(false);
//    ui->tableView_allGrass->resizeColumnsToContents();
}

// View Information Page: Will display all the stadiums and their surface
// on the surface tab of the view Information page. (tableView_allGrass)
void MainWindow::on_button_allSurfaces_clicked()
{
    auto model = Database::getInstance()->getAllSurfaces();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("Surface"));
    ui->tableView_allGrass->setModel(model);
    ui->tableView_allGrass->verticalHeader()->setVisible(false);
    ui->tableView_allGrass->resizeColumnsToContents();
}

// View Information Page: Will change the table view on the typology tab
// of the view information page to view all the stadiums with the
// specified typology. (tableView_allTypology)
void MainWindow::on_comboBox_specificTypology_currentIndexChanged(int index)
{
    QString modelChange = ui->comboBox_specificTypology->currentText();
    auto model = Database::getInstance()->getAllTypologyWith(modelChange);
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("Typology"));
    ui->tableView_allTypology->setModel(model);
    ui->tableView_allTypology->verticalHeader()->setVisible(false);
//    ui->tableView_allTypology->resizeColumnsToContents();
}

// View Information Page: Will change the table view on the typology tab
// of the view information page to view all the stadiums and their typology.
// (tableView_allTypology)
void MainWindow::on_button_allTypology_clicked()
{
    auto model = Database::getInstance()->getAllTypology();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("Typology"));
    ui->tableView_allTypology->setModel(model);
    ui->tableView_allTypology->verticalHeader()->setVisible(false);
    ui->tableView_allTypology->resizeColumnsToContents();
}

// View Information Page: Will display all the American league stadiums
// on the league tab of the view information page. (tableView_allLeagues)
void MainWindow::on_button_AmericanLeague_clicked()
{
    auto model = Database::getInstance()->getAmericanLeagueStadiums();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("League"));
    ui->tableView_allLeagues->setModel(model);
    ui->tableView_allLeagues->verticalHeader()->setVisible(false);
//    ui->tableView_allLeagues->resizeColumnsToContents();
}

// View Information Page: Will display all the National league stadiums
// on the league tab of the view information page. (tableView_allLeagues)
void MainWindow::on_button_NationalLeague_clicked()
{
    auto model = Database::getInstance()->getNationalLeagueStadiums();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("League"));
    ui->tableView_allLeagues->setModel(model);
    ui->tableView_allLeagues->verticalHeader()->setVisible(false);
//    ui->tableView_allLeagues->resizeColumnsToContents();

}

// View Information Page: Will display all the stadiums and their league
// on the league tab of the view information page. (tableView_allLeagues)
void MainWindow::on_button_allLeague_clicked()
{
    auto model = Database::getInstance()->getAllLeagues();
    model->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Teams"));
    model->setHeaderData(2, Qt::Horizontal, tr("League"));
    ui->tableView_allLeagues->setModel(model);
    ui->tableView_allLeagues->verticalHeader()->setVisible(false);
//    ui->tableView_allLeagues->resizeColumnsToContents();
}

// View Information Page: Will display all the souvenirs and the team
// they are associated to and their price. (tableView_allSouvenirs)
void MainWindow::on_button_allSouvenirs_clicked()
{
    auto model = Database::getInstance()->getAllSouvenirs();
    model->setHeaderData(0, Qt::Horizontal, tr("Item"));
    model->setHeaderData(1, Qt::Horizontal, tr("Price"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team Name"));
    ui->tableView_allSouvenirs->setModel(model);
    ui->tableView_allSouvenirs->verticalHeader()->setVisible(false);
//    ui->tableView_allSouvenirs->resizeColumnsToContents();
}

// View Information Page: Will change the table on the team page to show
// the souvenirs available and their listed price for a specific team.
// (tableView_allSouvenirs)
void MainWindow::on_comboBox_specificTeam_currentIndexChanged(int index)
{
    QString modelChange = ui->comboBox_specificTeam->currentText();
    auto model = Database::getInstance()->getAllSouvenirsWithTeam(modelChange);
    model->setHeaderData(0, Qt::Horizontal, tr("Item"));
    model->setHeaderData(1, Qt::Horizontal, tr("Price"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team Name"));
    ui->tableView_allSouvenirs->setModel(model);
    ui->tableView_allSouvenirs->verticalHeader()->setVisible(false);
//    ui->tableView_allSouvenirs->resizeColumnsToContents();
}

// Admin Welcome Page: Will send to the admin souvenir management page
// where the admin can change the price, add a souvenir, delete a souvenir,
// or modify a souvenir.
void MainWindow::on_button_souvenirManagement_clicked()
{
    ui->comboBox_adminSouvTeam->clear();

    //Disables all buttons and price LineEdit when clicked from admin UI
    ui->pushButton_AddSouv->setDisabled(true);
    ui->pushButton_DeleteSouv->setDisabled(true);
    ui->pushButton_EditSov->setDisabled(true);
    ui->doubleSpinBox_souvPrice->setDisabled(true);
    ui->label_AddError->setVisible(false);

    //Sets up the combo box on the souvneir page
    QStringList teamlist = Database::getInstance()->getTeamsComboBox();
    ui->comboBox_adminSouvTeam->addItems(teamlist);

    // Initialize the tables for the page
    auto model = Database::getInstance()->getAllSouvenirsWithTeam(teamlist.at(0));
    model->setHeaderData(0, Qt::Horizontal, tr("Item"));
    model->setHeaderData(1, Qt::Horizontal, tr("Price"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team Name"));
    ui->tableView_adminSouv->setModel(model);
    ui->tableView_adminSouv->verticalHeader()->setVisible(false);
    ui->tableView_adminSouv->resizeColumnsToContents();
    ui->tableView_adminSouv->setColumnWidth(1, 70);

    SetIndex(AdminSouvenirManagementPage);
}

// Admin Welcome Page: Will send to the admin stadium management page
// where the admin can add a stadium, delete a stadium or modify a
// stadium.
void MainWindow::on_button_stadiumManagement_clicked()
{

    //Disables all buttons and price LineEdit when clicked from admin UI
    ui->pushButton_stadAdd->setDisabled(true);
    ui->pushButton_stadDelete->setDisabled(true);


    QSqlTableModel *model = new QSqlTableModel(this, *Database::getInstance());
    model->setTable("Stadiums");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    ui->tableView_adminStad->setModel(model);
    ui->tableView_adminStad->setUpdatesEnabled(true);

    SetIndex(AdminStadiumManagementPage);
}

// Admin Welcome Page: Will load information from a 'file' to
// the database.
void MainWindow::on_button_loadFile_clicked()
{
    // If statement will prevent the file being loaded twice
    if(!Database::getInstance()->ifExistsOnStadiumsTable("Las Vegas Stadium")){
        ui->label_fileLoaded->setText("The File has been loaded \ninto the database.\n\nClick \'View Database Tables\'\nto view changes.");

        // Reads from a file and adds the information to the database
        Database::getInstance()->addStadiumFromFile("assets/new-stadium.json");

        // Insert into Souvenirs Table the default souvenirs
        Database::getInstance()->insertNewTeamSouvenirs("Las Vegas Gamblers");
    }else{
        ui->label_fileLoaded->setText("Hey!\n\nThe file has already\nbeen loaded before!\n\nClick \'View Database Tables\'\nto view changes.");
    }
}

// Admin Welcome Page: Will send you to the view tables page
// where the admin can view all the information in the database
// (Preferably to see the changes from loading the file)
void MainWindow::on_button_viewTables_clicked()
{
    SetIndex(ViewTablesPage);

    auto model = Database::getInstance()->getAllInformation();
    ui->tableView_stadiumsTable->setModel(model);

    model = Database::getInstance()->getAllSouvenirs();
    ui->tableView_souvenirsTable->setModel(model);

    model = Database::getInstance()->getAllDistances();
    ui->tableView_distancesTable->setModel(model);
}

// Admin Welcome Page: Will send you back to the main window
// prevents you from using admin features
void MainWindow::on_button_logOut_clicked()
{
    adminLoggedIn = false;
    visitedPages.clear();
    SetIndex(WelcomePage);
}

// Souvenir Management Page: This will load the tableView with the
// selected Team from the comboBox.  (tableView_adminSouv)
void MainWindow::on_comboBox_adminSouvTeam_currentTextChanged(const QString &arg1)
{
    // Initialize the tables for the page
    auto model = Database::getInstance()->getAllSouvenirsWithTeam(arg1);
    model->setHeaderData(0, Qt::Horizontal, tr("Item"));
    model->setHeaderData(1, Qt::Horizontal, tr("Price"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team Name"));
    ui->tableView_adminSouv->setModel(model);
    ui->tableView_adminSouv->verticalHeader()->setVisible(false);
    ui->tableView_adminSouv->resizeColumnsToContents();
    ui->tableView_adminSouv->setColumnWidth(1, 70);
}

// Souvenir Management Page: This LineEdit will be used to have the user enter the
// name of the souvenir. Chgaracters and whitespaces are only allowed. Will save
// the souvenir name to variable.
void MainWindow::on_lineEdit_adminSouvName_textChanged(const QString &arg1)
{
    //Sets the Regex for the LineEdit input
    //This will only accept Upper and lower case characters and whitespaces
    QRegExp rx("[A-Za-z\\s]+");
    ui->lineEdit_adminSouvName->setValidator( new QRegExpValidator(rx, this));

    //Disables the Delete button and Enables the Price LineEdit
    ui->pushButton_DeleteSouv->setEnabled(false);
    ui->doubleSpinBox_souvPrice->setEnabled(true);

    // If Arg1 exists on souvenirs database, then enable delete button and
    // enable spin box if not already enabled. Otherwise, allow the
    // user to add it.
    if(Database::getInstance()->ifExistsOnSouvenirsTable(arg1)){
        ui->pushButton_DeleteSouv->setEnabled(true);
    }

    ui->doubleSpinBox_souvPrice->setEnabled(true);
}


// Souvenir Management Page: This button when clicked will ADD a new souvenir to the database.
// It will also clear the LineEdits after insertion. Will call a method defined in Database.
// Will check to see if the new souvenir is already in the list.
// (tableView_adminSouv)
void MainWindow::on_pushButton_AddSouv_clicked()
{
    QString compare = ui->lineEdit_adminSouvName->text();
    //Will check to see if the new souvenir is part of the default list.
    if(compare != "Baseball Cap" && compare != "Baseball Bat" && compare != "Team Pennant" &&
       compare != "Autographed Baseball" && compare != "Team Jersey"){

        //Calls the Add method in the Database
        Database::getInstance()->addSouvenir(compare,
                                             ui->doubleSpinBox_souvPrice->value(),
                                             ui->comboBox_adminSouvTeam->currentText());

        // Initialize the tables for the page
        auto model = Database::getInstance()->getAllSouvenirsWithTeam(ui->comboBox_adminSouvTeam->currentText());
        model->setHeaderData(0, Qt::Horizontal, tr("Item"));
        model->setHeaderData(1, Qt::Horizontal, tr("Price"));
        model->setHeaderData(2, Qt::Horizontal, tr("Team Name"));
        ui->tableView_adminSouv->setModel(model);
        ui->tableView_adminSouv->verticalHeader()->setVisible(false);

        ui->label_AddError->setVisible(false); //Hides red error

    }else{
        ui->label_AddError->setVisible(true);  //Displays red error on page
    }

    //Clears and disables all buttons on page after clicked
    ui->lineEdit_adminSouvName->clear();
    ui->doubleSpinBox_souvPrice->setValue(0.0);
    ui->pushButton_AddSouv->setDisabled(true);
    ui->pushButton_DeleteSouv->setDisabled(true);
    ui->pushButton_EditSov->setDisabled(true);
    ui->doubleSpinBox_souvPrice->setDisabled(true);
}

// Souvenir Management Page: This button when clicked will EDIT a souvenir and update the database file.
// It will also clear the LineEdits after insertion. Will call a method defined in Database.
// (tableView_adminSouv)
void MainWindow::on_pushButton_EditSov_clicked()
{
    //Calls the Edit method defined in Database
    Database::getInstance()->editSouvenir(ui->lineEdit_adminSouvName->text(),
                                          ui->doubleSpinBox_souvPrice->value(),
                                          ui->comboBox_adminSouvTeam->currentText());

    //Clears and disables all buttons on page after clicked
    ui->lineEdit_adminSouvName->clear();
    ui->doubleSpinBox_souvPrice->setValue(0.0);
    ui->pushButton_AddSouv->setDisabled(true);
    ui->pushButton_DeleteSouv->setDisabled(true);
    ui->pushButton_EditSov->setDisabled(true);
    ui->doubleSpinBox_souvPrice->setDisabled(true);

    // Initialize the tables for the page
    auto model = Database::getInstance()->getAllSouvenirsWithTeam(ui->comboBox_adminSouvTeam->currentText());
    model->setHeaderData(0, Qt::Horizontal, tr("Item"));
    model->setHeaderData(1, Qt::Horizontal, tr("Price"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team Name"));
    ui->tableView_adminSouv->setModel(model);
    ui->tableView_adminSouv->verticalHeader()->setVisible(false);
}

// Souvenir Management Page: This button when clicked will DELETE a souvenir and remove it from the database file.
// It will also clear the LineEdits after insertion. Will call a method defined in Database.
// (tableView_adminSouv)
void MainWindow::on_pushButton_DeleteSouv_clicked()
{
    //Calls the Delete method defined in Database
    Database::getInstance()->deleteSouvenir(ui->lineEdit_adminSouvName->text(), ui->comboBox_adminSouvTeam->currentText());

    //Clears and disables all buttons on page after clicked
    ui->lineEdit_adminSouvName->clear();
    ui->doubleSpinBox_souvPrice->setValue(0.0);
    ui->pushButton_AddSouv->setDisabled(true);
    ui->pushButton_DeleteSouv->setDisabled(true);
    ui->pushButton_EditSov->setDisabled(true);
    ui->doubleSpinBox_souvPrice->setDisabled(true);

    // Initialize the tables for the page
    auto model = Database::getInstance()->getAllSouvenirsWithTeam(ui->comboBox_adminSouvTeam->currentText());
    model->setHeaderData(0, Qt::Horizontal, tr("Item"));
    model->setHeaderData(1, Qt::Horizontal, tr("Price"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team Name"));
    ui->tableView_adminSouv->setModel(model);
    ui->tableView_adminSouv->verticalHeader()->setVisible(false);
}

// Souvenir Management Page: Will fill the line edit with the information at the clicked index.
void MainWindow::on_tableView_adminSouv_clicked(const QModelIndex &index)
{
    QModelIndex souvIndex  = index.sibling(index.row(), 0);
    QModelIndex priceIndex = index.sibling(index.row(), 1);

    ui->lineEdit_adminSouvName->setText(ui->tableView_adminSouv->model()->data(souvIndex).toString());
    ui->doubleSpinBox_souvPrice->setValue(ui->tableView_adminSouv->model()->data(priceIndex).toDouble());
    ui->doubleSpinBox_souvPrice->setEnabled(true);
}

// Souvenir Management Page: Is the indication that a price has been changed
// or added for a team.
void MainWindow::on_doubleSpinBox_souvPrice_valueChanged(double arg1)
{
    if(Database::getInstance()->ifExistsOnSouvenirsTable(ui->lineEdit_adminSouvName->text())){
        ui->pushButton_EditSov->setEnabled(true);
    }else{
        if(ui->doubleSpinBox_souvPrice->value() > 0.0){
            ui->pushButton_AddSouv->setEnabled(true);
        }
    }
}

// Stadium Management Page: If the line edit has been changed, it will check
// if the text on the line edit is on the Stadiums Database or not.
// If it is, they will allow the user to delete, if not it will allow
// the user to add.
void MainWindow::on_lineEdit_adminStad_textChanged(const QString &arg1)
{
    if(arg1.length() > 0){
        if(Database::getInstance()->ifExistsOnStadiumsTable(arg1)){
            ui->pushButton_stadDelete->setEnabled(true);
            ui->pushButton_stadAdd->setDisabled(true);
        }else{
            ui->pushButton_stadAdd->setEnabled(true);
            ui->pushButton_stadDelete->setDisabled(true);
        }
    }
}

// Stadium Management Page: Will fill the adminStad line edit with the
// stadium name that the user clicked on.
void MainWindow::on_tableView_adminStad_clicked(const QModelIndex &index)
{
    QModelIndex stadIndex  = index.sibling(index.row(), 0);

    ui->lineEdit_adminStad->setText(ui->tableView_adminStad->model()->data(stadIndex).toString());
}

// Stadium Management Page: Will delete a record from the database of the
// stadium name that is in the line edit.
void MainWindow::on_pushButton_stadDelete_clicked()
{
    Database::getInstance()->deleteStadium(ui->lineEdit_adminStad->text());
    ui->lineEdit_adminStad->clear();

    QSqlTableModel *model = new QSqlTableModel(this, *Database::getInstance());
    model->setTable("Stadiums");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    ui->tableView_adminStad->setModel(model);
    ui->tableView_adminStad->setUpdatesEnabled(true);
}

// Stadium Management Page: Will add a record to the database with the
// stadium name that is in the line edit.
void MainWindow::on_pushButton_stadAdd_clicked()
{
    Database::getInstance()->addStadium(ui->lineEdit_adminStad->text());
    ui->lineEdit_adminStad->clear();

    QSqlTableModel *model = new QSqlTableModel(this, *Database::getInstance());
    model->setTable("Stadiums");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView_adminStad->setModel(model);
}

//Information page: displays a specfic team with all of the information
void MainWindow::on_comboBox_selectTeam_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox_selectTeam->currentText() != "Select a team to view")
    {
        auto model1 = Database::getInstance()->getTeamInformation(ui->comboBox_selectTeam->currentText());
        model1->setHeaderData(0, Qt::Horizontal, tr("Stadium Name"));
        model1->setHeaderData(1, Qt::Horizontal, tr("Capacity"));
        model1->setHeaderData(2, Qt::Horizontal, tr("Address"));
        model1->setHeaderData(3, Qt::Horizontal, tr("Surface"));
        model1->setHeaderData(4, Qt::Horizontal, tr("Team"));
        model1->setHeaderData(5, Qt::Horizontal, tr("Date Opened"));
        model1->setHeaderData(6, Qt::Horizontal, tr("Typology"));
        model1->setHeaderData(7, Qt::Horizontal, tr("League"));
        ui->tableView_allInformation->setModel(model1);
        ui->tableView_allInformation->setSortingEnabled(true);
        ui->tableView_allInformation->verticalHeader()->setVisible(false);
    }
}

void MainWindow::on_pushButton_AddInitialSouvenirs_clicked()
{
    Database::getInstance()->insertNewTeamSouvenirs(ui->comboBox_adminSouvTeam->currentText());

    // Reinitialize the tables for the page
    auto model = Database::getInstance()->getAllSouvenirsWithTeam(ui->comboBox_adminSouvTeam->currentText());
    model->setHeaderData(0, Qt::Horizontal, tr("Item"));
    model->setHeaderData(1, Qt::Horizontal, tr("Price"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team Name"));
    ui->tableView_adminSouv->setModel(model);
    ui->tableView_adminSouv->verticalHeader()->setVisible(false);
    ui->tableView_adminSouv->resizeColumnsToContents();
    ui->tableView_adminSouv->setColumnWidth(1, 70);
}
