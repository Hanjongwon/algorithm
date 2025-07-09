#include <bits/stdc++.h>
using namespace std;

// 콜라츠 함수: 짝수는 2로 나누고, 홀수는 3을 곱하고 1 더함
void col(long long & n) {
    if (n % 2 == 0) {
        n /= 2;
    } else {
        n = n * 3 + 1;
    }
}

// 콜라츠 추측 함수
int solution(int num) {
    int ret = 0; // 지역 변수로 초기화
    long long n = num;
    
    while (n != 1) {
        col(n);
        ret++;
        if (ret == 500) return -1;
    }
    return ret;
}