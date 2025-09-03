#include <bits/stdc++.h>
using namespace std;
vector<string> ret;
stack<pair<string, int>> remained;
int int_max = 987654321, next_start;

int get_minutes(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

bool cmp(vector<string> v1, vector<string> v2){
    return get_minutes(v1[1]) < get_minutes(v2[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(), plans.end(), cmp);
    
    for (int i = 0; i < plans.size(); i++) {
        string name = plans[i][0];
        int start = get_minutes(plans[i][1]);
        int time = stoi(plans[i][2]);
        
        if (i + 1 < plans.size()) {
            next_start = get_minutes(plans[i+1][1]);
        }
        else {
            next_start = int_max;
        }
        
        int remain_time = next_start - start;
        
        if (remain_time >= time) {
            // 현재 과제 끝냄
            ret.push_back(name);
            remain_time -= time;
            
            // 남은 시간동안 멈춰둔 과제 이어 하기
            while (!remained.empty() && remain_time > 0) {
                auto p = remained.top();
                string p_name = p.first;
                int p_time = p.second;
               	remained.pop();
                
                if (remain_time >= p_time) {
                    ret.push_back(p_name);
                    remain_time -= p_time;
                }
                else {
                    remained.push({p_name, p_time - remain_time});
                    remain_time = 0;
                    break;
                }
            }
        }
        else {
            remained.push({name, time-remain_time});
        }
    }
    
    // 이후에는 새 과제가 없으므로 스택을 차례대로 처리
    while (!remained.empty()) {
        ret.push_back(remained.top().first);
        remained.pop();
    }
   
    return ret;
}