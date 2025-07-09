#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int a[50][50];
vector<pair<int, int>> house, chicken;
vector<int> selected;
int result = 1e9;

int get_city_chicken_distance(const vector<int>& selected_chickens) {
    int sum = 0;
    for (auto& h : house) {
        int min_dist = 1e9;
        for (int idx : selected_chickens) {
            int dist = abs(h.first - chicken[idx].first) + abs(h.second - chicken[idx].second);
            min_dist = min(min_dist, dist);
        }
        sum += min_dist;
    }
    return sum;
}

void dfs(int idx, int depth) {
    if (depth == m) {
        result = min(result, get_city_chicken_distance(selected));
        return;
    }

    for (int i = idx; i < chicken.size(); i++) {
        selected.push_back(i);
        dfs(i + 1, depth + 1);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) house.push_back({i, j});
            else if (a[i][j] == 2) chicken.push_back({i, j});
        }
    }

    dfs(0, 0);
    cout << result << '\n';
    return 0;
}