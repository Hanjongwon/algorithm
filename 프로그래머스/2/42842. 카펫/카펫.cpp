#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<int> v;

vector<int> solution(int brown, int yellow) {
    int tot = brown + yellow;
    
    for (int i = 1; i <= yellow; i++) {
        if (yellow % i == 0) {
            m = i;
            n = yellow / i;
            if (m*n + 2*n + 2*m + 4 == tot) {
                v.push_back(n+2);
                v.push_back(m+2);
                break;
            }
        }
        
    }
    
    return v;
}