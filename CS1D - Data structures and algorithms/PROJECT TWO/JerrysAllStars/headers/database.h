#ifndef DATABASE_H
#define DATABASE_H

#include <QByteArray>
#include <QDebug>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <vector>

/**
 * @brief The Database class represents SQL database and the queries needed to display or change information
 *  stored in the database. Implemented as singleton model.
 */
class Database: public QSqlDatabase
{
public:

    /**
    * @brief getInstance A static method that returns a static pointer to the database. Allows
    * the database to be accessed anywhere.
    * @return instance A static Database pointer.
    */
    static Database* getInstance();

    /**
     * @brief getTeamInformation will return QSqlQueryModel with all of the Stadiums table
     * information based on teamName.
     * @param teamName the team name to return information corresponding to it
     * @return model with team name's information.
     */
    QSqlQueryModel* getTeamInformation(QString teamName);

    /**
     * @brief getAllTypologyWith will return a model of all the stadiums with the specified
     * typology that is passed in.
     * @param typeName the typeology of the stadiums to return a model of
     * @return a QSqlQueryModel of all the stadiums with the passed in typology.
     */
    QSqlQueryModel* getAllTypologyWith(QString typeName);

    /**
     * @brief getAllInformation will return QSqlQueryModel with all of the Stadiums table information
     * @return model with all the stadium and team name information.
     */
    QSqlQueryModel* getAllInformation();

    /**
     * @brief getTeamsAndStadiums will return a QSqlQueryModel with all the teams and stadiums
     * from the Stadiums table.
     * @return model with all the stadiums and teams
     */
    QSqlQueryModel* getTeamsAndStadiums();

    /**
     * @brief getAllTeams will return a model with all the team names
     * @return a QSqlQueryModel with all the team names
     */
    QSqlQueryModel* getAllTeams();

    /**
     * @brief getAmericanLeagueTeamsAndStadiums will return a QSqlQueryModel with all the
     * American league teams and stadium information.
     * @return model with all the american league information
     */
    QSqlQueryModel* getAmericanLeagueStadiums();

    /**
     * @brief getNationalLeagueTeamsAndStadiums will return a QSqlQueryModel with all the
     * National league teams and stadium information.
     * @return model with all the national league information
     */
    QSqlQueryModel* getNationalLeagueStadiums();

    /**
     * @brief getTeamsWithSurface will return QSqlQueryModel with teams that have stadium surfaces
     * with what ever passed in surfaceType
     * @param surfaceType the type of stadium surface, grass or astroturf
     * @return model with teams and their stadium surface type
     */
    QSqlQueryModel* getTeamsWithSurface(QString surfaceType);

    /**
     * @brief getAllStadiumNames will return a model of all the stadiums
     * in the Stadiums table of the database
     * @return a QSqlQueryModel of all the stadium names.
     */
    QSqlQueryModel* getAllStadiumNames();

    /**
     * @brief getAllStadiumsAndLocation will return a model of all the
     * stadium names and their location
     * @return a QSqlQueryModel of all the stadium locations
     */
    QSqlQueryModel* getAllStadiumsAndLocations();

    /**
     * @brief getAllSurfaces will return a model of all the stadiums and their surfaces
     * @return a QSqlQueryModel of all the stadium surfaces
     */
    QSqlQueryModel* getAllSurfaces();

    /**
     * @brief getAllStadiumsWithGrass will return a model of all the stadiums
     * and their surface if it is grass
     * @return a QSqlQueryModel with all the stadiums with grass surface
     */
    QSqlQueryModel* getAllStadiumsWithGrass();

    /**
     * @brief getAllStadiumsWithoutGrass will return a model of all the stadiums
     * and their surface if it isn't grass
     * @return a QSqlQueryModel with all the stadiums without grass surface
     */
    QSqlQueryModel* getAllStadiumsWithoutGrass();

    /**
     * @brief getALlCapacity will return a model of all the stadiums and their capacity
     * @return a QSqlQueryModel of all the stadium capacities
     */
    QSqlQueryModel* getAllCapacity();

