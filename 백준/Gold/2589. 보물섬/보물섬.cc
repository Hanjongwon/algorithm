#include <bits/stdc++.h>
using namespace std;

int n, m, visited[50][50], ret = -987654321;  // n: 세로, m : 가로
char arr[50][50];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    int cnt = 0;

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (arr[ny][nx] == 'W') continue;

            visited[ny][nx] = visited[y][x] + 1;
            cnt             = max(cnt, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'L') {
                int cnt = bfs(i, j);
                ret     = max(cnt, ret);
            }
        }
    }
    cout << ret - 1;
}