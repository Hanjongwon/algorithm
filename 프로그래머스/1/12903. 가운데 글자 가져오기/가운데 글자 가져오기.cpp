#include <bits/stdc++.h>

using namespace std;
int a, b;

string solution(string s) {
    string answer = "";
    a = s.size() / 2;
    b = s.size() % 2;
    if (b == 0){
        answer += s[a-1];
        answer += s[a];
    }
    else answer += s[a];
    return answer;
}