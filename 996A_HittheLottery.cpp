#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array

int main(){
    ll n, totalBills = 0;
    ar<int, 5> notes = {100, 20, 10, 5, 1};
    cin >> n;
    
    for(int i=0; i< notes.size(); i++){
        if(n >= notes[i]){
            totalBills += n / notes[i];
            n = n % notes[i];
        }
    }
    cout << totalBills;
    return 0;
}