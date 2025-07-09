#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int n, m, j, ret;
vector<int> v;

int main() {
    cin >> n >> m >> j;
    for (int i = 0; i < j; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int left  = 1;
    int right = m;

    for (int app : v) {
        if (app >= left && app <= right)
            continue;  // 범위안에 있는 경우 그냥 넘어감
        else if (app < left) {
            // 왼쪽으로 이동해야 하는 경우
            int diff = left - app;
            ret += diff;
            left -= diff;
            right -= diff;
        } else if (app > right) {
            int diff = app - right;
            ret += diff;
            left += diff;
            right += diff;
        }
    }

    cout << ret;
}
