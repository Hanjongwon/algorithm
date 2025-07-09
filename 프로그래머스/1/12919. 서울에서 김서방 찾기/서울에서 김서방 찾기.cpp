#include <bits/stdc++.h>
using namespace std;
string ret;
int n;

string solution(vector<string> seoul) {
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") n = i;
    }
    ret += "김서방은 ";
    ret += to_string(n);
    ret += "에 있다";
    return ret;
}