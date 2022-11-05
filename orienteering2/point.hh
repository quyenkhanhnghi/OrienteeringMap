/*
 * A class for points
 */

#ifndef POINT_HH
#define POINT_HH

#include <string>
#include <set>
#include <vector>

using namespace std;

class Point
{
public:
    // constructor get all the neccessary attributes to construct a point
    Point(string name, int x, int y, int height, char sign);
    ~Point();

    // return the name of the point
    string getName();

    // return the sign of the point
    char getSign();

    // return the x-coordinate of the point
    int getXcoor();

    // return the y-coordinate of the point
    int getYcoor();

    // return the height of the point
    int getheight();

    // add the point to the route with route name as parameter
    void addRoute(string routeName);

    //return all the routes that the point belong to
    vector<string> getBelongRoutes();

private:
    string name_ = "";
    int x_ = 0, y_ = 0, height_ = 0;
    char sign_ = ' ';
    set <string> belongRoutes;
};


#endif // POINT_HH
