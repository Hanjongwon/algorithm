#include <iostream>
using namespace std;

int a, b, c, ret;
int arr[104];

int main() {
    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++) {
        int n, m;
        cin >> n >> m;
        for (int k = n; k < m; k++) {
            arr[k]++;
        }
    }

    for (int i : arr) {
        if (i == 1)
            ret += a;
        else if (i == 2)
            ret += (2 * b);
        else if (i == 3)
            ret += (3 * c);
    }
    cout << ret;
}