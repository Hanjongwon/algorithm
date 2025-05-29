#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> ans_arr;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    for (int i = 0; i < n - k + 1; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += arr[j];
        }
        ans_arr.push_back(sum);
    }

    int max_val = 0;
    for (int k : ans_arr) {
        if (k >= max_val) max_val = k;
    }

    cout << max_val;

    return 0;
}