#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int l = 1, r = 1, sum = 1, ret = 0;
    
    while(l <= n / 2) {
        if (sum == n) {
            ret ++;
            sum -= l;
            l++;
        }
        else if (sum < n) {
            r++;
            sum += r;
        }
        else {
            sum -= l;
            l++;
        }
    }
    
    return ret + 1;
}