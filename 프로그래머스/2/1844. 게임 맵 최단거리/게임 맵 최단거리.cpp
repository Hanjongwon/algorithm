#include<bits/stdc++.h>
using namespace std;
int ret, visited[104][104];
const int dy[] = {-1, 0 , 1, 0};
const int dx[] = {0, 1, 0, -1};

int bfs(int y, int x, vector<vector<int>>& maps) {
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y,x});
    
    while(!q.empty()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
          	
            if (ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size()) continue;
            if (maps[ny][nx] == 0 || visited[ny][nx] != 0) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
            
            if (ny == maps.size()-1 && nx == maps[0].size()-1) return visited[ny][nx]; 
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    return bfs(0, 0, maps);
}