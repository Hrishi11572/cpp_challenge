#include <iostream>

class Point {
public: 
    Point(int x_value, int y_value)
        : x(x_value), y(y_value) {} // the members are initialized with their intended values directly. This detail is very important in the constness case. .. see next code file in this directory.

    int getx() { // getter
        return x; 
    }

    int gety() {
        return y; 
    }

private: 
    int x; 
    int y; 
};

int main() {
    Point p = {23, 3}; 
    std :: cout << p.getx() << " " << p.gety() << std :: endl; 
    return 0; 
}