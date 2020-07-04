/*************************************************************************
	> File Name: vector2.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年07月18日 星期三 22时38分12秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct test {
private:
    vector<int> y;

public:
    test(vector<int> &yy) : y(yy) {}
    bool operator()(int x)const {
        return find(begin(y), end(y), x) != end(y);
    }
};

int main() {
    vector<int> x = {1, 2, 3, 4, 5};
    vector<int> y = {1, 2, 3, 4, 5};
    auto count = count_if(begin(x), end(x), test(y));
    cout << count << endl;
    return 0;
}

