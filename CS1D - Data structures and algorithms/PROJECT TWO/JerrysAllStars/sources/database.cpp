#include "database.h" //includes QSqlDatabase
#include <QFileInfo>


// To access the databse anywhere, include the header file ex: "headers\database.h"
// To reference the databse, use the syntax ex: Database::getInstance()->functionName()

Database* Database::instance = nullptr; // Static pointer to the database (global)
// This should be the only global variable/pointer
// This is also an example of lazy initialization (database expression for the way we initialized).

#include <cassert>
// Default constructor that will OPEN the database. If it succeeds there will
// be console output.
// Private Constructor because you do not want anyone to instantiate a new Database
Database::Database(): QSqlDatabase(addDatabase("QSQLITE"))
{
    this->setDatabaseName("./assets/AllStarDatabase.db");
    QFileInfo existingDatabaseInfo ("./assets/AllStarDatabase.db");

    if(existingDatabaseInfo.exists()){
        qDebug() << "Database file is open\n";
        this->open();
        QSqlQuery query;
        query.prepare("PRAGMA foreign_keys = ON;");
        query.exec();
    }else{
        qDebug() << "Database file not open.\n";
    }
}

// This will return a pointer to the database and is static.
Database* Database::getInstance()
{
    // if the database has not been initialized, initialize it.
    if(instance == nullptr){
        instance = new Database;
    }
    return instance;
}

// Will return a model of all the information for a specific team.
QSqlQueryModel* Database::getTeamInformation(QString teamName)
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT * FROM Stadiums WHERE team = \"" + teamName +"\";";
    model->setQuery(string);
    return model;
}

// Will return a model with all the stadiums with the passed in typology
QSqlQueryModel* Database::getAllTypologyWith(QString typeName)
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, typology FROM Stadiums WHERE typology = \"" + typeName +"\";";
    model->setQuery(string);
    return model;
}

// Will return a model with all of the Stadiums table information.
QSqlQueryModel* Database::getAllInformation()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT * FROM Stadiums;";
    model->setQuery(string);
    return model;
}

// Will return a model with all the stadiums and their team names
QSqlQueryModel* Database::getTeamsAndStadiums()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT team, name FROM Stadiums ORDER BY team;";
    model->setQuery(string);
    return model;
}

// Will return a model with all the team names
QSqlQueryModel* Database::getAllTeams()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT team FROM Stadiums ORDER BY team;";
    model->setQuery(string);
    return model;
}

// Will return a model with all the teams and stadiums in the American League.
QSqlQueryModel* Database::getAmericanLeagueStadiums()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, league FROM Stadiums WHERE league = \"American\" ORDER BY team;";
    model->setQuery(string);
    model->sort(2, Qt::AscendingOrder);
    return model;
}

// Will return a model with all the teams and stadiums in the National League.
QSqlQueryModel* Database::getNationalLeagueStadiums()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "Select name, team, league FROM Stadiums WHERE league = \"National\" ORDER BY name;";
    model->setQuery(string);
    return model;
}

// Will return a model with all the team names and their surface
QSqlQueryModel* Database::getTeamsWithSurface(QString surfaceType)
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT team, surface FROM Stadiums WHERE surface = \"" + surfaceType + "\";";
    model->setQuery(string);
    return model;
}

// Will get all the stadium names and return it as a model
QSqlQueryModel* Database::getAllStadiumNames()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name FROM Stadiums;";
    model->setQuery(string);
    return model;
}

// Will return a model with all the stadiums and their location
QSqlQueryModel* Database::getAllStadiumsAndLocations()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, location FROM Stadiums;";
    model->setQuery(string);
    return model;
}

// Will return a model with all the stadiums and their corresponding surfaces
QSqlQueryModel* Database::getAllSurfaces()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, surface FROM Stadiums;";
    model->setQuery(string);
    return model;
}

// Will return a model with all stadiums with grass surface
QSqlQueryModel* Database::getAllStadiumsWithGrass()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, surface FROM Stadiums WHERE surface = \"Grass\" ORDER BY team;";
    model->setQuery(string);
    return model;
}

