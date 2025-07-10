#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const * argv[]){
    int n, m, value;
    int max_value = 0;

    vector <int> card_list; // vector 초기화

    cin >> n >> m; //카드 개수, 최대 값 입력

    for(int i = 0; i < n; i++){
        int card;
        cin >> card;
        card_list.push_back(card);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                value = card_list[i] + card_list[j] + card_list[k];
                
                if (value >= max_value && value <= m) max_value = value;
            }
        }
    }
    cout << max_value;
    return 0;
}
