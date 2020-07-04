/*************************************************************************
	> File Name: stack.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年07月20日 星期五 21时30分10秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <stack>

using std::cin;
using std::cout;
using std::stringstream;
using std::string;
using std::stack;
using std::endl;


struct Elem {
    Elem() {}
    Elem(char _op) : op(_op) {}
public:
    int number = 0;
    char op = '\0';
};

int Run(stack<Elem>&);

int Push(stack<Elem>& sta, int number) {
    sta.top().number = number;
    switch (sta.top().op) {
        case '*':
        case '/': Run(sta); break;
    }
    return 0;
}

int Pop(stack<Elem>& sta) {
    while (sta.top().op != '\0') {
        Run(sta);
    }
    auto number = sta.top().number;
    sta.pop();
    return number;
}

int Run(stack<Elem>&sta) {
    auto second = sta.top();
    sta.pop();
    auto &first = sta.top().number;
    switch (second.op) {
        case '+':
            first += second.number;
            break;
        case '-':
            first -= second.number;
            break;
        case '*':
            first *= second.number;
            break;
        case '/':
            first /= second.number;
            break;
    }
}

int Caculate(string exp) {
    stringstream ss(exp);
    stack<Elem> sta;
    sta.push({});
    while (true) {
        char op = ss.peek();
        switch (op) {
            case '(': {
                sta.push({});
                break;
            }
            case ')': {
                Push(sta, Pop(sta));
                break;
            }
            case '+': case '-': case '*': case '/':
                Elem elem(op);
                sta.push(elem);
                break;
        }
        if (isdigit(op)) {
            int number;
            ss >> number;
            Push(sta, number);
        } else if (ss.eof()) {
            return Pop(sta);
        } else {
            ss.ignore();
        }
    }
}

int main() {
    string str;
    while (cin >> str) {
        cout << Caculate(str) << endl;
    }
    return 0;
}

