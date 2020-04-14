#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main(){
    ll n, ith;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ith;
        if(ith != 0){
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";
    return 0;
}