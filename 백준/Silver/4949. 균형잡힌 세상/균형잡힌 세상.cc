#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        getline(cin, s);
        if (s == ".") break;

        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && !stk.empty() && stk.top() == '(') {
                stk.pop();
            } else if (s[i] == ']' && !stk.empty() && stk.top() == '[') {
                stk.pop();
            } else if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']') {
                stk.push(s[i]);
            }
        }
        
        if (stk.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}