#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    while (n > 0) {
        int r = n % 3;
        n /= 3;
        
        if (r == 0) {
            r = 4;
            n -= 1; // 나머지가 0이면 자리 하나 빌려옴
        }
        
        answer = to_string(r) + answer;
    }
    return answer;
}