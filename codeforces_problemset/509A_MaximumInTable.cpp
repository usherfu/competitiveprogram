#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){

    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    int n;
    cin >> n;

    vector< vector<int> > a(n, vector<int>(n, 0));
    for (size_t i = 0; i < n; i++)
    {
        a[i][0] = a[0][i] = 1;
    }

    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    cout << a[n-1][n-1];
    
    
    return 0;

}