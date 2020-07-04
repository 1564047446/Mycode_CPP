/*************************************************************************
	> File Name: 左值引用与右值引用.cpp
	> Author:  byt 
	> Mail: baotongyu1995@163.com
	> Created Time: 2018年07月18日 星期三 21时06分56秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> MakeVector(int start, int end) {
    vector<int> numbers;
    for (int i = start; i <= end; ++i) {
        numbers.push_back(i);
    }
    return numbers;
}

class Sum {
private:
    vector<int> numbers;

public:
    explicit Sum(const vector<int>& theNumbers) : numbers{theNumbers} {}
    int Get() {
        int sum = 0;
        for (auto i : numbers) {
            sum += i;
        }
        return sum;
    }
};

int main() {
    Sum sum( MakeVector(1, 10) );
    cout << sum.Get() << endl;
    return 0;
}

