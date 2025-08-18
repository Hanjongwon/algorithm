#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

long long solution(int r1, int r2) {
    long long R1 = r1, R2 = r2;
    long long ret = 0;

    for (long long x = 1; x <= R2; ++x) {
        // 바깥원에서 허용되는 최대 y
        long double outv = (long double)R2 * R2 - (long double)x * x;
        if (outv < 0) continue; // 안전빵
        long long y_max = (long long)floor(sqrtl(outv));

        // 안쪽원에서 배제되는 최소 y (y_min 미만은 안쪽원 내부)
        long double inv = (long double)R1 * R1 - (long double)x * x;
        long long y_min = 0;
        if (inv > 0) y_min = (long long)ceill(sqrtl(inv));
        // y는 1 이상만 고려(축 제외)
        long long start = max(1LL, y_min);

        if (y_max >= start) ret += (y_max - start + 1);
    }

    // 1) 내부 사분면의 점들 4배
    ret *= 4;

    // 2) 축 위의 점들 추가: (±x,0), (0,±y) 에서 r1 ≤ |coord| ≤ r2
    // 양의 쪽에서 (r2 - r1 + 1)개, 전체 4배
    ret += 4LL * (R2 - R1 + 1);

    return ret;
}