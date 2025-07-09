#include <bits/stdc++.h>
using namespace std;
int min_val = 987654321;

vector<int> solution(vector<int> arr) {
    for (int i : arr) {
        if (i < min_val) min_val = i;
    }
    cout << min_val;
    auto it = find(arr.begin(), arr.end(), min_val);
    arr.erase(it);
    
    if (arr.size() == 0) arr.push_back(-1);
    
    return arr;
}