// Will return a model with all stadiums without grass surface
QSqlQueryModel* Database::getAllStadiumsWithoutGrass()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, surface FROM Stadiums WHERE surface is not \"Grass\";";
    model->setQuery(string);
    return model;
}

// Will return a model with all the stadium capacities and corresponding stadiums
QSqlQueryModel* Database::getAllCapacity()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, capacity FROM Stadiums;";
    model->setQuery(string);
    return model;
}

// Will return a model with all the stadiums and their corresponding open dates
QSqlQueryModel* Database::getAllOpenedDates()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, opened FROM Stadiums;";
    model->setQuery(string);
    return model;
}

// Will return a model with all the stadiums and their corresponding leagues
QSqlQueryModel* Database::getAllLeagues()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, league FROM Stadiums;";
    model->setQuery(string);
    return model;
}

// WIll return a model with all the stadiums' typology
QSqlQueryModel* Database::getAllTypology()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT name, team, typology FROM Stadiums ORDER BY typology;";
    model->setQuery(string);
    return model;
}

// Will return a model with all the souvenirs and the corresponding team
QSqlQueryModel* Database::getAllSouvenirs()
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT * FROM Souvenirs;";
    model->setQuery(string);
    return model;
}

// Will return a model with the souvenirs that correspond with the given team
QSqlQueryModel* Database::getAllSouvenirsWithTeam(QString teamName)
{
    QSqlQueryModel* model = new QSqlQueryModel;

    QString string = "SELECT * FROM Souvenirs WHERE team = \"" + teamName + "\";";
    model->setQuery(string);
    return model;
}

// returns a QSqlQueryModel of the entire Distances table from the database
QSqlQueryModel* Database::getAllDistances()
{
    QSqlQueryModel* model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Distances;");
    return model;
}

// Will get all the stadium names as a vector
std::vector<QString> Database::getAllStadiumNamesAsVector()
{
    QSqlQuery query(*this);
    query.prepare("SELECT name FROM Stadiums;");
    std::vector<QString> vec;
    if(query.exec()){
        while(query.next()){
            vec.push_back(query.value(0).toString());
        }
    }else{
        qDebug() << "\ngetAllStadiumNamesAsVector Query did not execute properly.\n";
    }
    return vec;
}

// Will return the price of the souvenir.
double Database::getPriceOf(QString souvenirName, QString teamName)
{
    QSqlQuery query(*this);
    query.prepare("SELECT price FROM Souvenirs WHERE item = ? AND team = ? ;");
    query.bindValue(0, souvenirName);
    query.bindValue(1, teamName);

    if(query.exec()){
        query.first();
        return query.value(0).toDouble();
    }else{
        qDebug() << "\ngetPrice Query did not execute properly.\n";
        return 0.0;
    }
}

// Will return a list to initialize a combo box of typology
QStringList Database::getTeamsComboBox()
{
    QSqlQuery query(*this);
    QString team;
    QStringList list;

    query.prepare("SELECT team FROM Stadiums ORDER BY team;");
    if(query.exec()){
        while(query.next()){
            team = query.value("team").toString();
            list << team;
        }
    }else{
        qDebug() << "\ngetTeamsComboBox Query did not execute properly.\n";
    }

    return list;
}

// Will return a list to initialize a combobox of typology
QStringList Database::getTypologyComboBox()
{
    QSqlQuery query(*this);
    QString typeology;
    QStringList list;

    query.prepare("SELECT typology FROM Stadiums ORDER BY typology;");
    if(query.exec()){
        while(query.next()){
            if(!list.contains(query.value("typology").toString())){
                typeology = query.value("typology").toString();
                list << typeology;
            }
        }
    }else{
        qDebug() << "\ngetTypologyComboBox Query did not execute properly.\n";
    }

    return list;
}

// Will return a vector of all the sadiums that the fromStadiumName can get to.
std::vector<QString> Database::getToStadiumNames(QString fromStadiumName)
{
    QSqlQuery query(*this);
    query.prepare("SELECT toStadiumName FROM Distances WHERE fromStadiumName = ?;");
    query.bindValue(0, fromStadiumName);

    std::vector<QString> toStadiums;

    if(query.exec()){
        while(query.next()){
            toStadiums.push_back(query.value(0).toString());
        }
    }else{
        qDebug() << "\ngetToStadiumNames Query did not execute properly.\n";
    }

    return toStadiums;
}

