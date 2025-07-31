#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, vector<int>>> v;
int n, k, country, gold, silver, bronze;

bool cmp(pair<int, vector<int>> p1, pair<int, vector<int>> p2) {
    vector<int> &v1 = p1.second;
    vector<int> &v2 = p2.second;

    if (v1[0] != v2[0]) return v1[0] > v2[0]; // 금
    if (v1[1] != v2[1]) return v1[1] > v2[1]; // 은
    return v1[2] > v2[2]; // 동
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> country >> gold >> silver >> bronze;
        v.push_back({country, {gold, silver, bronze}});
    }

    sort(v.begin(), v.end(), cmp);

    int rank = 1;
    for (int i = 0; i < n; i++) {
        if (v[i].first == k) {
            cout << rank << '\n';
            break;
        }
        if (i > 0 && v[i].second != v[i - 1].second) {
            rank = i + 1;
        }
    }
}