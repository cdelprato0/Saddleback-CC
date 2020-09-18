#include "stadiumvisitplan.h"
#include <map>
#include <stack>
#include <limits>

StadiumVisitPlan::StadiumVisitPlan()
{
    totalDistance = 0; // Always initialized to 0 to avoid error.
    InitializeGraph();
}

StadiumVisitPlan::~StadiumVisitPlan(){}

// Private method used in both Prims and Dijkstras.
void StadiumVisitPlan::InitializeGraph()
{
    // for loop below is adding the edges to the
    // std::map<QString, std::map<QString, int>>(graph) currentGraph

    std::vector<Stadium> newPlan;
    Stadium pass;
    std::vector<QString> temp = Database::getInstance()->getAllStadiumNamesAsVector();
    for(auto itr = temp.begin(); itr != temp.end(); itr++){
        pass.stadiumName = *itr;
        newPlan.push_back(pass);
    }

    if(plan.size() > 0){
        auto pp = newPlan.begin();
        for(pp = newPlan.begin(); pp->stadiumName != plan.at(0).stadiumName &&
                                       pp != newPlan.end(); pp++);

        std::swap(*newPlan.begin(), *pp);
     }


    // from the database Distance Tables
    std::vector<QString> toStadiums;
    int weight;
    for(auto from = newPlan.begin(); from != newPlan.end(); from++){
        // returns a vector of all the toStadiumNames in the database associated with
        // the fromStadiumName (from->stadiumName)
        toStadiums = Database::getInstance()->getToStadiumNames(from->stadiumName);
        for(auto to = toStadiums.begin(); to != toStadiums.end(); to++){

            // returns the weight that is between the from and to stadiumNames.
            // because the iterator from is pointing to a Stadium struct obj, it uses from->stadiumName
            // because the iterator to is pointing to a QString, it use *to.
            weight = Database::getInstance()->getWeightBetween(from->stadiumName, *to);

            // weight is -1 if the query failed or if there was no weight between the from and
            // to stadium. This should never happen, but just in case.
            if(weight > -1){

                // Need to make the second a new map (call constructor) to avoid syntax errors.
                if(currentGraph.find(from->stadiumName) != currentGraph.end()){
                    currentGraph.insert(std::make_pair(from->stadiumName, std::map<QString, int>()));
                }
                currentGraph[from->stadiumName].insert(std::make_pair(*to, weight));
            }
        }
    }

}

// Orders the current plan by visiting each nearest stadium as determined using
// dijkstra's algorithm.
void StadiumVisitPlan::Dijkstras()
{
    totalDistance = 0; // Set to 0 to restart the accumulation

    std::vector<QString> pathToNearestStadium; // Path to next stadium to visit
    std::vector<QString> stadiumsToVisit;      // Initially just a copy of plan
    std::vector<QString> fullPath;             // Every leg of journey
    std::vector<QString> visitedStadiums;      // Visits in order

    // Start at the first stadium on the plan
    QString start = plan.front().stadiumName;
    visitedStadiums.push_back(start);

    // We will next visit every other stadium on the plan
    for(auto itr = ++plan.begin(); itr!= plan.end(); ++itr){
        stadiumsToVisit.push_back(itr->stadiumName);
    }

    InitializeGraph();

    // Loop until all planned stadiums have been visited
    while(!stadiumsToVisit.empty()){
        // Find path to the nearest stadium
        pathToNearestStadium = Dijkstras(start, stadiumsToVisit, totalDistance);

        /*Testing*/
        for(auto p = pathToNearestStadium.begin(); p != pathToNearestStadium.end(); p++){
            qDebug() << *p;
        }

        // Erases visited stadium to prevent a repeat visit.
        auto visitedStadium = std::find(stadiumsToVisit.begin(),
                                        stadiumsToVisit.end(),
                                        pathToNearestStadium.back());

        if(visitedStadium != stadiumsToVisit.end()){
            stadiumsToVisit.erase(visitedStadium);
        }
        else{
            throw("Error: found invalid end: " + pathToNearestStadium.back());
        }

        // Adds all stadiums that need to be traveled through to visit the next
        // stadium on the path, but not the final stadium as it will be the
        // initial stadium on the next path.
        auto penultimate = --pathToNearestStadium.end();
        for(auto it = pathToNearestStadium.begin(); it != penultimate; ++it){
            fullPath.push_back(*it);
        }

        // We have now visited this stadium
        visitedStadiums.push_back(pathToNearestStadium.back());
        pathToNearestStadium.clear();

        // Sets the new starting stadium to the previously visited stadium
        start = visitedStadiums.back();
    }

    // Add the final destination, as there will be no new paths afterwards
    fullPath.push_back(start);

    auto toSwap = plan.begin();
    for (const auto& name : visitedStadiums) {
        auto nextStadium = std::find_if(toSwap,
                                        plan.end(),
                                        [&] (const Stadium& stadium) {
                                            return stadium.stadiumName == name;
                                        });
        std::swap(*toSwap, *nextStadium);
        ++toSwap;
    }

    // Path is never being used as of yet. Not sure what it's for.
    // Distance is being stored in member variable totalDistance, however.
}

