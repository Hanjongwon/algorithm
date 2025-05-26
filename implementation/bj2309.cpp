/*
문제 링크 : https://www.acmicpc.net/problem/2309
핵심 아이디어 : 1. 브루트 포스 2. 순열
주의할 점 :
시간 복잡도 :
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> heights(9);
    int height_sum = 0;
    for (int i = 0; i < 9; i++) {
        int h;
        cin >> h;
        height_sum += h;
        heights[i] = h;
    }
    // 1.브루트포스
    // for (int i = 0; i < 9; i++) {
    //     for (int j = i + 1; j < 9; j++) {
    //         if (height_sum - heights[i] - heights[j] == 100) {
    //             heights.erase(heights.begin() + j);
    //             heights.erase(heights.begin() + i);
    //             sort(heights.begin(), heights.end());
    //             for (int h : heights) cout << h << '\n';
    //             return 0;
    //         }
    //     }
    // }

    // 2. 순열
    sort(heights.begin(), heights.end());
    do {
        int sum = 0;
        for (int i = 0; i < 7; i++) sum += heights[i];
        if (sum == 100) break;
    } while (next_permutation(heights.begin(), heights.end()));
    for (int i = 0; i < 7; i++) cout << heights[i] << '\n';
}
