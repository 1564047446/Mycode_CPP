/*************************************************************************
	> File Name: test1.cpp
	> Author: byt
	> Mail: baotongyu@zt.game
	> Created Time: 2018年07月22日 星期日 16时41分37秒
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
public :
    Animal(string _name) : name(_name) {}
    void say() {
        cout << "this is " << this->name << endl;
    }
    virtual void foo() {}
private :
    string name;
};


struct Cat : Animal {
public :
    virtual void foo() {}
    Cat() : Animal("cat") {}
};

struct Dog : Animal {
public :
    virtual void foo() {}
    Dog() : Animal("dog") {}
};

int main() {
    Cat *cat = dynamic_cast<Cat *>(p);
    if (cat == nullptr) {
        cout << "this is not cat" << endl;
    } else {
        cout << "this is cat" << endl;
    }
    return 0;
}