// Will return the weight between two stadiums if they have a weight between.
int Database::getWeightBetween(QString fromStadiumName, QString toStadiumName)
{
    QSqlQuery query(*this);
    query.prepare("SELECT distancemiles FROM Distances WHERE fromStadiumName = ? AND toStadiumName = ?;");
    query.bindValue(0, fromStadiumName);
    query.bindValue(1, toStadiumName);

    if(query.exec()){
        query.next();
        return query.value(0).toInt();
    }else{
        return -1;
    }
}

// Will check if passed in stadium name exists on the Stadiums table
bool Database::ifExistsOnStadiumsTable(QString stadiumName)
{
    QSqlQuery query(*this);
    query.prepare("SELECT * FROM Stadiums WHERE name = ?;");
    query.bindValue(0, stadiumName);
    if(query.exec()){
        return query.next();
    }else{
        return false;
    }
}

// Will determine if a souvenir exists on the Souvenirs table in the database.
bool Database::ifExistsOnSouvenirsTable(QString souvenirName)
{
    QSqlQuery query(*this);
    query.prepare("SELECT * FROM Souvenirs WHERE item = ?;");
    query.bindValue(0, souvenirName);
    if(query.exec()){
        return query.next();
    }else{
        return false;
    }
}

// Will return the team name of the stadium
QString Database::getTeam(QString stadiumName)
{
    QSqlQuery query(*this);
    query.prepare("SELECT team FROM Stadiums WHERE name  = ?;");
    query.bindValue(0, stadiumName);
    if(query.exec()){
        query.first();
        return query.value(0).toString();
    }else{
        qDebug() <<  "\ngetTeam query did not execute properly!\n";
        return " ";
    }
}

// Will be adding a new souvenir to the database.
void Database::addSouvenir( QString souvenir, double price, QString teamName ){

    QSqlQuery query(*this);

    /// SQL Command to be executed
    query.prepare("INSERT INTO Souvenirs (item, price, team) VALUES ( ? , ? , ? );");
    query.bindValue(0, souvenir);
    query.bindValue(1, price);
    query.bindValue(2, teamName);

    if(!query.exec()){
        qDebug() << "\n Adding Souvenir has FAILED!\n";
    }
}

// Will be editing an existing souvenir of the database. The price is the only thing
// that can be changed.
void Database::editSouvenir(QString souvenir, double price, QString teamName){

    QSqlQuery query(*this);

    /// SQL Command to be executed
    query.prepare("UPDATE Souvenirs SET price = ? WHERE item = ? AND team = ?;");
    query.bindValue(0, price);
    query.bindValue(1, souvenir);
    query.bindValue(2, teamName);

    if(!query.exec()){
        qDebug() << "\n Editing Souvenir price has FAILED!\n";
    }
}

// Will be removing a souvenir from the databasefile.
void Database::deleteSouvenir(QString souvenir, QString teamName){

    QSqlQuery query(*this);

    query.prepare("DELETE FROM Souvenirs WHERE item = ? AND team =?;");
    query.bindValue(0, souvenir);
    query.bindValue(1, teamName);

    if(!query.exec()){
        qDebug() << "\n Deleting Souvenir has FAILED!\n";
    }
}

// Will add a stadium to the database.
void Database::addStadium(const QString& stadiumName, const int& seatCapacity,
                          const QString& location,    const QString& surface,
                          const QString& teamName,    const int& openingYear,
                          const QString& typology,    const QString& league)
{
    QSqlQuery query(*this);

    query.prepare("INSERT INTO Stadiums(name, capacity, location, surface, "
                                       "team, opened, typology, league) "
                                "Values(:name, :capacity, :location, :surface, "
                                       ":team, :opened, :typology, :league)");
    query.bindValue(":name", stadiumName);
    query.bindValue(":capacity", seatCapacity);
    query.bindValue(":location", location);
    query.bindValue(":surface", surface);
    query.bindValue(":team", teamName);
    query.bindValue(":opened", openingYear);
    query.bindValue(":typology", typology);
    query.bindValue(":league", league);

    // add the stadium with its information
    assert(query.exec());
}

