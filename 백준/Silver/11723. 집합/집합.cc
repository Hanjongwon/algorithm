#include <iostream>
#include <string>
using namespace std;

bool s[21]; // 1~20 인덱스 사용
int m, x;
string cmd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    while (m--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            s[x] = true;
        } else if (cmd == "remove") {
            cin >> x;
            s[x] = false;
        } else if (cmd == "check") {
            cin >> x;
            cout << s[x] << '\n';
        } else if (cmd == "toggle") {
            cin >> x;
            s[x] = !s[x];
        } else if (cmd == "all") {
            for (int i = 1; i <= 20; i++) s[i] = true;
        } else if (cmd == "empty") {
            for (int i = 1; i <= 20; i++) s[i] = false;
        }
    }
}