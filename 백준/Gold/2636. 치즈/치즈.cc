#include <bits/stdc++.h>
using namespace std;

int arr[104][104];
int visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, cnt = 0, cnt2 = 0;
vector<pair<int, int>> v;

void solve(int y, int x) {
    visited[y][x] = 1;

    if (arr[y][x] == 1) {
        v.push_back({y, x});
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        solve(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    while (true) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        v.clear();

        solve(0, 0);

        for (auto p : v)
            arr[p.first][p.second] = 0;

        bool flag = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] != 0)
                    flag = true;

        cnt++;
        if (!flag) {
            cnt2 = v.size();
            break;
        }
    }

    cout << cnt << '\n' << cnt2 << '\n';
}