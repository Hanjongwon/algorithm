#include <bits/stdc++.h>
using namespace std;
vector<int> ret;

vector<int> solution(vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            ret.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(ret.begin(), ret.end());
    auto it = unique(ret.begin(), ret.end());
    ret.erase(it, ret.end());
    return ret;
}