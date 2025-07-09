#include <bits/stdc++.h>
using namespace std;
string ret;
unordered_map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    for (string name : participant) m[name]++;
    for (string name : completion) m[name]--;
    for (auto p : m) {
        if (p.second > 0) return p.first;
    }
    return "";
}