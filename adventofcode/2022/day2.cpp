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
//    cout << part1();

// part 2
    cout << part2();
    return 0; 
} 


int part1(){

/*
A, X Rock 0, 0

B, Y Paper 1, 1

C, Z Scissors 2, 2

self - oppo = 0 --> 3points (self = X, Y or Z)

self - oppo = 1 --> 6points (self = Y or Z)

self - oppo = -2 --> 6 points (self = X)

self - oppo = -1 --> 0 point (self = X or Y)

self - oppo = 2 --> 0 points (self = Z)
*/
    string line;
    int total = 0;
    int oppo, self;
    while(getline(cin, line)){
        if(line.empty())
            continue;

        oppo = line[0] - 'A';
        self = line[2] - 'X';
        total += self +1 ;
        
        int diff = self - oppo;
        if(diff == 0)
            total += 3;
        else if(diff == 1 || diff == -2)
            total += 6;
    }
    return total;
}

int part2(){
    
    string line;
    int total = 0;
    int oppo, self, res;

    while(getline(cin, line)){
        if(line.empty())
            continue;

        oppo = line[0] - 'A'; // oppo --> 0: rock, 1:paper, 2: scissors
        res = line[2] - 'Y';  //res -->  -1: lose, 0: draw, +1: win
        total += (res+1) * 3; 

        self = oppo + res;
        if(self < 0)
            self = 2;        
        if(self > 2)
            self = 0;

        total += self + 1;
    }
    return total;
}