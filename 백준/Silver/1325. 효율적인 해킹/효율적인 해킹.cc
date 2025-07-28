#include <bits/stdc++.h>
using namespace std;

int dp[10004], visited[10004], mx, n, m, a, b;
vector<int> v[10004];

int dfs(int here) {
    visited[here] = 1;
    int ret       = 1;

    for (int there : v[here]) {
        if (visited[there]) continue;
        ret += dfs(there);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;  // n : 컴퓨터 수, m : 신뢰관계 수

    while (m--) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        fill(visited, visited + 10004, 0);
        dp[i] = dfs(i);
        mx    = max(dp[i], mx);
    }
    for (int i = 1; i <= n; i++)
        if (mx == dp[i]) cout << i << " ";
}