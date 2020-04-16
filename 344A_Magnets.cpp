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

    ll n, g=1;
    string cur, pre;
    cin >> n;

    cin >> pre;
    for (size_t i = 1; i < n; i++)
    {
        cin >> cur;
        if(pre != cur)
            g++;
        pre = cur;
    }
    cout << g;
    return 0;

}