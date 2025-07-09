#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& input, string delimiter) {
    vector<string> v;
    int start = 0;
    int end = input.find(delimiter);
    
    while (end != string::npos) {
        v.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    v.push_back(input.substr(start));
    return v;
}

string solution(string s) {
    string ret = "";
    vector<string> v = split(s, " ");

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (j % 2 == 0)
                ret += toupper(v[i][j]);
            else
                ret += tolower(v[i][j]);
        }
        if (i != v.size() - 1) ret += " ";
    }
    return ret;
}