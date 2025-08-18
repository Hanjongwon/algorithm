#include <bits/stdc++.h>
using namespace std;
int ret;
int shot = -987654321;

bool cmp(const vector<int>& v1, const vector<int>& v2) {
    if (v1[1] == v2[1]) return v1[0] < v2[0];
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), cmp);
    
    for (auto t : targets) {
        int start = t[0];
        int end = t[1];
        
        if (shot <= start) {
            ret++;
            shot = end;
        }
    }
    return ret;
}