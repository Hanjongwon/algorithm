#include <bits/stdc++.h>
using namespace std;
bool ret = true;
int a[200];

bool solution(string s)
{
    //대문자를 모두 소문자로 만들기
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    for (char c : s) {
        a[(int)c]++;
    }
    
    if (a[112] == a[121]) ret = 1;
    else ret = 0;
    
    return ret;
}