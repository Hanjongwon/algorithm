#include <bits/stdc++.h>
using namespace std;
vector<int> real_lost;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int ret = n;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    //자기 체육복이 있는 경우 그걸 입음
    for (int i : lost) {
        auto it = find(reserve.begin(), reserve.end(), i);
        if (it != reserve.end()) {
            reserve.erase(it);
        }
        else real_lost.push_back(i);
    }
    
    for(int i : real_lost) {    
        auto it_ = find(reserve.begin(), reserve.end(), i-1);
        if (it_ != reserve.end()){
            reserve.erase(it_);
            continue;
        }
        else{
            auto it = find(reserve.begin(), reserve.end(), i+1);
                if (it != reserve.end()) {
                    reserve.erase(it);
                    continue;
                }
                else ret--;
        }
    }
    return ret;
}