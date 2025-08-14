#include <bits/stdc++.h>
using namespace std;

int n, m;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int bfs(pair<int,int> start, char target, const vector<string>& maps) {
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;
    auto [sy, sx] = start;
    dist[sy][sx] = 0;
    q.push(start);

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        if (maps[y][x] == target) return dist[y][x];  // 최단거리 도착

        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (maps[ny][nx] == 'X') continue;        // 벽은 못 감
            if (dist[ny][nx] != -1) continue;         // 이미 방문
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return -1; // 도달 불가
}

int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();

    pair<int,int> S{-1,-1}, L{-1,-1}, E{-1,-1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == 'S') S = {i, j};
            else if (maps[i][j] == 'L') L = {i, j};
            else if (maps[i][j] == 'E') E = {i, j};
        }
    }

    int s2l = bfs(S, 'L', maps);
    if (s2l == -1) return -1;

    int l2e = bfs(L, 'E', maps);
    if (l2e == -1) return -1;

    return s2l + l2e;
}