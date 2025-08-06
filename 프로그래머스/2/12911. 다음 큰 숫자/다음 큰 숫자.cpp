#include <bits/stdc++.h>
using namespace std;
int cnt;

int one_cnt(int num) {
    int cnt1 = 0;
    while(true) {
        int a = num % 2;
        if(a == 1) cnt1++;
        if(num == 0 || num == 1) break;
        num /= 2;
    }
    return cnt1;
}

int solution(int n) {
    cnt = one_cnt(n);
    cout << cnt;
    while(true) {
        n++;
        if (cnt == one_cnt(n)) break;
    }
    
    return n;
}