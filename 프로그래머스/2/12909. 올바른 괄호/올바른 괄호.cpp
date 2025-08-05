#include <bits/stdc++.h>
using namespace std;
stack<char> stk;

bool solution(string s)
{ 

    for (char c : s) {
        if (stk.empty()) {
            stk.push(c);
            continue;
        }
        
        if (stk.top() == '(' && c == ')') {
            stk.pop();
            continue;
        }
        
        stk.push(c);
    }

    return stk.empty();  // 불필요한 ret 제거
}