    /**
     * @brief getAllOpenedDates will return a model of all the stadiums and their open dates
     * @return a QSqlQueryModel of all the stadium open dates
     */
    QSqlQueryModel* getAllOpenedDates();

    /**
     * @brief getAllLeagues will return a model of all the stadiums and their league
     * @return a QSqlQueryModel of all the stadium leagues
     */
    QSqlQueryModel* getAllLeagues();

    /**
     * @brief getAllTypology will return a model of all the stadiums and their typology
     * @return a QSqlQueryModel of all the stadium typologies
     */
    QSqlQueryModel* getAllTypology();

    /**
     * @brief getAllSouvenirs will return a model of all the Souvenirs table contents
     * @return a QSqlQueryModel of all the team souvenirs
     */
    QSqlQueryModel* getAllSouvenirs();

    /**
     * @brief getAllSouvenirsWithTeam will return a model of all the souvenirs by
     * the given team name.
     * @param teamName for all the souvenirs with the given team name.
     * @return a QSqlQueryModel of all the souvenirs for sale sponsored by the given
     * team name.
     */
    QSqlQueryModel* getAllSouvenirsWithTeam(QString teamName);

    /**
     * @brief getAllDistances will return a model of all the information
     * in the Distances table of the database.
     * @return a QSqlQueryModel of all the information inside the
     * Distances table.
     */
    QSqlQueryModel* getAllDistances();

    /**
     * @brief getAllStadiumNamesAsVector will return the all the
     * names of the stadiums as a vector
     * @return a vector of qstrings which are the names of all the stadiums
     */
    std::vector<QString> getAllStadiumNamesAsVector();

    /**
     * @brief getPriceOf will find the price of a specific souvenir.
     * @param souvenirName name of the souvenir of the price to be returned
     * @param teamName the team name that the souvenir belongs to
     * @return the price of the souvenir belonging to the team
     */
    double getPriceOf(QString souvenirName, QString teamName);

    /**
     * @brief getTeamsComboBox Will return a list to populate a combobox of teams
     * @return a QStringList of team names
     */
    QStringList getTeamsComboBox();

    /**
     * @brief getTypologyComboBox Will return a list to populate a
     * combobox of typologies
     * @return a QStringList of stadium typologies
     */
    QStringList getTypologyComboBox();

    /**
     * @brief getToStadiumNames will return a list of all the stadiums that
     * the fromStadiumName connects to.
     * @param fromStadiumName name to check where all the connections are
     * @return vector of all the to stadiums.
     */
    std::vector<QString> getToStadiumNames(QString fromStadiumName);

    /**
     * @brief getWeightBetween will get the distance between two
     * stadium names from the Distances table.
     * @return the weight. -1 if there is no distance between.
     */
    int getWeightBetween(QString fromStadiumName, QString toStadiumName);

    /**
     * @brief ifExistsOnStadiumsTable will determine if the stadium name passed
     * in appears on the Stadiums Table or not.
     * @param stadiumName is the name of the stadium checked
     * @return will return true if stadium does exist on table, and false
     * if stadium does not exist on table.
     */
    bool ifExistsOnStadiumsTable(QString stadiumName);

    /**
     * @brief ifExistsOnSouvenirsTable will determine if the souvenir name passed
     * in appears on the Souvenirs table or not.
     * @param souvenirName is the name of the souvenir being checked.
     * @return will return true if the souvenir does exist on the table,
     * and false if the souvenir does not exist on table.
     */
    bool ifExistsOnSouvenirsTable(QString souvenirName);

    /**
     * @brief getTeam will find the team name with the corresponding stadium name
     * @param stadiumName the name of the stadium to retrieve the team name
     * @return a QString of the team's name that has the home stadium stadiumName
     */
    QString getTeam(QString stadiumName);

    /**
     * @brief addSouvenir will be taking in the name, price, and team name that
     * the user has entered, into this function so that it can be added to the database file.
     * @param souvenir the name of the new souvenir.
     * @param price the price of the new souvenir.
     * @param teamName the team name the new souvenir belongs to.
     */
    void addSouvenir(QString souvenir, double price, QString teamName );

