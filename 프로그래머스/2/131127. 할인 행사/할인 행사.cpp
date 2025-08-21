#include <bits/stdc++.h>
using namespace std;
int ret;
int l = 0;
unordered_map<string, int> mp;
unordered_map<string, int> mp2;
bool check = true;


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    for(int i = 0; i < want.size(); i++) {
        mp[want[i]] = number[i];
        mp2[want[i]] = 0;
    }
    
    for(int i = 0; i < 10; i++) {
        if(mp2.count(discount[i]) == 1) { // want에 있는 물품인경우
            mp2[discount[i]]++;
        }
    }
    
    for (int i = 0; i < want.size(); i++) {
        if (mp[want[i]] != mp2[want[i]]) {
            check = false;
            break;
        }
    }
    
    if (check == true) ret++;

    for (int r = 10; r < discount.size(); r++) {
        check = true;
        if (mp2.count(discount[l]) == 1) {
            mp2[discount[l]]--;
        }
        
        if (mp2.count(discount[r]) == 1) {
            mp2[discount[r]]++;
        }
        
        for (int i = 0; i < want.size(); i++) {
            if (mp[want[i]] != mp2[want[i]]) {
                check = false;
                break;
            }
    	}	
    	if (check == true) ret++;
        
        l++;
    }
    return ret;
}