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
 
string space_delimiter = " ", forward_cmd = "forward", down_cmd = "down", up_cmd = "up";

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    string line;
    size_t pos = 0, x=0, y=0;

// part 1
    while(getline(cin, line)){
        pos = line.find(space_delimiter);
        if(pos == string::npos)
            continue;
    
        string command = line.substr(0, pos);
        int step = stoi(line.substr(pos+1));

        if(command == forward_cmd)
            x += step;
        
        if(command == down_cmd)
            y += step;
        
        if(command == up_cmd)
            y -= step;


    }

    cout << x * y;
// part 2

    // int aim = 0;
    // while(getline(cin, line)){
    //     pos = line.find(space_delimiter);
    //     if(pos == string::npos)
    //         continue;
    
    //     string cmd = line.substr(0, pos);
    //     int value = stoi(line.substr(pos+1));

    //     if(cmd == down_cmd)
    //         aim += value;

    //     if(cmd == up_cmd)
    //         aim -= value;
        

    //     if(cmd == forward_cmd){
    //         x += value;
    //         y += aim * value;
    //     }

    // }

    // cout << x * y;
    return 0; 
} 