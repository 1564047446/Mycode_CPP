/*************************************************************************
	> File Name: 重载运算符.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月27日 星期二 18时41分45秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &out, const vector<int> &arr) {
    out << "[";
    for (auto x = arr.begin(); x != arr.end(); x++) {
        out << *x << " ";
    }
    out << "]";
    return out;
}

int main() {
    vector<int> arr;
    for (int i = 0; i < 3; i++) {
        arr.push_back(i);
    }
    cout << arr << endl;
    return 0;
}
