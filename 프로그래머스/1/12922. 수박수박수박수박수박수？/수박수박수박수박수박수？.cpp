#include <bits/stdc++.h>
using namespace std;
string ret;
int a, b;

string solution(int n) {
    a = n / 2;
    b = n % 2;
    
    for (int i = 0; i < a; i++) {
        ret += "수박";
    }
    if (b == 1) ret += "수";
    return ret;
}