#include <bits/stdc++.h>
using namespace std;

int solution(int storey) {
    int ans = 0;
    while (storey > 0) {
        int d = storey % 10;          // 현재 1의 자리
        int next = (storey / 10) % 10; // 다음 자리(십의 자리)

        if (d < 5) {
            ans += d;
            storey /= 10;
        } else if (d > 5) {
            ans += (10 - d);
            storey = storey / 10 + 1; // 올림(캐리)
        } else { // d == 5
            if (next >= 5) {
                ans += 5;
                storey = storey / 10 + 1; // 올림
            } else {
                ans += 5;
                storey /= 10;              // 내림
            }
        }
    }
    return ans;
}