#include <bits/stdc++.h>
using namespace std;
int ret;

int solution(int n)
{
    string s = to_string(n);
    for (char c : s) {
        ret += (int)c - '0';
    }

    return ret;
}