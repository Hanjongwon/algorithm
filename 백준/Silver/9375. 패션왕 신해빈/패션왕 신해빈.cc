#include <iostream>
#include <map>
#include <string>
using namespace std;
int t, n;
string a, b;

int main() {
    cin >> t;
    while (t--) {
        map<string, int> mp;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            mp[b]++;
        }
        long long ret = 1;
        for (auto c : mp) {
            ret *= (long long)(c.second + 1);
        }
        ret--;
        cout << ret << '\n';
    }
    return 0;
}
