// 装饰模式

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
动态的给一个对象新增一些额外的功能
装饰模式比继承更为灵活（消除重复代码 & 减少子类个数）
*/


class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class ShapeDeractor : public Shape {
public:
    ShapeDeractor(Shape* shape) : Shape(), shape(shape) {}
    virtual void draw() {
        shape->draw();
    }
    
    // 基类的指针, 用来实现子类的组合
    Shape* shape;
};

class Circle : public Shape {
public:
    virtual void draw() {
        cout << "this is circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    virtual void draw() {
        cout << "this is rectangle" << endl;
    }

};

class RedShapeDeractor : public ShapeDeractor {
public:
    RedShapeDeractor(Shape* shape) : ShapeDeractor(shape) {}
    void redborder() {
        cout << "red border" << endl;
    }
};


int main() {
    Circle *c = new Circle;
    Rectangle *r = new Rectangle();
    c->draw();
    r->draw();
    RedShapeDeractor* circle = new RedShapeDeractor(c);
    circle->draw();
    circle->redborder();
    RedShapeDeractor* rectangle = new RedShapeDeractor(r);
    rectangle->draw();
    rectangle->redborder();
    delete rectangle;
    delete circle;
    delete r;
    delete c;
    return 0;
}