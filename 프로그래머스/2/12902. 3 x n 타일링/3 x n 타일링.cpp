#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long ret[5004];

int solution(int n) {
    memset(ret, 0, sizeof(ret));
    if (n % 2) return 0;
   	ret[0] = 1;
    ret[2] = 3;
   	
    for (int i = 4; i <= n; i+=2) {
        long long val = (4 * ret[i-2] - ret[i-4]) % MOD;
        if (val < 0) val += MOD;
        ret[i] = val;
    }
    
    
    return (int)ret[n];
}