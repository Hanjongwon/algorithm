#include <bits/stdc++.h>
using namespace std;

int n, m, ret = -987654321;
int arr[8][8];
int arr_cpy[8][8];
int visited[8][8];
pair<int, int> p1, p2, p3;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (visited[ny][nx] == 0 && arr_cpy[ny][nx] == 0) {
            arr_cpy[ny][nx] = 2;
            dfs(ny, nx);
        }
    }
}

pair<int, int> make_loc(int l) {
    return {l / m, l % m};
}

int go() {
    arr_cpy[p1.first][p1.second] = 1;
    arr_cpy[p2.first][p2.second] = 1;
    arr_cpy[p3.first][p3.second] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr_cpy[i][j] == 2) dfs(i, j);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr_cpy[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // map 생성
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k;
            cin >> k;
            arr[i][j] = k;
        }
    }

    for (int i = 0; i < (n * m); i++) {
        p1 = make_loc(i);
        if (arr[p1.first][p1.second] != 0) continue;
        for (int j = i + 1; j < (n * m); j++) {
            p2 = make_loc(j);
            if (arr[p2.first][p2.second] != 0) continue;
            for (int k = j + 1; k < (n * m); k++) {
                p3 = make_loc(k);
                if (arr[p3.first][p3.second] != 0) continue;
                fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
                memcpy(arr_cpy, arr, sizeof(arr));  // 초기화
                ret = max(ret, go());
            }
        }
    }
    cout << ret;
}