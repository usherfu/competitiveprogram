#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {

    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    ll x, rest, step;
    cin >> x;
    rest = x % 5;
    step = (x-rest)/5;

    if(rest){
        step ++;
    }
    cout << step;
    return 0;

}