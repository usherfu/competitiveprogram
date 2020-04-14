#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define ll long long
#define ar array

const int mxN = 5;

int main(){

    int n;
    for (int i = 0; i < mxN; i++)
    {
        for (int j = 0; j < mxN; j++)
        {
            cin >> n;
            if (n)
            {
                cout << (abs(i-2) + abs(j-2));
                return 0;
            }
            
        }
        
    }
    
    return 0;

}