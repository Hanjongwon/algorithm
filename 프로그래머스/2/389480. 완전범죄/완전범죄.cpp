#include <bits/stdc++.h>
using namespace std;

bool dp[42][122][122];

int solution(vector<vector<int>> info, int n, int m) {
    int len = info.size(); // 물건의 총 개수
    
    memset(dp, false, sizeof(dp));
    dp[0][0][0] = true;
    
    for (int i = 0; i < len; i++) {
        int A = info[i][0];
        int B = info[i][1];
        
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if(!dp[i][a][b]) continue; // 만약에 불가능한 상황은 continue (누적합 상황)
                
                int new_A = a + A; // A를 선택하는 경우
                if (new_A < n) dp[i+1][new_A][b] = true;
                
                int new_B = b + B; // B를 선택하는 경우
                if (new_B < m) dp[i+1][a][new_B] = true;
            }
        }
    }
    
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (dp[len][a][b]) return a;
        }
    }
    
    
    return -1;
}