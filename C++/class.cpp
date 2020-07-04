/*************************************************************************
	> File Name: class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月31日 星期六 09时17分49秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class People {
public :
    string name;
};

struct Piont {
    Piont(int x, int y) : x(x), y(y){

    }
    Piont(const Piont &a) : x(a.x), y(a.y) {

    }
    int x, y;
};

struct Test {
    Test(int x, int y) : p1(x, y), p2(p1) {
        cout << "build" << endl;
        Test::num++;
    }
    Test(const Test &a) : p1(a.p1), p2(a.p2) {
        Test::num++;
        cout << "copy" << endl;
    }
    Test &operator=(const Test &a) {
        cout << "get value" << endl;
        this->p1 = a.p1;
        this->p2 = a.p2;
        return *this; // b的地址
    }
    ~Test() {
        Test::num--;
    }
    static void print() {
        cout << "All num is " << Test::num << endl;
    }
    Piont p1;
    Piont p2;
private :
    static int num;
};

Test func() {
    Test temp(5, 6);
    Test::print();
    return temp;
}

int Test::num = 0;

ostream &operator<<(ostream &out, Piont &a) {
    out << "(" << a.x << ", " << a.y << ")" << endl;
}

int main() {
    //People a;
    //a.name = "byt";
    //cout << People::name << endl;
    Test a(2, 3), b = a;
    /*Test::print();
    Test c = func();
    Test::print();*/
    b = a; 
    // b.operator=(a);
    return 0;
}
