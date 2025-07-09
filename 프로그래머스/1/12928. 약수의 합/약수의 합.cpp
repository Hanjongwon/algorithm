#include <bits/stdc++.h>
using namespace std;
int ret;
vector <int> v;

int solution(int n) {
    if (n == 0 || n == 1) return n;
    
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if ((n / i) == i) continue;
            v.push_back(n / i);
        }
    }
    ret = accumulate(v.begin(), v.end(), 0);
    return ret;
}