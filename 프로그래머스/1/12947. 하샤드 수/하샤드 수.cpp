#include <bits/stdc++.h>
using namespace std;
int tot;

bool solution(int x) {
    string s = to_string(x);
    for (char c : s) tot += ((int)c - '0');
    
    if (x % tot == 0) return true;
    else    return false;
}