#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ret;

void moveHanoi(int num, int from, int aux, int to) {
    if (num == 0) return; //기저사례 : 원판이 없으면 종료
    moveHanoi(num-1, from, to, aux); // 가장 큰 원판을 제외한 나머지를 보조기둥으로 옮기기
    ret.push_back({from, to}); // 가장 큰 원판을 목표 기둥으로 옮기기
    moveHanoi(num-1, aux, from, to); // 다른 원판들을 목표 기둥으로 옮기기
}

vector<vector<int>> solution(int n) {
    moveHanoi(n, 1, 2, 3);
    return ret;
    
}