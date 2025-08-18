#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int> pq;
    
    for (int i = 0; i < enemy.size(); i++) {
        n -= enemy[i];
        pq.push(enemy[i]);
        
        if (n < 0) {
            if (k > 0) {
                n += pq.top();
                pq.pop();
                k--;
            }
            else return i;
        }
    }
    return enemy.size();
}