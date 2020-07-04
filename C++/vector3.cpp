/*************************************************************************
	> File Name: vector3.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年07月19日 星期四 21时41分41秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::prev;
using std::next;

template<typename T> void bubble_sort(T first, T second) {
    if (first == second || next(first) == second) return ;
    for (auto i = first; i != second; ++i) {
        for (auto j = prev(second); j != i; --j) {
            auto k = prev(j);
            if (*j < *k) {
                auto t = *k;
                *k = *j;
                *j = t;
            }
        }
    }
    return ;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    /*for (auto i = begin(arr); i < end(arr); ++i) {
        cout << *i << endl;
    }
    for (auto i : arr) {
        cout << i << endl;
    }*/
    {
        vector<int> brr{1, 2, 3};
        auto it = brr.end();
        --it;
        auto pv = prev(it, 1); //返回第n个前驱的迭代器指针，默认返回一个
        cout << *pv << endl;
    }
    {
        vector<int> brr = {3, 2, 1, 4, 5};
        bubble_sort(begin(brr), end(brr));
        for (auto i : brr) {
            cout << i << " ";
        }
        cout << endl;
    }
    {
        int brr[] = {1, 2, 3 , 5, 4, 0, 2, 2};
        bubble_sort(&brr[1], &brr[4]);
        for (auto i : brr) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

