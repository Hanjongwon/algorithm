#include <bits/stdc++.h>
using namespace std;
vector<int> ret;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    for (int p = 0; p < commands.size(); p++) {
        int i = commands[p][0];
        int j = commands[p][1];
        int k = commands[p][2];
        vector<int> vec(array.begin()+i-1, array.begin()+j);
        sort(vec.begin(), vec.end());
        ret.push_back(vec[k-1]);
        }
    return ret;
}