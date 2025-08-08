#include <bits/stdc++.h>
using namespace std;
vector<char> v;
string ret;

bool cmp(int a, int b) {
    string A = to_string(a);
    string B = to_string(b);
    return A+B > B+A;
}


string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), cmp);
    if (numbers[0] == 0) return "0";
    for (int i : numbers) ret+= to_string(i);
    

    return ret;
}