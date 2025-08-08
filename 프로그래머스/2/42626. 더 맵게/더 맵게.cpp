#include <bits/stdc++.h>
using namespace std;

int ret;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i : scoville) pq.push(i);
    
    while (pq.size() >= 2 && pq.top() < K) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int new_scoville = first+second*2;
        pq.push(new_scoville);
        ret++;
    }
    if (pq.top() < K) return -1;
    return ret;
}