#include <bits/stdc++.h>
#include <array>
using namespace std;

#define ll long long
#define ar array

int main(){

    ar<int, 4> input = {0, 0, 0, 0};
    int max_index = -1;
    for (size_t i = 0; i < input.size(); i++){
        cin >> input[i];

        if(max_index == -1){
            max_index = i;
        }else if (input[i] > input[max_index])
        {
            max_index = i;
        }
    }

    for (size_t i = 0; i < input.size(); i++)
    {
        if(i != max_index)
            cout << input[max_index] - input[i] << ' ';
    }
    
    return 0;

}