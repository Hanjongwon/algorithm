#include <bits/stdc++.h>
using namespace std;
int ret;

int to_min(const string& s) {
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    return h*60 + m;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> v; // (start, end_with_clean)
    for (auto & bt : book_time) {
        int start = to_min(bt[0]);
        int end = to_min(bt[1]) + 10;
        v.push_back({start, end});
    }
    
    //시작 시간 기준 정렬
    sort(v.begin(), v.end());
    
    // 사용 중인 방들의 "비는 시각"을 담는 최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (auto &it : v) {
        int start = it.first;
        int end_with_clean = it.second;
        
        //가장 빨리 비는 방이 현재 예약 시작 이전 / 같으면 재사용
        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }
        
        pq.push(end_with_clean);
        ret = max(ret, (int)pq.size());
    }    
    return ret;
}