// 线程安全的单利模式

#include <iostream>

// C++11保证一个局部变量的初始化只进行一次，所以是线程安全的。
class Shape {
private:
    Shape() {}
    Shape(int x, int y) : _x(x), _y(y) {}
    int _x;

public:
    static Shape* getInstanc() {
        static Shape* instance = new Shape(1, 2);
        return instance;
    }
    void print() {
        std::cout << _x << " " << _y << std::endl;
    }
    int _y;
};

int main() {
    Shape* shape = Shape::getInstanc();
    shape->print();
    shape->_y = 10000;
    Shape* shape2 = Shape::getInstanc();
    shape2->print();
    return 0;
}