#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        vector<int> sides(3);
        cin >> sides[0] >> sides[1] >> sides[2];

        // 종료 조건
        if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0) break;

        // 정렬
        sort(sides.begin(), sides.end());

        // 삼각형 조건 판별
        if (sides[2] >= sides[0] + sides[1]) {
            cout << "Invalid\n";
        }
        else if (sides[0] == sides[2]) {
            cout << "Equilateral\n";
        }
        else if (sides[0] == sides[1] || sides[1] == sides[2]) {
            cout << "Isosceles\n";
        }
        else {
            cout << "Scalene\n";
        }
    }

    return 0;
}