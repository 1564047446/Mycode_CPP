/*************************************************************************
	> File Name: forward.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年07月18日 星期三 22时05分58秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::forward;

void print(int &x) {
    cout << "this is &" << endl;
}

void print(int &&x) {
    cout << "this is &&" << endl;
}

template<typename T> void CallPrint(T&& x) {
    //print(forward<T>(x));
    print(x);
    return ;
}

int main() {
    int x = 0;
    CallPrint(x);
    CallPrint(0);
    return 0;
}

