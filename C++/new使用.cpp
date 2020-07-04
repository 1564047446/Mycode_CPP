/*************************************************************************
	> File Name: new使用.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年07月19日 星期四 00时21分04秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

class A {
private:
    int i;
public:
    A(int x) : i(x) {}
    void print() {
        cout << this->i << endl;
    }
};

int main() {
    A *p = new A(3);
    p->print();
    char s[1000];
    A *q = (A*)s;
    new(q) A(4);
    q->print();
    return 0;
}

