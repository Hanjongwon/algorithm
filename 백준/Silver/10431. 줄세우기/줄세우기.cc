#include <iostream>
#include <vector>
using namespace std;

int t, tall;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int test = 1; test <= t; test++) {
        vector<int> v;
        int cnt = 0;
        int dummy;
        cin >> dummy;  // 테스트 번호 (예: 1~20 중 하나)

        for (int i = 0; i < 20; i++) {
            cin >> tall;
            int idx = 0;
            while (idx < v.size() && v[idx] < tall) idx++;
            cnt += v.size() - idx;
            v.insert(v.begin() + idx, tall);
        }

        cout << test << ' ' << cnt << '\n';
    }
}