// Private, Only used in method Dijkstras() above.
// Returns the shortest path from stadium start to the nearest stadium in ends.
std::vector<QString> StadiumVisitPlan::Dijkstras(QString start,
                                                 std::vector<QString> ends,
                                                 int &distance)
{
    std::map<QString, QString> previous;  // Penultimate stadiums on each path
    std::map<QString, int>     distances; // Path lengths from starting stadium

    // Set distance and previous for the starting stadium
    distances.insert(std::make_pair(start, 0));
    previous.insert(std::make_pair(start, " "));

    // Indicate that no path has yet been found to all non-starting stadiums
    for(auto& stadium : currentGraph){
        distances.insert(std::make_pair(stadium.first,
                                        std::numeric_limits<int>::max()));
    }

    std::vector<QString> pending; // Stores each stadium that has been found
    pending.push_back(start); // push on to the path the starting point

    bool found = false; // Indicates that a path to a stadium in ends was found
    QString current; // where dijkstras is currently looking for best path.

    while(pending.size() > 0 && !found){
        // Sorts the discovered cities by their distance from the start
        std::sort(pending.begin(),pending.end(),
                  [&distances](QString i, QString j){
            return distances.at(i) < distances.at(j);
        });

        current = pending.front();
        pending.erase(pending.begin());

        if (std::find(ends.begin(), ends.end(), current) != ends.end()){
            found = true; // found a shortest path to the nearest stadium
        }else{
            // Updates path to  adjacent cities if they should be rerouted
            // through the current nearest city
            for (auto i = currentGraph[current].begin(); i != currentGraph[current].end(); i++) {
                // i->first =  string key of neighbor to current node
                // i->second = distance between neighbor and current node
                if(distances[current] + i->second < distances[i->first]){
                    previous.insert(std::make_pair(i->first, current));
                    distances[i->first] = distances[current] + i->second;
                    pending.push_back(i->first);
                }
            }
        }
    }

    // Add distance of path to the total distance traveled
    distance += distances.at(current);

    // Construct path by traversing back from end to start, then reversing
    std::vector<QString> path;
    path.push_back(current);
    while(previous[current] != " " ){
        current = previous[current];
        path.push_back(current);
    }
    std::reverse(path.begin(), path.end());

    return path;
}