    /**
     * @brief editSouvenir will be taking in the name, price, and team name that
     * the user has entered into this function so that the price of the souvenir can be changed.
     * @param souvenir the name of the souvenir to be changed.
     * @param price the new price of the souvenir.
     * @param teamName the team name of the edited souvenir.
     */
    void editSouvenir(QString souvenir, double price, QString teamName);

    /**
     * @brief deleteSouvenir will be taking in the name of the souvenir to be deleted so that
     * it can be removed from the database file.
     * @param souvenir the name of the souvenir to be deleted.
     * @param teamName the name of the team that will be deleted.
     */
    void deleteSouvenir(QString souvenir, QString teamName);

    /**
     * @brief editStadium Will take in user input and change all of the information for a specific team.
     * The team name is the only thing that cannot be changed.
     * @param teamName the team name will be used to change all of the info for.
     * @param stadiumName this will be the new stadium name.
     * @param seatCapacity this wil be the new seating capacity
     * @param location this will be the new location.
     * @param surface this will be the new field surface.
     * @param openingYear this is the opening year of new stadium.
     * @param typology this is the new typology of the stadium.
     * @param league this is the leage the team is with.
     */
    void editStadium(QString teamName, QString stadiumName, int seatCapacity,
                     QString location, QString surface, int openingYear,
                     QString typology, QString league);

    /**
     * @brief Adds a stadium with all information to the database.
     * @param stadiumName name of the stadium itself.
     * @param seatCapacity number of seats in the stadium (max capacity).
     * @param location city and state where stadium is located.
     * @param surface type of playing field surface.
     * @param teamName name of the home team.
     * @param openingYear first year the stadium was open.
     * @param typology the typology.
     * @param league the league that the home team plays in.
     */
    void addStadium(const QString& stadiumName, const int& seatCapacity,
                    const QString& location,    const QString& surface,
                    const QString& teamName,    const int& openingYear,
                    const QString& typology,    const QString& league);

    /**
     * @brief Adds a stadium and any distances to the others from a JSON file.
     * @param originStadium name of the starting stadium.
     * @param distance distance to destination stadium in miles.
     * @param destinationStadium name of the destination stadium.
     */
    void addDistance(const QString& originStadium, const int& distance,
                     const QString& destinationStadium);


    /**
     * @brief Adds a stadium and any distances to the others from a JSON file.
     * @param filename name of the JSON file.
     */
    void addStadiumFromFile(const QString& filename);

    /**
     * @brief insertNewTeamSouvenirs will insert the default 4 souvenirs to
     * the Souvenirs table for the given team name.
     * @param teamName
     */
    void insertNewTeamSouvenirs(QString teamName);

    /**
     * @brief editStadium will take in the user input for the Stadium and the new team name and
     * will change the database to have the updated move.
     * @param newTeamName this will be the new team moving into the given stadium
     * @param stadium this will be the given stadium of the change
     */
    void editStadium(QString newTeamName, QString stadium);

    /**
     * @brief deleteStadium will delete a row in database with
     * the corresponding stadiumName
     * @param stadiumName the name of the stadium to delete and its
     * correlating information
     */
    void deleteStadium(QString stadiumName);

    /**
     * @brief addStadium adds empty row with the stadium name of the passed
     * in parameter
     * @param stadiumName name of the stadium that is being added to the
     * database
     */
    void addStadium(QString stadiumName);

    /**
     * @brief totalCapacity finds total capacity
     * @return total capacity in Stadiums table
     */
    int totalCapacity();

    /**
     * @brief totalCapacity finds total number of grass stadiums
     * @return total grass stadiums in Stadiums table
     */
    int totalGrass();


private:
    /**
     * @brief Database Default constructor to open a SQL database.
     */
    Database();

    /**
     * @brief instance A static pointer variable to the database.
     */
    static Database* instance;

};

#endif // DATABASE_H
