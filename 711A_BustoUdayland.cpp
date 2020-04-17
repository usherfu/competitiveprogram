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
    bool found = false;
    vector<string> seat(n);

    for (size_t i = 0; i < n; i++){
        cin >> seat[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        if(seat[i][0] == 'O' && seat[i][1] == 'O'){
            seat[i][0] = seat[i][1] = '+';
            found = true;
            break;
        }
        if(seat[i][3] == 'O' && seat[i][4] == 'O'){
            seat[i][3] = seat[i][4] = '+';
            found = true;            
            break;
        }        
    }
    
    if(found){
        cout << "YES" << endl;
        for (size_t i = 0; i < n; i++)
        {
            cout << seat[i] <<endl;
        }
        
    }else
    {
        cout << "No\n";
    }
    
    return 0;

}