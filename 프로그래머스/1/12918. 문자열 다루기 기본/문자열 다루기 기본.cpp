#include <bits/stdc++.h>

using namespace std;
bool ret = true;

bool solution(string s) {   
    if (s.length() != 4 && s.length() != 6) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}