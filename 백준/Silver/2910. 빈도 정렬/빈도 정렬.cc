#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> freq, order;
vector<pair<int, int>> vv;
int n, c;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return order[a.first] < order[b.first];
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        freq[m]++;
        if (!order.count(m)) order[m] = i;
    }

    for (auto& p : freq) {
        vv.push_back({p.first, p.second});
    }

    sort(vv.begin(), vv.end(), cmp);

    for (auto& p : vv) {
        for (int i = 0; i < p.second; i++) {
            cout << p.first << ' ';
        }
    }
}