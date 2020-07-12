#include <iostream>
#include <vector>

class Shape {
public:
    Shape(int index, int number) : _index(index), _number(number) {}
    Shape& operator++();
    // 编译器会自动传进去一个0进去进行计算
    Shape operator++(int);
    void printNumber();
private:
    int _index;
    int _number;
};

void Shape::printNumber() {
    std::cout << _number << std::endl;
    return ;
}

Shape& Shape::operator++() {
    ++_number;
    return *this;
}

Shape Shape::operator++(int) {
    ++_number;
    return *this;
}


int main() {
    Shape shape(1, 2);
    shape.printNumber();
    ++shape;
    shape.printNumber();
    shape++;
    shape.printNumber();
    return 0;
}