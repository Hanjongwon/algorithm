#include <bits/stdc++.h>
using namespace std;
string ret;

vector<int> split(const string& input, const string& delimiter) {
    vector<int> output;
    auto start = 0;
    auto end = input.find(delimiter);
    
    while (end != string::npos) {
        output.push_back(stoi(input.substr(start, end - start)));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    output.push_back(stoi(input.substr(start)));
    
    return output;
}

string solution(string s) {
    vector<int> v = split(s, " ");
    int min_val = *min_element(v.begin(), v.end());
    int max_val = *max_element(v.begin(), v.end());
    ret += to_string(min_val);
    ret += " ";
    ret += to_string(max_val);
    
    return ret;  
}