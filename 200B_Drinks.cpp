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

    int n, p, j=0;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        cin >> p;
        j += p;
    }

    cout << ((double)j / n);
    return 0;

}