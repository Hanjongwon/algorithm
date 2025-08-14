#include <bits/stdc++.h>
using namespace std;
long long ret;
unordered_map<int, int> mp;
vector<pair<int, int>> ratios = {{1,1}, {2,3}, {3,2}, {2,4}, {3,4}, {4,2}, {4,3}};

long long solution(vector<int> weights) {
    for (int i : weights) {
        for (auto p : ratios) {
           	long long lhs = 1LL * i * p.second;
            if (lhs % p.first) continue;
            int check = lhs / p.first;
            if (mp.count(check) != 0) {
                ret += mp[check];
            }
        }
        mp[i]++;
    }
    return ret;
}