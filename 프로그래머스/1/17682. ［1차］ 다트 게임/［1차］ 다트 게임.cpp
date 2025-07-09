#include <bits/stdc++.h>
using namespace std;
int ret, cnt;
vector<int> v;

int solution(string dartResult) {
    for (int i = 0; i < dartResult.size(); i++) {
        if (isdigit(dartResult[i])){
            if(isdigit(dartResult[i+1])) {
                v.push_back(10);
                i++;
                cnt++;
            }
            else {
                v.push_back((int)dartResult[i] - '0');
                cnt++;
            }
        }
        else if (dartResult[i] == 'S') {
            continue;
        }
        else if (dartResult[i] == 'D') {
            v[cnt-1] = pow(v[cnt-1], 2);
        }
        else if (dartResult[i] == 'T') {
            v[cnt-1] = pow(v[cnt-1], 3);
        }
        else if (dartResult[i] == '#') {
            v[cnt-1] = -v[cnt-1];
        }
        else if (dartResult[i] == '*') {
            if (cnt == 1) v[cnt-1] *= 2;
            else {
                v[cnt-2] *= 2;
                v[cnt-1] *= 2;
            }
        }
    }
    
    ret = accumulate(v.begin(), v.end(), 0);
    return ret;
}