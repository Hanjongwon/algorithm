#include <bits/stdc++.h>
using namespace std;
vector<int> ret;
int trans_cnt, zero_cnt;

string go(int num) {
    vector<int> v;
    string result;
    
    while(num != 1) {
        int a = num % 2;
        v.push_back(a);
        num /= 2;
    }
    v.push_back(1);
    reverse(v.begin(), v.end());
    for (int i : v) result += to_string(i);
    return result;
}

vector<int> solution(string s) {
    while(s != "1") {
        sort(s.rbegin(), s.rend());
        auto pos = s.find('0');
        if (pos != string::npos) {
            zero_cnt += (s.size()- pos);
            cout << zero_cnt << '\n';
            s.erase(pos);
        }
        int n = s.size();
        s = go(n);
        trans_cnt++;
    }
    ret.push_back(trans_cnt);
    ret.push_back(zero_cnt);
    return ret;
}