// Will add undirected distances between stadiums to the database
void Database::addDistance(const QString& originStadium, const int& distance,
                           const QString& destinationStadium)
{
    QSqlQuery query(*this);

    query.prepare("INSERT INTO Distances(fromStadiumName, distancemiles, "
                                        "toStadiumName) "
                                 "Values(:origin, :distance, "
                                        ":destination)");
    query.bindValue(":origin", originStadium);
    query.bindValue(":distance", distance);
    query.bindValue(":destination", destinationStadium);

    // add the path to the database
    assert(query.exec());
}

// Will add stadiums from a file.
void Database::addStadiumFromFile(const QString& filename)
{
    // ensure we can open the given file
    QFile fileInfo(filename);
    assert(fileInfo.open(QIODevice::ReadOnly));

    // extract the JSON object from the file
    const auto stadium = QJsonDocument::fromJson(fileInfo.readAll()).object();

    // get the necessary information from the file
    const auto stadiumName     = stadium["Stadium Name"].toString();
    const auto seatingCapacity = stadium["Seating Capacity"].toInt();
    const auto location        = (stadium["City"].toString() + ", " +
                                  stadium["State"].toString());
    const auto surface         = stadium["Surface"].toString();
    const auto teamName        = stadium["Team Name"].toString();
    const auto openingYear     = stadium["Date Opened"].toInt();
    const auto fieldTypology   = stadium["Typology"].toString();
    const auto league          = stadium["League"].toString();

    addStadium(stadiumName, seatingCapacity, location, surface, teamName,
               openingYear, fieldTypology, league);

    // get each path from the array of destinations
    for (const auto& path : stadium["Destinations"].toArray()) {
        // there will be only one object per path
        auto it = path.toObject().constBegin();

        // add the path as undirected
        addDistance(stadiumName, it.value().toInt(), it.key());
        addDistance(it.key(), it.value().toInt(), stadiumName);
    }
}

// Will insert the initial souvenirs for every team to the new added team
void Database::insertNewTeamSouvenirs(QString teamName)
{
    QSqlQuery query(*this);
    std::vector<QString> initialItems = {"Baseball Cap","Baseball Bat","Team Pennant","Autographed Baseball","Team Jersey"};
    std::vector<double> initialItemPrices = {26.99, 49.39, 11.99, 29.99, 88.99};
    for(int i = 0; i < 5; i++){
        query.prepare("INSERT INTO Souvenirs (item, price, team) VALUES (?,?,?);");
        query.bindValue(0, initialItems.at(i));
        query.bindValue(1, initialItemPrices.at(i));
        query.bindValue(2, teamName);
        query.exec();
    }

}

// Will delete a record with the passed in stadium name in the Stadiums Table
void Database::deleteStadium(QString stadiumName)
{
    QSqlQuery query(*this);
    query.prepare("DELETE FROM Stadiums WHERE name = ?;");
    query.bindValue(0, stadiumName);
    if(!query.exec()){
        qDebug() << "\ndeleteStadium query did not execute properly!\n";
    }

}

// Will add a record with the passed in stadium name in to the Stadiums Table
void Database::addStadium(QString stadiumName)
{
    QSqlQuery query(*this);
    query.prepare("INSERT INTO Stadiums (name) VALUES (?);");
    query.bindValue(0, stadiumName);
    if(!query.exec())
    {
        qDebug() << "\naddStadium query did not execute properly!\n";
    }
}

int Database::totalCapacity()
{
    QSqlQuery query(*this);
    query.prepare("SELECT SUM(capacity) FROM Stadiums;");

    if(query.exec())
    {
       query.first();
       return query.value(0).toInt();
    }
    else
    {
        return 0;
        qDebug() << "\ntotalCapacity query did no execute properly!\n";
    }

    return 0;
}

int Database::totalGrass()
{
    QSqlQuery query(*this);
    query.prepare("SELECT COUNT(surface) FROM Stadiums WHERE surface = \"Grass\";");

    if(query.exec())
    {
       query.first();
       return query.value(0).toInt();
    }
    else
    {
        return -1;
        qDebug() << "\ntotalGrass query did no execute properly!\n";
    }

    return -1;
}
