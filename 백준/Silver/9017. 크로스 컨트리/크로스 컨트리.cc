#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int t, n;
int p_check[1004];

bool cmp(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
    int sum_a = a.second[0] + a.second[1] + a.second[2] + a.second[3];
    int sum_b = b.second[0] + b.second[1] + b.second[2] + b.second[3];
    if (sum_a != sum_b) return sum_a < sum_b;
    return a.second[4] < b.second[4]; // 동점일 경우 5번째 등수 비교
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        fill(p_check, p_check + 1004, 0);
        vector<int> v;
        map<int, vector<int>> scores;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int team;
            cin >> team;
            v.push_back(team);
            p_check[team]++;
        }

        int rank = 0;
        for (int team : v) {
            if (p_check[team] < 6) continue;
            rank++;
            scores[team].push_back(rank);
        }


        vector<pair<int, vector<int>>> vec(scores.begin(), scores.end());
        sort(vec.begin(), vec.end(), cmp);

        cout << vec[0].first << '\n'; // 우승 팀 출력
    }

    return 0;
}