#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    getline(cin, input);

    for (int i = 0; i < input.size(); i++) {
        if ('A' <= input[i] && input[i] <= 'Z') {
            input[i] = (input[i] - 'A' + 13) % 26 + 'A';
        } else if ('a' <= input[i] && input[i] <= 'z') {
            input[i] = (input[i] - 'a' + 13) % 26 + 'a';
        }
    }
    cout << input;
    return 0;
}