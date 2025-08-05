#include <bits/stdc++.h>
using namespace std;
stack<char> stk;
int ret;

int solution(string s)
{
    for (int i = 0; i < s.size(); i++) {
        if(stk.size() == 0) {
            stk.push(s[i]);
            continue;
        }
        
        char top = stk.top();
        if (top == s[i]) {
            stk.pop();
            continue;
        }
        stk.push(s[i]);
    }
    
    if (stk.size() == 0) ret = 1;
    else ret = 0;
    
    return ret;
}