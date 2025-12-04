#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Point {
private:
    double x, y;  // My coordinates

public:
    // Default constructor - makes point at (0,0)
    Point() {
        x = 0;
        y = 0;
        cout << "Point created at (0, 0)" << endl;
    }
    
    // Constructor with coordinates
    Point(double newX, double newY) {
        x = newX;
        y = newY;
        cout << "Point created at (" << x << ", " << y << ")" << endl;
    }
    
    // Copy constructor - makes a copy of another point
    Point(const Point& other) {
        x = other.x;
        y = other.y;
        cout << "Point copied from (" << x << ", " << y << ")" << endl;
    }
    
    // Get x value
    double getX() {
        return x;
    }
    
    // Set x value
    void setX(double newX) {
        cout << "Changing x from " << x << " to " << newX << endl;
        x = newX;
    }
    
    // Get y value
    double getY() {
        return y;
    }
    
    // Set y value
    void setY(double newY) {
        cout << "Changing y from " << y << " to " << newY << endl;
        y = newY;
    }
    
    // Make coordinates as text
    string toString() {
        string text = "(" + to_string(x) + ", " + to_string(y) + ")";
        return text;
    }
    
    // Calculate distance to another point
    double distance(Point other) {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx*dx + dy*dy);
    }
};

int main() {
    cout << "=== CREATING POINTS ===" << endl;
    
    // First point - default
    Point p1;
    
    // Second point - with values
    Point p2(3, 4);
    
    // Third point - copy
    Point p3 = p2;
    
    cout << "\n=== CHANGING POINT 1 ===" << endl;
    p1.setX(2);
    p1.setY(5);
    
    cout << "\n=== SHOWING POINTS ===" << endl;
    cout << "p1: " << p1.toString() << endl;
    cout << "p2: " << p2.toString() << endl;
    cout << "p3: " << p3.toString() << endl;
    
    cout << "\n=== CALCULATING DISTANCES ===" << endl;
    cout << "Distance p1 to p2: " << p1.distance(p2) << endl;
    cout << "Distance p2 to p3: " << p2.distance(p3) << endl;
    
    return 0;
}
