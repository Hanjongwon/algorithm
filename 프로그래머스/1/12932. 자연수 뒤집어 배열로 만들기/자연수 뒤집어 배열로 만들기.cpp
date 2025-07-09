#include <bits/stdc++.h>
using namespace std;
vector<int> v;

vector<int> solution(long long n) {
    string s = to_string(n);
    for (char c : s) v.push_back((int)c - '0');
    
    reverse(v.begin(), v.end());
    
    return v;
}