/*
문제 링크 : https://www.acmicpc.net/problem/1620
핵심 아이디어 :
- 포켓몬 이름과 번호가 양방향으로 주어지고, 이 중 어떤 정보가 들어와도 반대편 정보를 출력해야 함
- 이름 → 번호, 번호 → 이름을 동시에 빠르게 찾기 위해 map 자료구조 2개 사용
- 숫자인지 이름인지 판별할 때 atoi()를 이용하여 간단히 처리
  - 숫자가 아닌 경우 atoi()는 0을 반환한다는 특성을 활용

주의할 점 :
- 포켓몬 번호는 1부터 시작하며, 이름에 해당하는 문자열이 숫자 "0"인 경우는 존재하지 않음
- 입력이 숫자인지 문자인지 구분하는 방식으로 atoi 사용 시, "0"은 이름으로 간주됨

시간 복잡도 : O(N + M),
- N: 포켓몬 도감 생성 (map 삽입 O(log N))
- M: 질의 처리 (map 탐색 O(log N)) * M번
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    map<int, string> mp2;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]      = i + 1;
        mp2[i + 1] = s;
    }

    for (int j = 0; j < m; j++) {
        string s;
        cin >> s;
        if (atoi(s.c_str()) == 0) {
            cout << mp[s] << '\n';
        } else {
            cout << mp2[atoi(s.c_str())] << '\n';
        }
    }
    return 0;
}