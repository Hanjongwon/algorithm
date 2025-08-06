#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int ret = 1;

int solution(vector<vector<string>> clothes) {
    for (vector<string> v : clothes) {
        mp[v[1]]++;
    }
    
    for (auto it : mp) {
        ret *= (it.second+1);
    }
    
    
    return ret-1;
}