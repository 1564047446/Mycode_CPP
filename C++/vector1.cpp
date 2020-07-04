/*************************************************************************
	> File Name: vector1.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年07月18日 星期三 22时29分42秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> x = {1, 2, 3, 4, 5};
    vector<int> y = {3, 4, 5, 6, 7};
    auto count = count_if(begin(x), end(x), [&y](int x) {
        return find(begin(y), end(y), x) != end(y);
    });
    cout << count << endl;
    return 0;
}

