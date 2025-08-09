#include <bits/stdc++.h>
using namespace std;
int ret;
const int MOD = 1000000007;

int solution(int n) {
    if (n == 1) return 1;
    long long a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        long long c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return (int)b;
}