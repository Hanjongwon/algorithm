#include <bits/stdc++.h>
using namespace std;
unordered_set <int> sums;

int solution(vector<int> elements) {
	int n = elements.size();
    
    for (int len = 1; len <= n; len++) {
        int cur = 0;
        for (int i = 0; i < len; i++) cur += elements[i];
        sums.insert(cur);
        
        // 시작을 1 ~ n-1씩 한 칸씩 이동
        for (int start = 1; start < n; start++) {
            cur -= elements[(start-1 + n) % n];
            cur += elements[(start + len - 1) % n];
            sums.insert(cur);
        }
    }
    return sums.size();
}