// Private Uses prims algorithm to find the minnimum spanning tree starting
// from the starting stadium.
std::vector<QString> StadiumVisitPlan::Prims()
{
  totalDistance = 0;
  std::vector<QString> MST; // Will be the Minnimum Spanning Tree
  std::vector<QString> visited; // All the stadium names (vertices) that have been visited
  Graph reachableNodes; // All the edges that are reachable from the visited nodes

  // Prims starts at a given vertex. I have decided to use the starting stadium.
  visited.push_back(plan.at(0).stadiumName);

  // Variables below are used for the algorithm
  QString smallestStadium;
  int smallestWeight;
  QString currentParent;

  // Will loop until all vertices have been visited.
  while(visited.size() != plan.size()){

      // Double for-loop will initialize the reachableNodes Graph.
      // Loops through the visited vector to find all the edges of each visited stadium
      for(auto vecItr = visited.begin();
          vecItr != visited.end(); vecItr++){
          // Will loop through the graph to find all the edges belonging to the
          // current *vecItr
          for(auto graphItr = currentGraph[*vecItr].begin();
              graphItr != currentGraph[*vecItr].end(); graphItr++){

              // Will add all edges that have to-stadiums that have not been visited yet.
              if(std::find(visited.begin(), visited.end(), graphItr->first) == visited.end()){
                  // Need to make the second a new map (call constructor) to avoid syntax errors.
                  if(reachableNodes.find(*vecItr) != reachableNodes.end()){
                        reachableNodes.insert(std::make_pair(*vecItr, std::map<QString, int>()));
                  }
                  reachableNodes[*vecItr].insert(std::make_pair(graphItr->first, graphItr->second));
                  //qDebug() << "added to reachableNodes: " << *vecItr << ", " << graphItr->first << "  " << graphItr->second;
              }
          }
      }

      // Initializes the smallest stadium weight of all the edges to
      // the first of the list of edges.
      smallestStadium = reachableNodes.begin()->second.begin()->first;
      smallestWeight = reachableNodes.begin()->second.begin()->second;

      // The current parent, will help for when adding to the MST vector.
      currentParent = reachableNodes.begin()->first;

      // Loops through the second of the graph (map of string, map) and
      // finds the smallest weighted edge.
      for(auto x = reachableNodes.begin(); x != reachableNodes.end(); x++){
          for(auto y = reachableNodes[x->first].begin()++; y!= reachableNodes[x->first].end(); y++){
              //qDebug() << "A: " << currentParent << " to " << smallestStadium << ":  " << smallestWeight << " is greater than " << y->second;
              if(smallestWeight > y->second){
                  //qDebug() << "B: " << currentParent << " to " << smallestStadium << ":  " << smallestWeight << " is greater than " << y->second ;
                  smallestStadium = y->first;
                  smallestWeight = y->second;
                  currentParent = x->first;
              }
              //qDebug() << "\n";
          }
      }
      //qDebug() << "End reachableNodes search \n\n";

      // Adds the smallest weighted edge to-stadium to the visited vector
      visited.push_back(smallestStadium);

      /*****************************
       * If total weight needs to be
       * calculated, it would be here
       ****************************/
      totalDistance+= smallestWeight;

      // Also adds the visited edge
      MST.push_back(currentParent + " to " + smallestStadium + " " + QString::number(smallestWeight).toStdString().c_str());
      reachableNodes.clear(); // reachableNodes are cleared to be re-initialized
  }
  return MST;
}

// Public method to call prims to find the MST.
std::vector<QString> StadiumVisitPlan::MST(){

    /*********************************
     * Determine whether we keep it as
     * a string or to order it by
     * edge length.
     ********************************/

    std::vector<QString> minSpanTree;
    minSpanTree = Prims();
    return minSpanTree;
}

// Will push a stadium on to the Plan vector with the passed in
// stadium name
void StadiumVisitPlan::pushStadium(QString stadiumName)
{
    Stadium newStadium;
    newStadium.stadiumName = stadiumName;
    pushStadium(newStadium);

}

// Pushes a literal Stadium (struct) obj on to the plan vector.
void StadiumVisitPlan::pushStadium(Stadium stadiumInsert)
{
    if(search(stadiumInsert.stadiumName) == planSize()){
        plan.push_back(stadiumInsert);
    }else{
        qDebug() << "\nAlready exists in the plan exception. Method:pushStadium\n";
    }
}

// Will push a souvenir in to the given plan vector's given index
// with the given souvenir name.
void StadiumVisitPlan::pushSouvenir(QString souvenirName, int index)
{
    souvenir newSouvenir;
    newSouvenir.souvenirName = souvenirName;
    pushSouvenir(newSouvenir, index);
}

