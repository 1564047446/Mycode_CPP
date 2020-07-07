#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Color {
public:
    virtual void color() = 0;
    virtual ~Color() {}
};

class Circle : public Shape {
public:
    virtual void draw() {
        cout << "this is Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    virtual void draw() {
        cout << "this is Rectangle" << endl;
    }
};

class Red : public Color {
public:
    virtual void color() {
        cout << "Red" << endl;
    }
};

class Black : public Color {
public:
    virtual void color() {
        cout << "Black" << endl;
    }
};

//抽象工厂
class AbstractFactory {
public:
    virtual Shape* createShape() = 0;
    virtual Color* createColor() = 0;
};

// 具体工厂
class ShapeFactory : public AbstractFactory {
public:
    ShapeFactory(string ch) : AbstractFactory(), choice(ch) {}
    virtual Shape* createShape() {
        if (choice == "circle") {
            return new Circle;
        } else if (choice == "rectangle") {
            return new Rectangle;
        } else {
            return nullptr;  //每一个分支都要有返回值
        }
    }
    virtual Color* createColor() {
        return nullptr;
    }
    string choice;
};

// 具体工厂
class ColoeFactory : public AbstractFactory {
public:
    ColoeFactory(string ch) : AbstractFactory(), choice(ch) {}
    virtual Color* createColor() {
        if (choice == "red") {
            return new Red;
        } else if (choice == "black") {
            return new Black;
        } else {
            return nullptr;
        }
    }
    virtual Shape* createShape() {
        return nullptr;
    }
    string choice;
};

//创建一个工厂创造器/生成器类，通过传递形状或颜色信息来获取工厂。
class FactoryProductor {
public:
    FactoryProductor(string ch, string ch2) : choice(ch), choice2(ch2) {

    }
    AbstractFactory* getFactory() {
        if (choice == "shape") {
            return new ShapeFactory(choice2);
        } else {
            return new ColoeFactory(choice2);
        }
    }
    string choice;
    string choice2;
};

int main() {
    FactoryProductor* fp = new FactoryProductor("shape", "circle");
    AbstractFactory* shape = fp->getFactory();
    Shape* circle = shape->createShape();
    circle->draw();
    FactoryProductor* fp2 = new FactoryProductor("color", "red");
    AbstractFactory* color = fp2->getFactory();
    Color* red = color->createColor();
    red->color();
    delete red, color, fp2, circle, shape, fp;
    return 0;
}