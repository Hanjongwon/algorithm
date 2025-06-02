/*
문제 링크 : https://www.acmicpc.net/problem/2979
핵심 아이디어 : 시간의 흐름에 따라 각 시점마다 주차된 차량 수를 계산하고, 차량 수에 따라 요금을 누적
주의할 점 : 출차 시간은 요금 계산에 포함되지 않도록 범위를 [도착 시간, 출차 시간)으로 설정해야 함
시간 복잡도 : O(T) (T는 전체 시간 범위, 최악의 경우 100까지)
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int arr_1, dep_1, arr_2, dep_2, arr_3, dep_3;
    cin >> arr_1 >> dep_1 >> arr_2 >> dep_2 >> arr_3 >> dep_3;
    int cnt = 0;  // 주차장에 있는 차의 개수
    int fee = 0;

    vector<int> time = {arr_1, dep_1, arr_2, dep_2, arr_3, dep_3};
    sort(time.begin(), time.end());

    for (int i = time[0]; i < time[5]; i++) {
        cnt = 0;
        if (i >= arr_1 && i < dep_1) cnt++;
        if (i >= arr_2 && i < dep_2) cnt++;
        if (i >= arr_3 && i < dep_3) cnt++;

        if (cnt == 1)
            fee += a;
        else if (cnt == 2)
            fee += (b * 2);
        else if (cnt == 3)
            fee += (c * 3);
    }
    cout << fee;
    return 0;
}