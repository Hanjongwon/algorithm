#include <algorithm>
#include <iostream>
using namespace std;

int a[104][104], e[104][104], visited[104][104];
int n, temp, ret = 1;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int h) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visited[ny][nx] == 0 && a[ny][nx] > h) dfs(ny, nx, h);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int h = 1; h < 101; h++) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > h && visited[i][j] == 0) {
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret << '\n';
}