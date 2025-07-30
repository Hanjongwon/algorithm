#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<int> v;
string s;

void solve1(string cp, int num) {
    auto it = find(v.begin(), v.end(), num);

    if (cp == "add") {
        if (it != v.end()) return;  // v에 num이 있다면
        v.push_back(num);
    }
    if (cp == "remove") {
        if (it == v.end()) return;  // v에 num이 없다면
        v.erase(it);
    }
    if (cp == "check") {
        if (it != v.end()) {
            cout << 1 << '\n';
            return;
        } else {
            cout << 0 << '\n';
            return;
        }
    }
    if (cp == "toggle") {
        if (it == v.end()) {
            v.push_back(num);
        } else {
            v.erase(it);
        }
    }
}

void solve2(string& cp) {
    if (cp == "all") {
        v.clear();
        for (int i = 1; i <= 20; i++) v.push_back(i);
    }
    if (cp == "empty") {
        v.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s != "all" && s != "empty") {
            cin >> n;
            solve1(s, n);
        } else
            solve2(s);
    }
}