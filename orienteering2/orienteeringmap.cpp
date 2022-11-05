#include "orienteeringmap.hh"

OrienteeringMap::OrienteeringMap() {}
OrienteeringMap::~OrienteeringMap() {}

void OrienteeringMap::set_map_size(int width, int height) {
    width_ = width;
    height_ = height;


    markerMap = vector<vector<char>>(height_, vector<char> (width, '.'));
}

void OrienteeringMap::add_point(std::string name, int x, int y, int height, char marker) {
    nameToPoint[name] = new Point(name, x, y, height, marker);
    markerMap[y-1][x-1] = marker; 
}

bool OrienteeringMap::connect_route(std::string from,
                       std::string to,
                       std::string route_name) 
{
    
    if (nameToRoute.find(route_name) != nameToRoute.end()) {
        nameToRoute[route_name]->addPoint(nameToPoint[to]);
        nameToPoint[to]->addRoute(route_name);
    } else {
        nameToRoute[route_name] = new Route(route_name);
        
        nameToRoute[route_name]->addPoint(nameToPoint[from]);
        nameToRoute[route_name]->addPoint(nameToPoint[to]);
        
        nameToPoint[to]->addRoute(route_name);
        nameToPoint[from]->addRoute(route_name);
    }

    return true;
}

void OrienteeringMap::print_map() const {

    cout << " ";
    for (int j = 0; j < width_; j++)
    {
        cout.width(3);
        cout << right << j+1;
    }
    cout << endl;

    int line = 1;
    for (const auto &row : markerMap) {
        cout.width(2);
        cout << right << line;
        for (const auto m : row) {
            cout.width(3);
            cout << right << m;
        }
        cout << endl;
        line++;
    }

}

void OrienteeringMap::print_routes() const {

    cout << "Routes:" << endl;
    for (const auto &pair : nameToRoute) {
        cout << " - " << pair.first << endl;
    }

}

void OrienteeringMap::print_points() const {

    cout << "Points:" << endl;
    for ( const auto &pair : nameToPoint) {
        cout << " - " << pair.first << " : " << pair.second->getSign() << endl;
    }
}

void OrienteeringMap::print_route(const std::string& name) const {

    if (nameToRoute.find(name)== nameToRoute.end()) {
        cout << "Error: Route named " << name << " can't be found" << endl;
        return;
    }

    vector<string> pointsName = nameToRoute.at(name)->getPointsName();

    cout << pointsName[0] << endl;
    for ( unsigned long i = 1; i < pointsName.size(); i++ ) {
        cout << " -> " << pointsName[i] << endl;
    }

    return;

}

void OrienteeringMap::route_length(const std::string& name) const {

    if (nameToRoute.find(name) == nameToRoute.end()) {
        cout << "Error: Route named " << name << " can't be found" << endl;
        return; 
    }
    cout << setprecision(2);
    cout << "Route " << name << " length was " << nameToRoute.at(name)->sumLength() << endl;

    return;
}

void OrienteeringMap::greatest_rise(const std::string & point_name) const {
    int maxrise = 0;
    vector<string> maxRiseRoute;

    if (nameToPoint.find(point_name) == nameToPoint.end()) {
        cout << "Error: Point named " << point_name << " can't be found" << endl;
        return;
    }
    Point * point = nameToPoint.at(point_name);

    for (const auto &routeName : point->getBelongRoutes()) {
        Route * route = nameToRoute.at(routeName);

        int rise = route->risePoint(point->getName());

        if (rise > maxrise) {
            maxRiseRoute.clear();
            maxRiseRoute.push_back(route->getName());
            maxrise = rise;
        } else {
            if (rise == maxrise) {
                maxRiseRoute.push_back(route->getName());
            }
        }
    }

    if (maxrise == 0) {
        cout << "No route rises after point " << point_name << endl;
        return;
    }
    
    cout << "Greatest rise after point " << point_name << ", " << maxrise << " meters, is on route(s):" << endl;
    for (const auto &route: maxRiseRoute) {
        cout << " - " << route << endl;
    }

    return;

}

double OrienteeringMap::sumLength(vector<int> x, vector<int> y, int n) const
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += sqrt(pow(x[i] - x[i+1], 2) + pow(y[i]- y[i+1], 2));
    return sum;
}
