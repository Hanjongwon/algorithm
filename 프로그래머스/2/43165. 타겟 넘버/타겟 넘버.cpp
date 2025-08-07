#include <bits/stdc++.h>
using namespace std;
int ret;

int solution(vector<int> numbers, int target) {
    int n = numbers.size();
    
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += numbers[i]; //비트가 1일 경우 +
            else sum -= numbers[i];
        }
        if (target == sum) ret++;
    }
    return ret;
}