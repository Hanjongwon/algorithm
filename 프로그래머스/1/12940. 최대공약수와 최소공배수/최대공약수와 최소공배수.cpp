#include <bits/stdc++.h>
using namespace std;
vector<int> ret;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b); 
}

vector<int> solution(int n, int m) {
    int gcd_num = gcd(n, m);
    int lcm_num = lcm(n, m);
    ret.push_back(gcd_num);
    ret.push_back(lcm_num);
    return ret;
}