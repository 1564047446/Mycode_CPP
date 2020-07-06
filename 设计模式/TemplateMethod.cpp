// 模板方法

#include <iostream>

using namespace std;

/*
定义一个操作中的算法的骨架是稳定的
将变化的方法添加到子类
模板方法可以使自雷可以不改变（复用）一个算法的结构即可重新定义该算法的默写特定步骤
*/

class A {
public :
     A() {
        cout << "这是基类A" << endl;
    }
    // run方法就是模板方法，是稳定的
    void run() {
        step1();
        if (step2()) { // 支持变化 ==》 虚函数多态调用
            step3();
        }
        step4();// 支持变化 ==》 虚函数多态调用
        step5();
    }
    void step1() {
        cout << "这是第一步" << endl;
    }
    void step3() {
        cout << "这是第三步"  << endl;
    }
    void step5() {
        cout << "这是第五步" << endl;
    }
    virtual int step2() = 0;
    virtual void step4() = 0;
    virtual ~A() {}
};

class B : public A {
public:
     B() : A() {
        cout << "这是派生类B" << endl;
    }
    virtual int step2() {
        cout << "这是第二步" << endl;
        return 1;
    }

    virtual void step4() {
        cout << "这是第四步" << endl;
    }
    virtual ~B() {}
};

int main() {
    A *b = new B;
    b->run();
    delete b;
    return 0;
}