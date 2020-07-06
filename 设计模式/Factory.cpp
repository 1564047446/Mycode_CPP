// 简单工厂

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
定义一个用于创建对象的接口，让子类决定实例化哪一个类。
工厂方法使得一个类的实例化延迟到子类
*/

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    virtual void draw() {
        cout << "this is circle ~" << endl;
    }
};

class Rectangle : public Shape {
public:
    virtual void draw() {
        cout << "this is rectangle ~" << endl;
    }
};

// 抽象工厂
class ShapeFactory {
public:
    virtual Shape* createshape() = 0;
    virtual ~ShapeFactory() {}
};

// 具体工厂
class CircleFactory : public ShapeFactory {
public:
    virtual Shape* createshape() {
        return new Circle;
    }
};

class RectangleFactory : public ShapeFactory {
public:
    virtual Shape* createshape() {
        return new Rectangle;
    }
};

int main() {
    ShapeFactory* fac = new CircleFactory;
    Shape* shape = fac->createshape();
    shape->draw();
    fac = new RectangleFactory;
    shape = fac->createshape();
    shape->draw();
    delete shape;
    delete fac;
    return 0;
}