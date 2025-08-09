#include <bits/stdc++.h>
using namespace std;
unordered_set <int> s;

int solution(vector<int> elements) {
    for (int i = 1; i <= elements.size(); i++) {
        for (int j = 0; j < elements.size(); j++) {
            int sum = 0;
            for (int k = 0; k < i; k++) {
                int idx = j + k;
                if (idx >= elements.size()) idx -= elements.size();
                sum += elements[idx];
            }
            s.insert(sum);
        }
    }
    return s.size();
}