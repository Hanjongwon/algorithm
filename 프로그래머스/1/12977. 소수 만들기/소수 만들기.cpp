#include <bits/stdc++.h>
using namespace std;
int ret;
vector<int> v;

bool check(int num) {
    if (num == 1) return false;
    if (num == 2 || num == 3) return true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int ret = 0;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i+1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (check(sum)) ret++;
            }
        }
    }
    return ret;
}