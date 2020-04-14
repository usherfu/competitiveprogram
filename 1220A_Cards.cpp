#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array

int main(){

    int n, nZ=0, nN=0;
    char c;

    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> c;
        if(c == 'z')
            nZ++ ;
        else if(c == 'n')
            nN++ ;
    }

    while(nN--)
        cout << 1 << ' ';
    
    while(nZ--)
        cout << 0 << ' ';
    
    return 0;

}