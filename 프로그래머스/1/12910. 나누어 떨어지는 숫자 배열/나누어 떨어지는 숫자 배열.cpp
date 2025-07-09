#include <bits/stdc++.h>
using namespace std;
vector <int> v;

vector<int> solution(vector<int> arr, int divisor) {
    for (int n : arr) {
        int b = n % divisor;
        if (b == 0) v.push_back(n);
    }
    if (v.size() == 0) v.push_back(-1);
    sort(v.begin(), v.end());
    return v;
}