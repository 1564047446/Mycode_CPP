/*************************************************************************
	> File Name: 计算平均分.cpp
	> Author: byt
	> Mail: baotongyu@zt.game
	> Created Time: 2018年09月12日 星期三 10时39分37秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    int n;
    map<string, vector<double> > data;
    vector< pair<string, double> > ret;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        double score;
        cin >> name >> score;
        data[name].push_back(score);
    }
    for (auto it : data) {
        sort(begin(it.second), end(it.second), [](auto a, auto b) { return a > b; });
        int count = 0;
        ret.push_back(make_pair(
            it.first,
            accumulate(
                begin(it.second),
                (it.second.size() < 5 ? end(it.second) : begin(it.second) + 5),
                0.0,
                [&](auto a, auto b) {
                    ++count;
                    return a + b;
                }
                ) / count
            ));
    }
    sort(
        begin(ret), 
        end(ret),
        [](auto a, auto b) {
            if (a.second > b.second) return true;
            if (a.second == b.second && a.first < b.first) return true;
            return false;
        }
        );

    for (auto p : ret) {
        cout << p.first << " " << fixed << setprecision(2) << p.second << endl;

    }

    return 0;
    
}

