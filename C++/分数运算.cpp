/*************************************************************************
	> File Name: 分数运算.cpp
	> Author: byt
	> Mail: baotongyu@zt.game
	> Created Time: 2018年09月11日 星期二 22时07分58秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ratio>

using namespace std;

int main() {
    
    ratio<5, 3> five;
    cout << five.num << "/" << five.den << endl;
    ratio<2, 4> two;
    cout << two.num << "/" << two.den << endl;
    //ratio_add<decltype(five), decltype(two)> sum;
    //ratio_add<two, five> sum;
    auto sum = ratio_add<decltype(five), decltype(two)>;
    cout << sum.num << "/" << sum.den << endl;
    return 0;
}
