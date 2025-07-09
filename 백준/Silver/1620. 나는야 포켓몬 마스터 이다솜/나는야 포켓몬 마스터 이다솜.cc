#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    map<int, string> mp2;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s] = i + 1;
        mp2[i+1] = s;
    }

    for (int j = 0; j < m; j++) {
        string s;
        cin >> s;
        if(atoi(s.c_str()) == 0) {
            cout << mp[s] << '\n';
        }
        else {
            cout << mp2[atoi(s.c_str())] << '\n';
        }
    }
    return 0;

}