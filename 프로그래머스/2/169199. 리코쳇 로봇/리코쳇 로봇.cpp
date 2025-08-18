#include <bits/stdc++.h>
using namespace std;
int n, m, g_i, g_j, MAX = 987654321, visited[104][104], ret;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int bfs(int y, int x, const vector<string>& board) {
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while(!q.empty()) {
        tie(y, x) = q.front(); q.pop();
        
        if (y == g_i && x == g_j) return visited[y][x]-1;
       
        for (int i = 0; i < 4; i++) {
           int k = 1;
         
           while(1) {
               int temp_y = y + k*dy[i];
               int temp_x = x + k*dx[i];
               
               if (temp_y < 0 || temp_x < 0 || temp_y >= n || temp_x >= m) break;
               if (board[temp_y][temp_x] == 'D') break;
               k++;
           }
           
            int ny = y + (k-1) * dy[i];
            int nx = x + (k-1) * dx[i];
            
            if (ny == y && nx == x) continue;
            if (visited[ny][nx] > visited[y][x] + 1) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
       }
    }
    return -1;
}


int solution(vector<string> board) {
    n = board.size();
    m = board[0].size();
    fill(&visited[0][0], &visited[0][0] + 104 * 104, MAX);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'G') {
                g_i = i;
                g_j = j;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') return bfs(i, j, board);
        }
    }
}