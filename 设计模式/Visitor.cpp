// 观察者模式

#include <iostream>
#include <vector>

using namespace std;

/*
定义对象间1对多的以来关系
当由一个对象的状态发生改变时，所有依赖于他的对象都得到通知并更新

*/

class IVsitor {
public:
    virtual void dosome() = 0;
    virtual ~IVsitor() {}
};

class B : public IVsitor {
public:
    virtual void dosome() {
        cout << "1" << endl;
    }
};

class C : public IVsitor {
public:
    virtual void dosome() {
        cout << "2" << endl;
    }
};

class A {
public:
    vector<IVsitor*> my_visitor;
    void add(IVsitor *visitor) {
        my_visitor.push_back(visitor);
    }
    void Ado() {
        for (auto x : my_visitor) {
            if (my_visitor.empty()) {
                cout << "nullptr" << endl;
                break;
            }
            x->dosome();
        }
    }
};



int main() {
    B b;
    C c;
    A *a = new A;
    a->add(&b);
    a->add(&c);
    a->Ado();
    delete a;
    return 0;
}