/*************************************************************************
	> File Name: 返回值优化.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月30日 星期五 20时21分30秒
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class People {
public : 
    People(string name) {
        this->name = name;
        cout << "constructor" << endl;
    }
    
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
    }    
    void show() {
        cout << name << endl;
    }
private : 
        string name;
};

People func() {
    People temp_a("byt");
    return temp_a;
}

int main() {
    //People a = func();
    People a("bao");
    a.show();
    People b(a);
    b.show();
    return 0;
}

