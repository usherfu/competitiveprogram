#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main(){
    ll n, sum = 0;
    string poly;

    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> poly;
        if(poly == "Tetrahedron"){
            sum += 4;
        }else if(poly == "Cube"){
            sum += 6;
        }else if(poly == "Octahedron"){
            sum += 8;
        }else if(poly == "Dodecahedron"){
            sum += 12;
        }else if(poly == "Icosahedron"){
            sum += 20;
        }
        
    }
    cout << sum;
    return 0;
}