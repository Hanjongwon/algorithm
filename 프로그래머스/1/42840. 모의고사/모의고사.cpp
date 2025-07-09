#include <bits/stdc++.h>
using namespace std;
vector<int> v, ret;
vector <vector <int>> vec = {{1,2,3,4,5},
             {2,1,2,3,2,4,2,5},
             {3,3,1,1,2,2,4,4,5,5}
            };
int max_cnt = -1;

vector<int> solution(vector<int> answers) {
    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        for (int j = 0; j < answers.size(); j++) {
            int k = j % vec[i].size();
            if (answers[j] == vec[i][k]) cnt++;
        }
        if (max_cnt <= cnt) max_cnt = cnt; 
        v.push_back(cnt);
    }
    for (int i = 0; i < 3; i++) {
        if (v[i] == max_cnt) ret.push_back(i+1);
    }
    return ret;
}