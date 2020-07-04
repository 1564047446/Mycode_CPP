#include <iostream>
#include <string>
using namespace std;

/* 请在这里定义struct */
struct Point {
    int x;
    int y;
};

struct Vector {
    int x;
    int y;
};

Vector operator+(Vector a, Vector b) {
    return Vector{a.x + b.x, a.y + b.y};
}

Point operator+(Point a, Vector b) {
    return Point{a.x + b.x, a.y + b.y};
}

Point operator+(Vector a, Point b) {
    return Point{a.x + b.x, a.y + b.y};
}

int main() {
    Point a{1, 2};
    Vector b{3, 4};
    auto x = b + b;
    cout << "b + b = {" << x.x << ", " << x.y << "}" << endl;
    auto y = a + b;
    cout << "a + b = {" << y.x << ", " << y.y << "}" << endl;
    auto z = b + a;
    cout << "b + a = {" << z.x << ", " << z.y << "}" << endl;
   
    return 0;
}