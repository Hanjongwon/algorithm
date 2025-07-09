#include <bits/stdc++.h>
using namespace std;

set<int> s;

int solution(vector<int> nums)
{
    s.insert(nums.begin(), nums.end());
    return min(nums.size() / 2, s.size());
}