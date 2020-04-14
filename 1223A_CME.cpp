#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long

int main(){

    ll q, n;

    cin >> q;

    for (size_t i = 0; i < q; i++)
    {
        cin >> n;
        if(n == 2){
            cout << 2 << endl;
        }else
            cout << n%2 << endl;
    }
    

    return 0;

}