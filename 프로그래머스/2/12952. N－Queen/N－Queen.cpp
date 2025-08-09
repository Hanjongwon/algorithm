#include <bits/stdc++.h>
using namespace std;

int ret;                  // 해답 개수
vector<int> used_col;     // 열 사용 여부
vector<int> used_diag1;   // ↘ 대각선(r+c)
vector<int> used_diag2;   // ↙ 대각선(r-c+n-1)

void dfs(int r, int n) {
    if (r == n) {         // 모든 행에 퀸 배치 완료
        ret++;
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (used_col[c]) continue;
        if (used_diag1[r + c]) continue;
        if (used_diag2[r - c + n - 1]) continue;

        // (r, c)에 퀸을 놓음
        used_col[c] = used_diag1[r + c] = used_diag2[r - c + n - 1] = 1;
        dfs(r + 1, n);
        // 백트래킹(되돌리기)
        used_col[c] = used_diag1[r + c] = used_diag2[r - c + n - 1] = 0;
    }
}

int solution(int n) {
    ret = 0;
    used_col.assign(n, 0);
    used_diag1.assign(2 * n - 1, 0);
    used_diag2.assign(2 * n - 1, 0);

    dfs(0, n);
    return ret;
}