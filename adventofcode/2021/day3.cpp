#include <iostream> 
#include <sstream> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <cctype> 
#include <string> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <algorithm> 
#include <functional> 
using namespace std;  
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl; 
#define REP(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<=(b);i++) 
#define FORD(i,a,b) for(int i=(a);i>=(b);i--) 
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; } 
 
const int INF = 1<<29; 
typedef long long ll; 
 
inline int two(int n) { return 1 << n; } 
inline int test(int n, int b) { return (n>>b)&1; } 
inline void set_bit(int & n, int b) { n |= two(b); } 
inline void unset_bit(int & n, int b) { n &= ~two(b); } 
inline int last_bit(int n) { return n & (-n); } 
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; } 
 
template<class T> void chmax(T & a, const T & b) { a = max(a, b); } 
template<class T> void chmin(T & a, const T & b) { a = min(a, b); } 
///////////////////////////////////////////////////////////////////// 

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

// part 1
    // char zero = '0';
    // string line;
    // cin >> line;
    // vector<int> allBit(line.length(), 0);
    // int count = 0;

    // do{
    //     for(int i=0; i<line.length(); i++){
    //         allBit[i] += line[i] - zero; // count all bit with 1
    //     }
    //     count++;
    // } while (cin >> line);

    // int gamma = 0, epsilon = 0, curBit = 0, base = 1;
    // for(int i=allBit.size()-1; i>=0; i--){
    //     if(count - allBit[i] < allBit[i])
    //         curBit = 1;
    //     else
    //         curBit = 0;
        
    //     if(curBit == 1){ 
    //          gamma += base;
    //     }else
    //         epsilon += base;

    //     base = base*2;
    // }
    // cout << gamma * epsilon << endl;

    // part 2
    int i;
    char zero = '0', one = '1';
    vector<string> reports;
    string line, oxygen, co2;
    while(cin >> line){
        reports.push_back(line);
    }
    vector<bool> filter(reports.size(), true);

    int left = reports.size();
    int zeroCount, oneCount, curBit = 0;
    char toKeep;
    while(left > 1 && curBit < reports[0].size()){
        zeroCount = 0, oneCount = 0;
        for(i=0; i<filter.size(); i++){
            if(filter[i]){
                if((reports[i][curBit] - zero) == 1){
                    oneCount++;
                }else{
                    zeroCount++;
                }
            }
        }

        if(oneCount >= zeroCount){
            toKeep = one;
        }else
            toKeep = zero;

        for(i=0; i<filter.size(); i++){
            if(filter[i] && reports[i][curBit] != toKeep){
                filter[i] = false;
                left--;
                //cout << "removing " << reports[i] << endl;
            }

        }
        curBit++;
    }

    for(i=0; i<reports.size(); i++){
        if(filter[i])
            oxygen = reports[i];
    }

    // co2
    left = reports.size();
    curBit = 0;
    for(i=0;i<reports.size();i++){
        filter[i] = true;
    }
    while(left > 1 && curBit < reports[0].size()){
        zeroCount = 0, oneCount = 0;
        for(i=0; i<filter.size(); i++){
            if(filter[i]){
                if((reports[i][curBit] - zero) == 1){
                    oneCount++;
                }else{
                    zeroCount++;
                }
            }
        }

        if(zeroCount <= oneCount){
            toKeep = zero;
        }else
            toKeep = one;

        for(i=0; i<filter.size(); i++){
            if(filter[i] && reports[i][curBit] != toKeep){
                filter[i] = false;
                left--;
                cout << "removing " << reports[i] << endl;
            }

        }
        curBit++;
    }

    for(i=0; i<reports.size(); i++){
        if(filter[i])
            co2 = reports[i];
            cout << co2;
    }

    int ox_ = 0, co2_ = 0, base = 1;
    for(int i=oxygen.size()-1; i>=0; i--){
        ox_ += (oxygen[i] - zero) * base;
        co2_ += (co2[i] - zero) * base;
        base = base*2;
    }

    cout << "result " << co2_ * ox_ << endl;
    return 0; 
} 