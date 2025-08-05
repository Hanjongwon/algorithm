#include <bits/stdc++.h>
using namespace std;

int visited[54][54], a[54][54], n, l, r, sum, ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    v.push_back({y, x});
    sum += a[y][x];  
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx<0 || nx>=n || ny<0 || ny>=n || visited[ny][nx])continue;
        if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while(true) {
        bool flag = false;
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(visited[i][j] == 0) {
                    sum = 0;
                    v.clear();
                    dfs(i, j);
                    if(v.size() == 1) continue;
                    for (auto p : v) {
                        a[p.first][p.second] = sum / v.size();
                    }
                    flag = true;
                }
            }
        }
        if(!flag) break;
        ret++;
    }
    cout << ret;
}