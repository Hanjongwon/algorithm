#include <algorithm>
#include <iostream>
using namespace std;
int h, w;
char arr[104][104];
int ret[104][104];

void move(int y, int x) {
    int cnt = 1;
    for (int j = x + 1; j < w; j++) {
        if (arr[y][j] == 'c') break;  // 또 다른 구름이 있으면 멈춤
        if (ret[y][j] == -1) ret[y][j] = cnt;
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&ret[0][0], &ret[0][0] + 104 * 104, -1);

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            arr[i][j] = c;
            if (c == 'c') ret[i][j] = 0;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (ret[i][j] == 0) {
                move(i, j);
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }
}