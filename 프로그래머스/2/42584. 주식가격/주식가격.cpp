#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s;  // 인덱스를 저장

    for (int i = 0; i < n; i++) {
        // 현재 가격이 스택 상단의 가격보다 작으면 pop
        while (!s.empty() && prices[i] < prices[s.top()]) {
            int top = s.top();
            s.pop();
            answer[top] = i - top;
        }
        s.push(i);  // 현재 인덱스를 스택에 추가
    }

    // 끝까지 가격이 떨어지지 않은 경우
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        answer[top] = n - top - 1;
    }

    return answer;
}