// 线程安全的单利模式

// 全局变量的缺点如下：
/*
1.代码可读性低
2.增加耦合
3.并发问题较为多
*/
#include <iostream>

class Shape;
class Normal;

class Normal {
public:
    Normal() {
        //shape = Shape::getInstanc();
    }
    Shape* shape;
};

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

class Singleton {
private:
    Singleton() {}
    Singleton(int x, int y) : _count(x), _number(y) {}
    Singleton(Singleton& single) {}
public:
    static Singleton* _instance;
    static Singleton* getInstance() {
        if (_instance == nullptr) {
            return new Singleton(1, 2);
        }
        return _instance;
    }
    int _count;
    int _number;
};

Singleton* Singleton::_instance = nullptr;

class People {
public:
    People() {
        single = Singleton::getInstance();
    }
    Singleton* single;
};

int main() {
    Shape* shape = Shape::getInstanc();
    shape->print();
    shape->_y = 10000;
    Shape* shape2 = Shape::getInstanc();
    shape2->print();

    Normal* normal = new Normal();
    normal->shape = Shape::getInstanc();
    normal->shape->print();
    normal->shape->_y = 20000;
    
    std::cout << "----------------------------" << std::endl;
    People* p1 = new People();
    std::cout << "p1:" << p1->single->_number << std::endl;
    p1->single->_number = 0;
    std::cout << "p1:" << p1->single->_number << std::endl;
    std::cout << "----------------------------" << std::endl;
    People* p2 = new People();
    std::cout << "p2:" << p2->single->_number << std::endl;
    return 0;
}