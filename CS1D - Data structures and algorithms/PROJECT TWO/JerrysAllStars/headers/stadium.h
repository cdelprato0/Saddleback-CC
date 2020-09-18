#ifndef STADIUM_H
#define STADIUM_H

#include "database.h" // includes QSqlDatabase, QSqlQueryModel, QSqlQuery, QDebug, vector

/**
 * @brief The souvenir struct represents a souvenir purchased
 */
struct souvenir{
    /**
     * @brief souvenirName the name of the souvenir the user is purchasing
     */
    QString souvenirName;

    /**
     * @brief quantity the amount of the souvenir the user is purchasing
     */
    int quantity;
};

/**
 * @brief The Stadium represents a stadium the user is visiting
 */
struct Stadium{
    /**
     * @brief stadiumName the name of the stadium the user is visiting
     */
    QString stadiumName;

    /**
     * @brief purchasedSouvenirs the souvenirs the user is purchasing
     */
    std::vector<souvenir> purchasedSouvenirs;
};



#endif // STADIUM_H
