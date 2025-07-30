#include <iostream>
#include <string>
using namespace std;

int m, x;
int s = 0; // 집합을 비트로 표현
string cmd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    while (m--) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            s |= (1 << x);
        }
        else if (cmd == "remove") {
            cin >> x;
            s &= ~(1 << x);
        }
        else if (cmd == "check") {
            cin >> x;
            cout << ((s & (1 << x)) ? 1 : 0) << '\n';
        }
        else if (cmd == "toggle") {
            cin >> x;
            s ^= (1 << x);
        }
        else if (cmd == "all") {
            s = (1 << 21) - 1; // 1~20까지 비트 on
        }
        else if (cmd == "empty") {
            s = 0;
        }
    }
}