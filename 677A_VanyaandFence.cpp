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

    ll n, f, h, w=0;
    cin >> n >> f;

    for (size_t i = 0; i < n; i++)
    {
        cin >> h;
        w += (h <= f) ? 1:2;
    }
    cout << w;
    return 0;

}