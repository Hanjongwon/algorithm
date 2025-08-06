#include <bits/stdc++.h>
using namespace std;
vector<int> ret;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    while(!progresses.empty()) {
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        
        if (progresses[0] >= 100) {
            int cnt = 0;
            
            while(!progresses.empty() && progresses[0] >= 100) {
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                cnt++;
            }
            ret.push_back(cnt);
        }
    }
    return ret;
}