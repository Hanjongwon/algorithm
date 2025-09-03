#include <bits/stdc++.h>
using namespace std;
int ret, point;
stack<int> stk;

int solution(vector<int> order) {
    for (int i = 1; i < order.size()+1; i++) {
        // 1. i가 order[point]와 다른경우 -> stack에 넣기
        if (i != order[point]) stk.push(i);
        else { // 2. 같은 경우
           	point++;
            ret++;
            
            while (!stk.empty()) {
                int top = stk.top(); stk.pop();
               
                if (order[point] == top) {
                    ret++;
                    point++;
                }
                else {
                    stk.push(top);
                    break;
                }
            }
        }
    }
    return ret;
}