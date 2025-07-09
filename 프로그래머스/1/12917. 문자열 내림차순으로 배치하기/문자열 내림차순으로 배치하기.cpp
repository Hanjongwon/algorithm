#include <bits/stdc++.h>

using namespace std;

bool cmp(const char& a, const char& b) {
    return a > b;
}

string solution(string s) {
    sort(s.begin(), s.end(), cmp);
    return s;
}