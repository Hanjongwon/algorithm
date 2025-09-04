#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    vector<bool> visited(n + 1, false);
    
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;

        // 그룹 A 시작
        int cntA = 0, curr = i;
        vector<bool> local_visited(n + 1, false);

        while (!local_visited[curr]) {
            local_visited[curr] = true;
            visited[curr] = true;
            curr = cards[curr - 1];
            cntA++;
        }

        // 그룹 B 찾기
        for (int j = 1; j <= n; ++j) {
            if (visited[j]) continue;

            int cntB = 0, currB = j;
            while (!visited[currB]) {
                visited[currB] = true;
                currB = cards[currB - 1];
                cntB++;
            }

            answer = max(answer, cntA * cntB);

            // B 그룹 끝났으니 다시 visited 복구
            currB = j;
            while (cntB--) {
                visited[currB] = false;
                currB = cards[currB - 1];
            }
        }
    }

    return answer;
}