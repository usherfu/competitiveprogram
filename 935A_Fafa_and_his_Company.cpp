#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array

int main(){
    ll n, count = 0;

    cin >> n;

    for (size_t i = 1; i <= n/2; i++) // n=10
    {
        if(n % i == 0){ // 
            count ++;
        }
    }
    cout << count;
    return 0;

}