#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    cin >> name;

    int alphabet[26] = {0};  // A ~ Z 빈도수 저장
    for (char c : name) {
        alphabet[c - 'A']++;
    }

    int odd_cnt = 0;
    char mid_char = 0;
    string left = "";

    // A부터 Z까지 사전 순으로 순회
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] % 2 == 1) {
            odd_cnt++;
            mid_char = 'A' + i;
            if (odd_cnt >= 2) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
        left += string(alphabet[i] / 2, 'A' + i);
    }

    string right = left;
    reverse(right.begin(), right.end());

    if (mid_char)
        cout << left + mid_char + right << '\n';
    else
        cout << left + right << '\n';

    return 0;
}