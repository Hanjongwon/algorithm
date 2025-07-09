#include <bits/stdc++.h>
using namespace std;
vector<char> v;
string temp;

long long solution(long long n) {
    string s = to_string(n);
    v.assign(s.begin(), s.end());
    sort(v.begin(), v.end(), greater<int>());
    temp.assign(v.begin(), v.end());
    return stoll(temp);
}