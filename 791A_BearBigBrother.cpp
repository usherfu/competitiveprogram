#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main(){
    ll a, b, year = 0;

    cin >> a >> b;
    
    while (a <= b){
        year++;
        a *= 3;
        b *= 2;
    }
    cout << year;
    return 0;
}