#include <bits/stdc++.h>
using namespace std;
int ret;
int gcd(int n, int m) {
    if (m == 0) return n;
    return gcd(m, n % m);
}

int lcd(int n, int m) {
    return m * n / gcd(n, m);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        answer = lcd(answer, arr[i]);
    }
    return answer;
}