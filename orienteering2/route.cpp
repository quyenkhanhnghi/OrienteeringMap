#include "route.hh"
#include <iostream>


Route::Route(string name) {
    name_ = name;
    
}

Route::~Route() {}

void Route::addPoint(Point * p) {
    controlPoints.push_back(p);
}

vector<string> Route::getPointsName() {
    vector<string> nameList;

    for (const auto point: controlPoints) {
        nameList.push_back(point->getName());
    }

    return nameList;
}

double Route::distance(Point * a, Point * b) {
    int xa = a->getXcoor();
    int ya = a->getYcoor();
    int xb = b->getXcoor();
    int yb = b->getYcoor();
    return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

double Route::sumLength() {
    
    double ans = 0;
    for ( unsigned long i = 0; i < controlPoints.size() - 1; i++ ) {
        ans += distance(controlPoints[i], controlPoints[i+1]);
    }

    return ans;
}

int Route::risePoint(string name) {
    int index = 0;
    for ( unsigned long i = 0; i < controlPoints.size(); i++) {
        if (controlPoints[i]->getName( ) == name ) {
            index = i;
            break;
        }
    }
    
    

    unsigned long i = 0;
    for (i = index + 1; i < controlPoints.size(); i++) {
        if (controlPoints[i]->getheight() < controlPoints[i -1]->getheight()) {
            break;
        }
    }
    i = i - 1;
    return controlPoints[i]->getheight() - controlPoints[index]->getheight();
}

string Route::getName() { return name_; }

