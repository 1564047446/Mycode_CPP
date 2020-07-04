/*************************************************************************
	> File Name: test2.cpp
	> Author: byt
	> Mail: baotongyu@zt.game
	> Created Time: 2018年07月22日 星期日 17时03分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;;
using std::string;
using std::vector;

struct Animal {
public:
    virtual void say() {
        cout << "I don't know who i am" << endl;
    }
private:
    string name;
};

struct Cat : Animal {
public:
    void say() override {
        cout << "I am a cat" << endl;
    }
};

int main() {
    Animal a;
    a.say();
    Cat cat;
    cat.say();
    return 0;
}
