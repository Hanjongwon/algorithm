/*
문제 링크 : https://www.acmicpc.net/problem/9996
핵심 아이디어 : 패턴 문자열은 '*' 하나를 포함하고 있으며, '*'는 어떤 문자열이든 대체 가능하다.
               '*' 기준으로 앞부분과 뒷부분을 나눈 뒤, 입력 문자열의 앞과 뒤가 각각 패턴의 앞/뒤와
일치하는지 확인한다. 전체 입력 문자열의 길이가 앞/뒤 패턴의 길이 합보다 작다면 매칭 불가. 주의할 점
: 뒷부분 비교 시 문자열 길이를 넘지 않도록 offset 계산을 정확히 해야 함. 시간 복잡도 : O(N * M) (N은
문자열 개수, M은 각 문자열의 길이)
*/

#include <iostream>
#include <string>
using namespace std;

int check_pattern(string pattern, string input) {
    auto star_point     = pattern.find('*');
    string pattern_forw = pattern.substr(0, star_point);
    string pattern_back = pattern.substr(star_point + 1);

    // input이 패턴보다 짧을 경우 false
    if (input.size() < pattern_forw.size() + pattern_back.size()) return 0;

    for (int i = 0; i < pattern_forw.size(); i++) {
        if (pattern_forw[i] != input[i]) return 0;  //*앞부분이 같은지 확인
    }

    for (int j = 0; j < pattern_back.size(); j++) {
        if (pattern_back[pattern_back.size() - (1 + j)] != input[input.size() - (1 + j)])
            return 0;  //*뒷부분이 같은지 확인
    }
    return 1;  // 둘다 같으면 1 출력
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string pattern;
    cin >> pattern;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        if (check_pattern(pattern, input))
            cout << "DA\n";
        else
            cout << "NE\n";
    }

    return 0;
}