// Will push a Souvenir (struct) object in to the plan vector's
// given index.
void StadiumVisitPlan::pushSouvenir(souvenir souvenirInsert, int index)
{
    if(searchPurchases(souvenirInsert.souvenirName, index) ==
       int(plan.at(index).purchasedSouvenirs.size())){
        plan.at(index).purchasedSouvenirs.push_back(souvenirInsert);
    }else{
        qDebug() << "\nAlready exists in the purchased souvenirs @ plan index " << index
                 << " exception. Method:pushSouvenir\n";
    }
}

// Will change the quantity of the souvenir name at the given plan vector's
// index.
void StadiumVisitPlan::changeQuantityAt(int planIndex, QString souvenirName, int quantity)
{
    int foundIndex = searchPurchases(souvenirName, planIndex);
    if(foundIndex != int(plan.at(planIndex).purchasedSouvenirs.size())){
        plan.at(planIndex).purchasedSouvenirs.at(foundIndex).quantity = quantity;
    }else{
        qDebug() << "\nDoesn\'t exist in the purchased souvenirs @ plan index " << planIndex
                 << " exception. Method:changeQuantityAt\n";
    }
}

// Will remove a souvenir at the given plan index that has the given
// souvenir name.
void StadiumVisitPlan::removeSouvenirAt(int planIndex, QString souvenirName)
{
    int foundIndex = searchPurchases(souvenirName, planIndex);
    if(foundIndex != int(plan.at(planIndex).purchasedSouvenirs.size())){
        plan.at(planIndex).purchasedSouvenirs.erase(plan.at(planIndex).purchasedSouvenirs.begin() + foundIndex);
    }else{
        qDebug() << "\nDoesn\'t exist in the purchased souvenirs @ plan index  " << planIndex
                 << " exception. Method:removeSouvenirAt\n";
    }
}

// Will clear the plan vector
void StadiumVisitPlan::clearPlan()
{
    plan.clear();
}

// Will clear purchases vecor at the given index.
void StadiumVisitPlan::clearPurchases(int index)
{
    plan.at(index).purchasedSouvenirs.clear();
}

// returns the size of the plan vector
int StadiumVisitPlan::planSize()
{
    return int(plan.size());
}

// will return the index at where the stadium name was found
int StadiumVisitPlan::search(QString searchStadiumName)
{
    for(int i = 0; i < planSize(); i++){
        if(plan.at(i).stadiumName == searchStadiumName){
            return i;
        }
    }
    return planSize();
}

// will return the index at which the souvenir name was found at the
// given plan index.
int StadiumVisitPlan::searchPurchases(QString searchSouvenir, int index)
{
    for(int i = 0; i < int(plan.at(index).purchasedSouvenirs.size()); i++){
        if(plan.at(index).purchasedSouvenirs.at(i).souvenirName == searchSouvenir){
            return i;
        }
    }
    return int(plan.at(index).purchasedSouvenirs.size());
}

// removes a stadium from the plan vector.
void StadiumVisitPlan::removeStadium(QString stadiumName)
{
    int foundIndex = search(stadiumName);
    if(foundIndex != planSize()){
        plan.erase(plan.begin() + foundIndex);
    }else{
        qDebug() << "\nStadium not found exception. Method:removeStadium\n";
    }
}

// will return the stadium's name at the given index of the
// plan vector.
QString StadiumVisitPlan::planAt(int index)
{
    return plan.at(index).stadiumName;
}

// Will set the starting stadium to the first index.
void StadiumVisitPlan::setStartingStadium(QString startingStadium)
{
    plan.at(0).stadiumName = startingStadium;
}

// will return the totalDistance attribute of the class
int StadiumVisitPlan::getTotalDistance()
{
    return totalDistance;
}

// will return the souvenir purchased vector at the given plan vector's index.
std::vector<souvenir> StadiumVisitPlan::getPurchasedVectorAt(int i)
{
    return plan.at(i).purchasedSouvenirs;
}


