#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n = arr1.size();
    int m = arr1[0].size();
    vector<vector<int>> v(n,vector<int>(m));
    for (int i = 0; i < arr1.size();i++) {
        for (int j = 0; j < arr1[0].size(); j++) {
            v[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return v;
}