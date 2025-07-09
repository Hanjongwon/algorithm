#include <bits/stdc++.h>
using namespace std;
int glo_n;

bool cmp (string &a, string &b) {
    if (a[glo_n] == b[glo_n]) return a < b;
    return a[glo_n] < b[glo_n];
}

vector<string> solution(vector<string> strings, int n) {
    glo_n = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}