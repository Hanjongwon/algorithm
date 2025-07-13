#include <bits/stdc++.h>
using namespace std;
string ret;
map<int, pair<int, int>> keys = {
    {1, {0,0}}, {2, {0,1}}, {3, {0,2}},
    {4, {1,0}}, {5, {1,1}}, {6, {1,2}},
    {7, {2,0}}, {8, {2,1}}, {9, {2,2}},
    {'*', {3,0}}, {0, {3,1}}, {'#', {3,2}}
};

string solution(vector<int> numbers, string hand) {
    auto l = keys['*'];
    auto r = keys['#'];
    ret = "";
    
    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            ret += 'L';
            l = keys[num];
        }
        else if (num == 3 || num == 6 || num == 9) {
            ret += 'R';
            r = keys[num];
        }
        else {
            //거리 계산
            int l_dist = abs(l.first - keys[num].first) + abs(l.second - keys[num].second);
            int r_dist = abs(r.first - keys[num].first) + abs(r.second - keys[num].second);
            
            if (l_dist < r_dist) {
                ret += 'L';
                l = keys[num];
            }
            else if (r_dist < l_dist) {
                ret += 'R';
                r = keys[num];
            }
            else {
                if (hand == "right") {
                    ret += 'R';
                    r = keys[num];
                }
                else {
                    ret += 'L';
                    l = keys[num];
                }
            }
        }
    }
    return ret;
}