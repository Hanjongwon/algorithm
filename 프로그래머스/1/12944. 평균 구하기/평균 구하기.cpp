#include <bits/stdc++.h>
using namespace std;
double ret;

double solution(vector<int> arr) {
    double tot = accumulate(arr.begin(), arr.end(), 0);
    ret = tot / arr.size();
    
    return ret;
}