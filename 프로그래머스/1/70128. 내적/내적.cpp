#include <bits/stdc++.h>
using namespace std;
int ret;

int solution(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); i++) {
        ret += (a[i] * b[i]);
    }
    return ret;
}