#include <bits/stdc++.h>
using namespace std;
long long ret;

long long solution(long long n) {
    if (sqrt(n) == (long long)sqrt(n))
        return (pow((long long)sqrt(n)+1,2));
    return -1;
}