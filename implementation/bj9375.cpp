/*
문제 링크 : https://www.acmicpc.net/problem/9375
문제 이름 : 패션왕 신해빈

핵심 아이디어 :
- 의상의 종류별로 개수를 세고, 각 종류마다 안 입는 경우까지 포함해 (개수 + 1)씩 곱한 뒤
  아무 것도 안 입는 경우(전부 다 안 입는 경우) 1을 빼면 가능한 조합의 수가 됨
  예: 모자 2개, 안경 1개 → (2+1)*(1+1) - 1 = 5가지

자료 구조 :
- map<string, int> mp : 의상 종류(b)를 key로 하고, 해당 종류의 의상 개수(count)를 value로 저장

주의할 점 :
- 정답이 int 범위를 초과할 수 있으므로 long long 타입 사용 필요

시간 복잡도 :
- 테스트 케이스 T개에 대해 각 의상 수 N개의 입력을 받으므로 O(T * N)
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    string a, b;

    cin >> t;

    while (t--) {
        map<string, int> mp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            mp[b]++;
        }
        long long ans = 1;
        for (auto c : mp) {
            ans *= ((long long)c.second + 1);
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}