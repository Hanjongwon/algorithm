#include <bits/stdc++.h>
using namespace std;
string ret;

string solution(int num) {
    if (num % 2 == 0) ret = "Even";
    else ret = "Odd";
    return ret;
}