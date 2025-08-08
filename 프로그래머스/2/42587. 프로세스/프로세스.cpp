#include <bits/stdc++.h>
using namespace std;

int ret;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    for (int i = 0; i <  priorities.size(); i++) {
        q.push({i, priorities[i]});
    } 
    
    while(!q.empty()) {
        auto cur = q.front(); 
        q.pop();
        
        bool check = false;
        for (int n : priorities) {
            if (n > cur.second) {
                check = true;
                break;
            }
        }
        
        if (check) q.push(cur); //큐에 다시 넣음
        else {
            ret++;
            priorities[cur.first] = -1; //이미 실행된 프로세스는 제외
            if(cur.first == location) return ret;
        }
    }  
}