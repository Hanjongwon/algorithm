#include <bits/stdc++.h>
using namespace std;
long long dp[2001];
const int MOD = 1234567;


long long solution(int n) {
    dp[0] = 0, dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        int val = dp[i-1] + dp[i-2];
        dp[i] = val % MOD;
    }
   
    return dp[n];
}