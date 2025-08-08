#include <bits/stdc++.h>
using namespace std;
int ret;
set<int> num_set;

bool is_prime(int num) {
    if (num == 0 || num == 1) return false;
    if (num == 2 || num == 3) return true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
void get_numbers(string numbers) {
    sort(numbers.begin(), numbers.end());
    
    do {
        for(int len = 1; len <= numbers.size(); len++) {
            string sub = numbers.substr(0, len);
            int num = stoi(sub);
            num_set.insert(num);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
}
int solution(string numbers) {
    get_numbers(numbers);
    for (int i : num_set) {
        if (is_prime(i)) ret++;
    }
    return ret;
}