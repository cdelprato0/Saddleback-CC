#ifndef STADIUMVISITPLAN_H
#define STADIUMVISITPLAN_H

#include "stadium.h" // includes database.h

/**
 * @brief The StadiumVisitPlan class Manages the Users
 * stadium visit and souvenir purchases using an STL Map, and a vector
 * of stadiums and souvenirs.
 */
class StadiumVisitPlan
{
public:

    // Typedef map of maps as Graph for ease and because it is being used as a graph.
    typedef std::map<QString, std::map<QString, int>> Graph;

    /**
     * @brief StadiumVisitPlan Default constructor will initialize attributes of class
     */
    StadiumVisitPlan();
    ~StadiumVisitPlan();

    /**
     * @brief pushStadium will add a stadium that the user wants to visit by
     * converting stadium string name to a stadium
     * @param stadiumName the name of the stadium that is added to the vector.
     */
    void pushStadium(QString stadiumName);

    /**
     * @brief pushStadium will add a stadium that the user wants to visit by
     * adding a stadium to the vector.
     * @param stadiumInsert a stadium to insert
     */
    void pushStadium(Stadium stadiumInsert);

    /**
     * @brief Dijkstras Will preform Dijikstras (Shortest trip) by creating a graph of
     * the current plan, and sorting it for shortest trip.
     */
    void Dijkstras();

    /**
     * @brief Dijkstras Uses an STL Map like a python graph (lol) to sort by shortest distance, also
     * uses a stack to store the path and push off the stack to put it in order.
     * @param start From point A
     * @param ends to point B (any QString on the endsVector found first is point B)
     * @param distance is the total distance from point A to B of the path.
     * @return a vector of QString that represents the path.
     */
    std::vector<QString> Dijkstras(QString start, std::vector<QString> ends, int &distance);

    // Prims or Kruskals:  Prims is implemented
    /**
     * @brief MST will call prims for the Minimum spanning tree.
     * @return vector representing the stadiums in an MST
     */
    std::vector<QString> MST();

    /**
     * @brief pushSouvenir will add a souvenir to the index passed
     * in's souvenir vector. By changing the string to a souvenir object
     * @param souvenirName the name of the souvenir
     * @param index index where the souvenir will be added.
     */
    void pushSouvenir(QString souvenirName, int index);

    /**
     * @brief pushSouvenir will add a souvenir to the index passed
     * in's souvenir vector.
     * @param souvenirInsert the souvenir to be inserted
     * @param index index of the souvenir to be inserted
     */
    void pushSouvenir(souvenir souvenirInsert, int index);

    /**
     * @brief changeQuantityAt will change the amount of souvenirs purchased at
     * index of the plan vector that is passed in.
     * @param planIndex the plan vector index
     * @param souvenirName name of the souvenir to increase the quantity of
     * @param quantity the new amount of souvenirs purchased
     */
    void changeQuantityAt(int planIndex,QString souvenirName, int quantity);

    /**
     * @brief removeSouvenirAt will remove a souvenir from the purchased
     * souvenir vector at the given plan vector index.
     * @param planIndex the plan vector index
     * @param souvenirName name of the souvenir to search for and remove
     */
    void removeSouvenirAt(int planIndex, QString souvenirName);

    /**
     * @brief clearPlan will empty the plan vector
     */
    void clearPlan();

    /**
     * @brief clearPurchases will empty the souvenir purchases
     * at given index of the plan vector
     * @param index the index of where to clear souvenir purchases
     */
    void clearPurchases(int index);

    /**
     * @brief planSize will return the size of the plan vector
     * @return the size of the plan vector
     */
    int planSize();

    /**
     * @brief search will find the index where the given
     * stadiumname is on the plan vector
     * @param searchStadiumName the stadium name to search for
     * @return the index where the stadium name is. The size will be
     * returned if not found.
     */
    int search(QString searchStadiumName);

    /**
     * @brief searchPurchases will find whether the searchSouvenir exists
     * on the souvenir vector at the passed in index of the plan.
     * @param searchSouvenir the souvenir to be searched
     * @param index index of the plan vector to search
     * @return the index of the souvenir vector where it searchSouvenir was found.
     * If not found, will return the size of the souvenir vector.
     */
    int searchPurchases(QString searchSouvenir, int index);

    /**
     * @brief removeStadium will remove the stadium that is passed in
     * if it found on the plan vector.
     * @param stadiumName name of the stadium to be removed
     */
    void removeStadium(QString stadiumName);

    /**
     * @brief planAt will return the stadium name at the given index
     * @param index where the stadium name is going to be returned
     * @return a QString stadium name at the given index
     */
    QString planAt(int index);

    /**
     * @brief setStartingStadium will put the passed in string in the 0th
     * index of the plan vector
     * @param startingStadium the stadium to start at.
     */
    void setStartingStadium(QString startingStadium);

    /**
     * @brief getTotalDistance will return the total distance
     * of the trip whether it was determined by dijkstras or MST
     * @return the totalDistance attribute of the class
     */
    int getTotalDistance();

    /**
     * @brief getPurchasedVectorAt will return the purchased food at the
     * given index of the plan vector
     * @param i index of the plan vector at which the purchased food vector
     * will be retrieved
     * @return a vector of souvenirs (struct of QString souvenir name, and quantity purchased)
     */
    std::vector<souvenir> getPurchasedVectorAt(int i);

    /**
     * @brief InitializeGraph will initialize the passed in graph
     */
    void InitializeGraph();


private:
    /**
     * @brief plan vector that is sorted by distance of what
     * stadiums the user wants to visit and their purchases.
     */
    std::vector<Stadium> plan; // starting stadium will be index 0

    /**
     * @brief totalDistance the total distance traveled in the plan.
     */
    int totalDistance; // calculated in Dijkstras(start, ends)

    /**
     * @brief Prims Will find the minnimum spanning tree using the prims algorithm.
     * It will start at the starting stadium in the plan vector.
     * @return the MST as a vector of QStrings
     */
    std::vector<QString> Prims();


    /**
     * @brief currentGraph Uses an STL map to store the users choices in
     * graph/map form.
     */
    Graph currentGraph;
};

#endif // STADIUMVISITPLAN_H
