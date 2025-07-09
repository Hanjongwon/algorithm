#include <bits/stdc++.h>
using namespace std;
vector<int> ret;
vector<pair<int, double>> fail_info;
int cnt, val_cnt;
double fail_ratio;

bool cmp(const pair<int, double> &a, const pair <int, double> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    for (int i = 1; i <= N; i++) {
        cnt = 0;
        val_cnt = 0;
        for (int n : stages) {
            if (n >= i) {
                cnt++;
                if (n == i) val_cnt++;
            }
        }
        if (cnt == 0) fail_ratio = 0;
        else fail_ratio = static_cast<double> (val_cnt) / cnt;
        fail_info.push_back({i, fail_ratio});
    }
    sort(fail_info.begin(), fail_info.end(), cmp);
    
    for (auto& p : fail_info) ret.push_back(p.first);
    
    return ret;
}