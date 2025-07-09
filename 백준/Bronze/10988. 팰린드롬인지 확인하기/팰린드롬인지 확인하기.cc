#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word, ori_word, rev_word;
    cin >> word;

    ori_word = word;
    reverse(word.begin(), word.end());

    if (ori_word == word)
        cout << 1;
    else
        cout << 0;

    return 0;
}