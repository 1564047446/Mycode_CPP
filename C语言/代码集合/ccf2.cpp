/*************************************************************************
	> File Name: ccf2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月20日 星期一 14时51分54秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define Max_Range 1010

int key_Sort[Max_Range] = {0};

struct key {
    int w, s, c;
};
key key_Start[Max_Range], key_End[Max_Range];

int cmp_Start(key a, key b)
{
    return a.s < b.s;
}

int cmp_End(key a, key b)
{
    if(a.c == b.c) return a.w < b.w;
    return a.c < b.c;
}

int main()
{
    int n, k, w, s, c;
    int maxn = 0, minn = 1000;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++) {
        scanf("%d%d%d", &w, &s, &c);
        key_Start[i].w = w, key_Start[i].s = s, key_Start[i].c = s + c;
        key_End[i].w = w, key_End[i].s = s, key_End[i].c = s + c;
        if(s < minn) minn = s;
        if(s + c > maxn) maxn = s + c;
    }
    for(int i = 1; i <= n; i++)
        key_Sort[i] = i;
    sort(key_Start + 1, key_Start + k + 1, cmp_Start);
    sort(key_End + 1, key_End + k + 1, cmp_End);
    int start = 1, end = 1;
    for(int i = minn; i <= maxn; i++) {
        //start = 1, end = 1;
        //cout << "lalal" << endl;
        while(i == key_End[start].c) {            //还钥匙
            for(int j = 1; j <= n; j++) {
                if(key_Sort[j] == 0) {
                    key_Sort[j] = key_End[start].w;
                    start ++;
                    //cout << start << endl;
                    break;
                }
            }
        }
       // cout << "kkkkkkk" << endl;
        while(i == key_Start[end].s) {            //取钥匙
            for(int j = 1; j <= n; j++) {
                if(key_Sort[j] == key_Start[end].w) {
                    key_Sort[j] = 0;
                    end ++;
                   // cout << end << endl;
                    break;
                }
            }
        }
        //``cout << "oooo" << endl;
    }
    for(int i = 1; i <= n - 1; i++)
        printf("%d ", key_Sort[i]);
    printf("%d\n", key_Sort[n]);
    //printf("\n");
}
