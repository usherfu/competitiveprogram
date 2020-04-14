#include <bits/stdc++.h>
#include <array>
#include <utility>

using namespace std;

#define ll long long
#define ar array

int main(){
    int cases;
    string str;
    vector< pair<string, string> > suf = {  make_pair("po", "FILIPINO"), 
                                            make_pair("desu","JAPANESE"), 
                                            make_pair("masu","JAPANESE"), 
                                            make_pair("mnida", "KOREAN")};
    
    cin >> cases;

    for (size_t i = 0; i < cases; i++)
    {
        cin >> str;

        for (size_t j = 0; j < suf.size(); j++)
        {
            auto const pos = str.rfind(suf[j].first);
            
            if(pos == str.size() - suf[j].first.length()){
                cout << suf[j].second << endl;
                break;
            }
        }
    }
    
    return 0;

}