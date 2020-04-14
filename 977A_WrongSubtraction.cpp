#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0; i<k; i++){
        if (n % 10)
        {
            n--;
        }else
        {
            n /=  10;
        }           
    }
    cout << n;
    return 0;
}