#include <bits/stdc++.h>
using namespace std;
vector<int> ret;

vector<int> solution(int n, long long k) {
    // 1) factorial 미리 계산 (20!은 64비트 정수에 안전)
    vector<unsigned long long> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;

    // 2) 범위 체크 (1 ≤ k ≤ n!)
    if (k < 1 || k > fact[n]) return {};

    // 3) 후보들 [1..n]
    vector<int> cand(n);
    iota(cand.begin(), cand.end(), 1);

    // 4) 0-based로 변환
    --k;

    // 5) 앞자리부터 선택
    vector<int> ans; ans.reserve(n);
    for (int i = n; i >= 1; --i) {
        unsigned long long block = fact[i - 1];  // 같은 앞자리 반복 크기
        unsigned long long idx = k / block;      // 이번 자릿수 인덱스(0-based)
        k %= block;                               // 다음 자리용 k 갱신

        ans.push_back(cand[(size_t)idx]);        // 선택
        cand.erase(cand.begin() + (ptrdiff_t)idx); // 후보에서 제거
    }
    return ans;
}