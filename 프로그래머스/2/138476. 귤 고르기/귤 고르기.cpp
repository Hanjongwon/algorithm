#include <bits/stdc++.h>
using namespace std;

int cnt[10000004];
vector<pair<int, int>> v;
unordered_set<int> s;

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second > p2.second;
}

int solution(int k, vector<int> tangerine) {
    for (int i : tangerine) {
        cnt[i]++;
        s.insert(i);
    }
    
    for (int i : s) {
        v.push_back({i, cnt[i]});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int ret = 1;
    int seq = 0;    
    while(1) {
        k -= v[seq].second;
        if (k <= 0) break;
        ret++;
        seq++;
    }
    return ret;
}