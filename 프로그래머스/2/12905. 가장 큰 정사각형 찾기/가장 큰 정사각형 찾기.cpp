#include <bits/stdc++.h>
using namespace std;
int n, m, max_width, dp[1004][1004];

int solution(vector<vector<int>> board)
{
    n = board.size();
    m = board[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                max_width = max(max_width, dp[i][j]);
            }
        }
    }
    return max_width * max_width;
}