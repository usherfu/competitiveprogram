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

    ll n, a=0, d=0;
    char c;
    cin >> n;

    for (size_t i = 0; i < n; i++){
        cin >> c;
        if(c == 'A') a++;
        if(c == 'D') d++;        
    }

    if(a == d){
        cout << "Friendship";
        return 0;
    }
    
    cout << (a > d ? "Anton" : "Danik");
    return 0;

}