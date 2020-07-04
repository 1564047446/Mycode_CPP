/*************************************************************************
	> File Name: test189.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年05月12日 星期六 20时57分12秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct A {
    A(int data) : data(data) {}
    int data;
};

struct B : virtual A {
    B() : A(3) {
        cout << this << endl;
    }
};

struct C : virtual B {
    C() : A(4) {
        cout << this << endl;
    }
};

struct D : B, C {
    D() : A(4) {}
};

int main() {
    D d;
    cout << d.data << endl;
    return 0;
}
