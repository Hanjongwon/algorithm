#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> rk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    v.resize(n);
    rk.resize(n);
    fill(rk.begin(), rk.end(), 1);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // 사람마다 돌면서 나보다 덩치가 큰 사람 체크 -> 있으면 등수 ++
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (v[i].first < v[j].first && v[i].second < v[j].second) {
                rk[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << rk[i] << ' ';
    }
    cout << '\n';
}