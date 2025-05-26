/*
문제 링크 : https://www.acmicpc.net/problem/10808
핵심 아이디어 : 1. 알파벳 a~z를 인덱스로 매핑해 등장 횟수를 카운트
주의할 점 : 아스키코드에서 'a'를 빼서 인덱스 계싼
시간 복잡도 : O(N) (N은 문자열의 길이)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;

    vector<int> ans(26, 0);
    for (char alpha : word) {
        int cnt = (int)alpha - 'a';
        ans[cnt]++;
    }

    for (int num : ans) cout << num << ' ';
    return 0;
}