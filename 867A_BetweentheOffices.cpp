#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array

int main(){

    int n, sf=0, fs=0;
    char p, c;
    cin >> n;
    cin >> p;
    for (size_t i = 1; i < n; i++)
    {
        cin >> c;
        if(p != c){
            if(p == 'S')
                sf++;
            else
                fs++;
        }
        p = c;
    }

    cout << (sf>fs ? "YES" : "NO");
    
    return 0;

}