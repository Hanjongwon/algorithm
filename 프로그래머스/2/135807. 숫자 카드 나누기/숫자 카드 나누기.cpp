#include <bits/stdc++.h>
using namespace std;
int ret_A, ret_B, gcd_A, gcd_B;
bool flag_A = false, flag_B = false;

int gcd(int n, int m) {
    if (m == 0) return n;
    return gcd(m, n % m);
}

vector<int> make_cand(int num) {
    vector<int> v;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            if (i == (num / i)) v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(num / i);
            }
        }
    }
    return v;
}


int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcd_A = arrayA[0];
    int gcd_B = arrayB[0];
    for (int i = 1; i < arrayA.size(); i++) {
        gcd_A = gcd(gcd_A, arrayA[i]);
        gcd_B = gcd(gcd_B, arrayB[i]);
    }
    
    vector<int> cand_a = make_cand(gcd_A);
    vector<int> cand_b = make_cand(gcd_B);
    
    sort(cand_a.begin(), cand_a.end(), greater<int>());
    sort(cand_b.begin(), cand_b.end(), greater<int>());
    cand_a.pop_back();
    cand_b.pop_back();
    
    // 첫번째 조건 확인
    if(!cand_a.empty()) {
        for (int c_a : cand_a) {
            for (int b : arrayB) {
                if (b % c_a == 0) {
                    flag_A = true;
                    break;
                }
            }
            if (flag_A == false) {
                ret_A = c_a;
                break;
            }
        }
    }
    
    // 두번째 조건 확인
    // 첫번째 조건 확인
    if(!cand_b.empty()) {
        for (int c_b : cand_b) {
            for (int a : arrayA) {
                if (a % c_b == 0) {
                    flag_B = true;
                    break;
                }
            }
            if (flag_B == false) {
                ret_B = c_b;
                break;
            }
        }
    }

    return max(ret_A, ret_B);
}