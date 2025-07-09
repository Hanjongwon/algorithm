#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int m, n, k;
int x_1, y_1, x_2, y_2, ret, cnt;
int a[104][104], visited[104][104];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<int> v;

int dfs(int y, int x) {
    visited[y][x] = 1;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (a[ny][nx] == 0 && visited[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        for (int y = y_1; y < y_2; y++) {
            for (int x = x_1; x < x_2; x++) {
                a[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cnt = 0;
            if (a[i][j] == 0 && visited[i][j] == 0) {
                cnt = dfs(i, j);
                v.push_back(cnt);
                ret++;
            }
        }
    }
    cout << ret << '\n';
    sort(v.begin(), v.end());
    for (int i : v) cout << i << ' ';
}