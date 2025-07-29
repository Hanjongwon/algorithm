#include <iostream>
using namespace std;

int h, w, n, m, x = 1, y = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w >> n >> m;
    int check1 = 0;
    while (1) {
        check1 += (n + 1);
        if (h - 1 < check1) break;
        x++;
    }

    int check2 = 0;
    while (1) {
        check2 += (m + 1);
        if (w - 1 < check2) break;
        y++;
    }
    cout << x * y;
}