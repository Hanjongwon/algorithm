#include <iostream>
using namespace std;

int n;
string s, front, back;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    size_t pos = s.find('*');
    front      = s.substr(0, pos);
    back       = s.substr(pos + 1);

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (front.size() + back.size() > s.size()) {
            cout << "NE\n";
        } else {
            if (front == s.substr(0, front.size()) && back == s.substr(s.size() - back.size()))
                cout << "DA\n";
            else
                cout << "NE\n";
        }
    }
    return 0;
}