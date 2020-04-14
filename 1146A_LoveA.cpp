#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array

int main(){

    int n = 0;
    string s;
    cin >> s;

    for (size_t i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a')
            n++;
    }
    
    if(2*n > s.size())
        cout << s.size();
    else
        cout << (2*n - 1);
        
    return 0;

}