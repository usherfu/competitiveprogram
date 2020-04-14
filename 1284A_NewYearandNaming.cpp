#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array

int main(){

    ll n, m, q, year;
    int indx;

    cin >> n >> m;

    vector<string> strN(n);
    vector<string> strM(m);

    for (size_t i = 0; i < n; i++)
    {
        cin >> strN[i];
    }
    
    for (size_t i = 0; i < m; i++)
    {
        cin >> strM[i];
    }

    cin >>  q;

    for (size_t i = 0; i < q; i++)
    {
        cin >> year;
        year = year % (n*m);
        indx = year % n;
        cout << strN[ indx ? indx -1 : n-1];
        
        indx = year % m;
        cout << strM[ indx ? indx -1 : m-1] << endl;
    }
    
    return 0;

}