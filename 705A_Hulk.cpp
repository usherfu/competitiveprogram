#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main(){
    ll n;
    bool hate = true;
    cin >> n;

    for(int i=0; i<n-1; i++){
        if(hate){
            cout << "I hate that ";
        }else
        {
            cout << "I love that ";
        }
        hate = !hate;
    }
    if(n % 2){
        cout << "I hate it";
    }else{
        cout << "I love it";
    }
    return 0;
}