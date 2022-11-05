/*
 *  A class for route
 */

#ifndef ROUTE_HH
#define ROUTE_HH

#include "point.hh"
#include <string>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

class Route 
{
public:
    // constructor for a route with name
    Route(string name);
    ~Route();

    // add point to the route
    void addPoint(Point * p);

    // return the name of the route
    string getName();

    // return all the points' name in a route
    vector<string> getPointsName();

    // return the length of a route (Euclidean distance between the points)
    double sumLength();

    // return the max rise (int) of a point in the route
    int risePoint(string name);

private:
    string name_ = "";

    vector<Point *> controlPoints;

    double distance(Point * a, Point * b);

};

#endif // ROUTE_HH
