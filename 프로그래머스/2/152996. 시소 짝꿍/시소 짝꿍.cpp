#include <bits/stdc++.h>
using namespace std;

long long solution(vector<int> weights) {
    unordered_map<int, long long> cnt;   // 과거에 본 몸무게 → 빈도
    long long ans = 0;

    // 가능한 좌석 거리 비율 (분자, 분모). 양방향을 모두 포함
    const pair<int,int> ratios[] = {
        {1,1}, {2,3}, {3,2}, {2,4}, {4,2}, {3,4}, {4,3}
    };

    for (int w : weights) {
        for (auto [num, den] : ratios) {
            long long lhs = 1LL * w * den;         // w * 분모
            if (lhs % num != 0) continue;          // 정수로 딱 떨어질 때만
            int target = (int)(lhs / num);         // 맞춰야 하는 상대 몸무게
            auto it = cnt.find(target);
            if (it != cnt.end()) ans += it->second;
        }
        cnt[w]++;                                   // 현재 몸무게를 ‘과거’로 등록
    }
    return ans;
}