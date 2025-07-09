#include <bits/stdc++.h>
using namespace std;

string ret;
int arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};
string days[] = {"FRI", "SAT","SUN", "MON", "TUE", "WED", "THU"};
int n;

string solution(int a, int b) {
    for (int i = 0; i < a-1; i++) {
        n += arr[i];
    }
    n += (b-1);
    int cnt = n % 7;
    ret = days[cnt];
    return ret;
}