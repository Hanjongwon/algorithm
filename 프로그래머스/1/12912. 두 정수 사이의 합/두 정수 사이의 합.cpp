#include <bits/stdc++.h>

using namespace std;
long long ret;

long long solution(int a, int b) {
    for (int i = min(a,b); i < max(a,b)+1; i++) {
        ret += i;
    }
    
    return ret;
}