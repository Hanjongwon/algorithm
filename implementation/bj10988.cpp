/*
문제 링크 : https://www.acmicpc.net/problem/10988
핵심 아이디어 : 입력받은 문자열을 뒤집은 문자열과 비교하여 회문 여부 판단
주의할 점 : reverse()는 제자리에서 뒤집기 때문에, 원본 문자열을 복사한 후 뒤집어야 함
시간 복잡도 : O(N) (N은 문자열 길이)
*/

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word, temp;
    cin >> word;
    word = temp;
    reverse(temp.begin(), temp.end());
    if (word == temp)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}