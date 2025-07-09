#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> mp;
int a, b, ret;

int solution(string s) {
    int answer = 0;
    int i = 0;
    
    while (i < s.size()) {
        char c = s[i];
        int c_cnt = 1;
        int not_c_cnt = 0;
        i++;
        while (i < s.size()) {
            if(s[i] == c) c_cnt++;
            else not_c_cnt++;
            
            i++;
            if (c_cnt == not_c_cnt) break;
        }
        answer++;
    }
    return answer;
}