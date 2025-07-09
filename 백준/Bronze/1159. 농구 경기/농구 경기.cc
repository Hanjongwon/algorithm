#include <iostream>
using namespace std;

int a[32], n;
bool check = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        char c = s[0];
        int k  = c - 'a';
        a[k]++;
    }

    for (int i = 0; i < 32; i++) {
        if (a[i] >= 5) {
            cout << (char)(i + 97);
            check = true;
        }
    }
    if (!check) cout << "PREDAJA";
}