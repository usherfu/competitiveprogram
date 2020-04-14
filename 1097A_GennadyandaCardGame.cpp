#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array
#define CARD_NUM 5

int main(){
    string card, my;

    cin >> card;

    for (size_t i = 0; i < CARD_NUM; i++)
    {
        cin >> my;
        if(card[0] == my[0] || card[1] == my[1]){
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
    return 0;

}