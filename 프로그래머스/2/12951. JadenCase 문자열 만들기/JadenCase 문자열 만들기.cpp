#include <bits/stdc++.h>
using namespace std;
string ret;
bool check = true;


string solution(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (int i = 0; i < s.size(); i++) {
        if(check) {
            if((int)s[i] >= 97 && (int)s[i] <= 122) {
                s[i] -= 32; //소문자인경우 
            }
            check = false;
        }
        if(s[i] == ' ') check = true;
    }

    return s;
}