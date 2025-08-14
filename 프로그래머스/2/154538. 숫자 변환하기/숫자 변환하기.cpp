#include <bits/stdc++.h>
using namespace std;
int visited[1000004];

int bfs(int x, int y, int n) {
    visited[x] = 1;
    queue<int> q;
    q.push(x);
    
    while(!q.empty()) {
        int value = q.front(); q.pop();
        if (value == y) return visited[value] - 1;

        int next_vals[3] = { value + n, value * 2, value * 3 };
        for (int i = 0; i < 3; i++) {
            int nv = next_vals[i];
            if (nv <= y && visited[nv] == 0) { // 목표 y를 기준으로 범위 제한
                visited[nv] = visited[value] + 1;
                q.push(nv);
            }
        }
    }
    return -1; // 도달 불가
}

int solution(int x, int y, int n) {
    memset(visited, 0, sizeof(visited)); // 방문 배열 초기화
    return bfs(x, y, n);
}