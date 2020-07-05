#include <iostream>

class Shape
{
public:
    Shape() {}
private:
    int _aa;
    int _bb;
};

class Circle
{
public:
    Circle(int a, int b, int c) : r(a), area(b), cle(c) {}
    Circle() { }
    // const 成员变量是只读的，不可被修改
    int getR() const;
    int getArea() const;
    int getCle() const;
    // 可以修改成员变量
    void setR(int newR);
    const Shape* getShape() const;
    Shape* getShape();

private:
    int r;
    int area;
    int cle;
    Shape shape;
};



int Circle::getR() const { return r; }
int Circle::getArea() const { return area; }
int Circle::getCle() const { return cle; }
void Circle::setR(int newR) { r = newR; }
const Shape* Circle::getShape() const {
    std::cout << "const func" << std::endl;
    return nullptr;
}

Shape* Circle::getShape() {
    std::cout << "normal func" << std::endl;
    return nullptr;
}

int main()
{
    Circle circle(1, 2, 3);
    Circle* circle2 = new Circle(1, 2, 3);
    circle2 = &circle;
    std::cout << "r = " << circle.getR() << std::endl;
    circle.setR(10);
    std::cout << "newR = " << circle.getR() << std::endl;
    const Circle circle3;
    // 会调用const版本
    circle3.getShape();
    Circle circle4;
    // 会调用normal版本
    circle4.getShape();
    return 0;
}
