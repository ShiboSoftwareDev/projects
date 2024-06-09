#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
};

int calculateDistance(Point one, Point two){
    int dx = one.x - two.x;
    int dy = one.y - two.y;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    Point one;
    Point two;
    
    cout << "Enter first point" << endl << "x: ";
    cin >> one.x;
    cout << "y: ";
    cin >> one.y;
    cout << "Enter second point" << endl << "x: ";
    cin >> two.x;
    cout << "y: ";
    cin >> two.y;
    int distance = calculateDistance(one, two);
    cout << "Distance is: " << distance << endl;
}

