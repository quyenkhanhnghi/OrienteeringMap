#include "point.hh"

Point::Point(string name, int x, int y, int height, char sign) {
    name_ = name;
    
    x_ = x;
    y_ = y;
    height_ = height;
    sign_ = sign;
}

Point::~Point() {}

string Point::getName() { return name_; }

char Point::getSign() {return sign_;}

int Point::getXcoor() {return x_;}

int Point::getYcoor() {return y_;}

int Point::getheight() {return height_;}

void Point::addRoute(string routeName) {
    belongRoutes.insert(routeName);
}

vector<string> Point::getBelongRoutes() {
    return vector<string>(belongRoutes.begin(), belongRoutes.end());
}
