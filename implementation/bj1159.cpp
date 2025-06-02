/*
문제 링크 : https://www.acmicpc.net/problem/1159
핵심 아이디어 : 각 선수의 이름 첫 글자를 알파벳 개수 배열에 카운트하고,
               5명 이상 겹치는 알파벳을 출력한다. 없으면 "PREDAJA" 출력.
주의할 점 : 벡터 범위 초과를 방지하기 위해 인덱스는 0 ~ 25까지만 사용해야 함
시간 복잡도 : O(N) (N은 선수의 수)
*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> cnt(26);
    int n;
    cin >> n;

    while (n--) {
        string name;
        cin >> name;
        cnt[name[0] - 'a']++;
    }

    bool printed = false;
    for (int i = 0; i < cnt.size(); i++) {
        if (cnt[i] >= 5) {
            cout << (char)(i + 'a');
            printed = true;
        }
    }
    if (!printed) cout << "PREDAJA";

    return 0;
}