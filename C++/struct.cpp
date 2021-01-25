#include <cmath>
#include <iostream>
using namespace std;

/** contains functions that return structs and structs as arguments
 * calculating distance between 2-variable coordinate in Euclidean space
 * @author Dave Amiana
 */

typedef struct point {
    point(double x_arg, double y_arg) {
        x = x_arg;
        y = y_arg;
    }
    double x = 0.0;
    double y = 0.0;
}Point;

/** formula for calculating the distance:
 * sqrt((pow,abs(x1-x2),2)+(pow,abs(y1-y2),2))
 */
double distance(Point a, Point b) {
    double x_dist = abs(b.x - a.x);
    double y_dist = abs(b.y - a.y);
    return sqrt(pow(x_dist, 2) + pow(y_dist, 2));
}

Point getMiddle(Point a, Point b){
    Point m{0,0};
    m.x = (a.x+b.y)/2;
    m.y = (a.y+b.y)/2;
    return m;
}

int main() {
    Point p1{1, 2};
    Point p2{3, 4};
    Point middle = getMiddle(p1, p2);
    std::cout << "distance: " << distance(p1, p2)<<endl;
    std::cout << "middle point: "<<middle.x<<" , "<<middle.y;
    return 0;
}
