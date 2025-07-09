#include <bits/stdc++.h>
using namespace std;
int ret;

bool check(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(int n) {
    for (int i = 2; i <= n; i++) {
        if (check(i)) ret++;
    }
    return ret;
}