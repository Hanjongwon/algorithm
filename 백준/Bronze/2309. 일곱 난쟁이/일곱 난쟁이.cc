#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int a[9], check;
vector<int> v;

void combi(int start) {
    if (v.size() == 2) {
        int n = v[0] + v[1];
        if (n == check) {
            for (int h : a) {
                if ((h != v[0]) && (h != v[1])) cout << h << '\n';
            }
            exit(0);
        }
    }

    for (int i = start + 1; i < 9; i++) {
        v.push_back(a[i]);
        combi(i);
        v.pop_back();
    }
}
int main() {
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    sort(a, a + 9);
    check = accumulate(a, a + 9, 0) - 100;
    combi(-1);
}