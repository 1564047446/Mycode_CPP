#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Order {
public:
    virtual void execute() = 0;
    // 加入撤销操作
    virtual void undo() = 0;

    virtual ~Order() {}
};

class Shape {
public:
    Shape(string str) : name(str) {}
    void buy() {
        cout << "player buy " << name << " cost money" << endl;
        /*
        costmoney = x;
        becostmoney = money;
        money += costmoney;
        */
        return ;
    }

    void sell() {
        cout << "player sell " << name << " get money" << endl;
        /*
        同上
        */
        return ;
    }

    void BeforeBuy() {
        cout << "player Beforebuy " << name << "' money" << endl;
        /*
        money = becostmoney;
        becostmoney = 0;
        */
        return ;
    }

    void BeforeSell() {
        cout << "player Beforesell" << name << "' money" << endl;
        /*
        ......
        */
        return ;
    }
private:
    string name;
    int money;
    int getmoney;
    int costmoney;
    // 假定撤销需要的数据
    int begetmoney;
    int becostmoney;
};

class BuyShape : public Order {
public:
    BuyShape(Shape *shape) : buyshape(shape) {}
    virtual void execute() {
        buyshape->buy();
        return ;
    }

    virtual void undo() {
        buyshape->BeforeBuy();
        return ;
    }

    Shape* buyshape;
};

class SellShape : public Order {
public:
    SellShape(Shape* shape) : sellshape(shape) {}
    virtual void execute() {
        sellshape->sell();
        return ;
    }

    virtual void undo() {
        sellshape->BeforeSell();
        return ;
    }

    Shape* sellshape;
};

class Broker {
public:
    Broker() {}
    void addVec(Order* order) {
        executeorder.push(order);
        undoorder.push(order);
        return ;
    }

    void executeOrder() {
        for (; !executeorder.empty();) {
            executeorder.front()->execute();
            executeorder.pop();
        }
        return ;
    }

    void UndoOrder() {
        for (; !undoorder.empty();) {
            undoorder.top()->undo();
            undoorder.pop();
        }
    }

private:
    // 因为操作顺序的原因，采用栈来存储
    queue<Order*> executeorder;
    stack<Order*> undoorder;
};

int main() {
    Shape* shape = new Shape("bbt");

    SellShape* sshape = new SellShape(shape);
    BuyShape* bshape = new BuyShape(shape);

    Broker* bro = new Broker();
    bro->addVec(sshape);
    bro->addVec(bshape);
    // 执行命令
    bro->executeOrder();
    // 撤销操作
    bro->UndoOrder();
    return 0;
}