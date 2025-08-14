#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string ans;
    
    for (char c : number) {
        while(!ans.empty() && k > 0 && ans.back() < c) {
            ans.pop_back();
            k--;
        }
        ans.push_back(c);
    }
    
    // 아직 k가 남았으면 뒤에서 제거
    if (k > 0) ans.erase(ans.end() - k, ans.end());
    return ans;
}
