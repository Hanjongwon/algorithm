#include <bits/stdc++.h>
using namespace std;
vector<string> v, vv;
string s;
int m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        v.push_back(s);
    }

    for (string s : v) {
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                int init_idx = i;
                do {
                    i++;
                } while (i < s.size() && isdigit(s[i]));
                int fin_idx = i;
                string num = s.substr(init_idx, fin_idx - init_idx);
                while (num.size() > 1 && num[0] == '0') num.erase(num.begin());
                vv.push_back(num);
            }
        }
    }
    sort(vv.begin(), vv.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for (const string& num : vv) cout << num << '\n';
}