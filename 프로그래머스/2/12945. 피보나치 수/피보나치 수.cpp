#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, res;
    for (int i = 2; i <= n; ++i) {
        res = (a + b) % 1234567;
        a = b;
        b = res;
    }
    return res;
}