/*
是一种数据驱动的设计模式，它属于行为型模式。
请求以命令的形式包裹在对象中，并传给调用对象。
调用对象寻找可以处理该命令的合适的对象，并把该命令传给相应的对象，该对象执行命令。
*/


#include <iostream>
#include <vector>

using namespace std;

class Order {
public:
    virtual void execute() = 0;
};

class Shape {
public:
    Shape(string str) : name(str) {}
    void buy() {
        cout << "buy " << name << endl;
    }

    void sell() {
        cout << "sell" << name << endl;
    }

    string name;
};

class BuyShape : public Order {
public:
    BuyShape(Shape *shape) : buyshape(shape) {}
    virtual void execute() {
        buyshape->buy();
    }

    Shape* buyshape;
};

class SellShape : public Order {
public:
    SellShape(Shape* shape) : sellshape(shape) {}
    virtual void execute() {
        sellshape->sell();
    }

    Shape* sellshape;
};

class Broker {
public:
    Broker() {}
    void addVec(Order* order) {
        executeorder.push_back(order);
    }

    void executeOrder() {
        for (auto x : executeorder) {
            x->execute();
        }
    }

    vector<Order*> executeorder;
};

int main() {
    Shape* shape = new Shape("bbt");

    SellShape* sshape = new SellShape(shape);
    BuyShape* bshape = new BuyShape(shape);

    Broker* bro = new Broker();
    bro->addVec(sshape);
    bro->addVec(bshape);
    bro->executeOrder();

    return 0;
}