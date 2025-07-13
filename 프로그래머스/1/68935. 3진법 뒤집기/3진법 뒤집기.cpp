#include <bits/stdc++.h>
using namespace std;
int ret;
vector<int> v;

int solution(int n) {
    while (n) {
        int i = n % 3; //나머지
        v.push_back(i);
        n /= 3;
    } 
    int t;
    for (int i = 0; i < v.size(); i++) {
        ret += (v[i] * pow(3, v.size() - (i+1)));
    }
    return ret;
}