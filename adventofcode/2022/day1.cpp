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

int part1(); 
int part2(); 
int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

// part 1
    // cout << part1();

// part 2
    cout << part2();
    return 0; 
} 

int part1(){
    
    int max = 0, n = -1, cur = 0;
    string line;

    while(getline(cin, line)){
        //cout << n << endl;
        if(line.empty()){
            if(max < cur){
                max = cur;
            }
            cur = 0;
        }else {
            n = std::stoi( line );
            //cout << n  << endl;
            cur += n;
        }
        //cout << "max: " << max << " cur: " << cur << endl;

    }
    return max > cur ? max : cur;
}

int part2(){
    
    int n = -1, cur = 0;
    vector<int> max(3, 0);

    string line;

    while(getline(cin, line)){
        if(line.empty()){
            if(max[0] < cur){
                max[2] = max[1];
                max[1] = max[0];                
                max[0] = cur;
            }else if(max[1] < cur){
                max[2] = max[1];
                max[1] = cur;
            }else if(max[2] < cur){
                max[2] = cur;
            }
            cur = 0;
        }else {
            n = std::stoi( line );
            //cout << n  << endl;
            cur += n;
        }
        //cout << "max: " << max << " cur: " << cur << endl;

    }
    return max[0] + max[1] + max[2];
}