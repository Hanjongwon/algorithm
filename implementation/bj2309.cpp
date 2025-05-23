/*
문제 링크 : https://www.acmicpc.net/problem/2309
핵심 아이디어 :
주의할 점 :
시간 복잡도 :
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> heights(9);
    for (int i = 0; i < 9; i++) {
        int h;
        cin >> h;
        heights[i] = h;
    }
    return 0;
}