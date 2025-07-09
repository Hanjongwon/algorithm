#include <bits/stdc++.h>
using namespace std;
int ret;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    
    for(int cost : d) {
        if (budget >= cost) {
            budget -= cost;
            ret++;
        }
        else 
            break;
    } 
    return ret;
}