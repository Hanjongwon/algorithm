#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, visited[104][104];
vector<int> ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x, const vector<string> &maps) {
    visited[y][x] = 1;
    cnt += (int) (maps[y][x] - '0');
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx] || maps[ny][nx] == 'X') continue;
        dfs(ny, nx, maps);
    }
}

vector<int> solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
	
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && maps[i][j] != 'X') {
                cnt = 0;
                dfs(i, j, maps);
                ret.push_back(cnt);
            }
        }
    }
    if (ret.empty()) ret.push_back(-1);
    else
        sort(ret.begin(), ret.end());
    
    return ret;
}