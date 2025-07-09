#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;

    vector<int> ans(26, 0);
    for (char alpha : word) {
        int cnt = (int)alpha - 'a';
        ans[cnt]++;
    }

    for (int num : ans) cout << num << ' ';
    return 0;
}