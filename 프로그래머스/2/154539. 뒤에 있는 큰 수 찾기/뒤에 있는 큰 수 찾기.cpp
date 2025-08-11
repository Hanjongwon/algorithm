#include <bits/stdc++.h>
using namespace std;
vector<int> ret;
int n;
stack<int> stk;

vector<int> solution(vector<int> numbers) {
    n = numbers.size();
    ret.resize(n);
    fill(ret.begin(), ret.end(), -1);
    
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && numbers[stk.top()] < numbers[i]) {
            ret[stk.top()] = numbers[i];
            stk.pop();
        }
        
        stk.push(i);
    }
    
    return ret;
}