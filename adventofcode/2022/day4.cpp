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
#include <unordered_set>
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
//   cout << part1();

// part 2
    cout << part2();
    return 0; 
} 

int part1(){

    string DEL_COMMA = ",", DEL_HYPEN = "-";
    string line, pair;
    int total = 0;
    int p1_s, p1_e, p2_s, p2_e;
    size_t pos_comma, pos_hypen = 0;

    while(getline(cin, line)){
        if(line.empty())
            continue;
        pos_comma = line.find(DEL_COMMA);

        pair = line.substr(0, pos_comma);
        pos_hypen = pair.find(DEL_HYPEN);
        p1_s = stoi(pair.substr(0, pos_hypen));
        p1_e = stoi(pair.substr(pos_hypen+1));

        pair = line.substr(pos_comma+1);
        pos_hypen = pair.find(DEL_HYPEN);
        p2_s = stoi(pair.substr(0,pos_hypen));
        p2_e = stoi(pair.substr(pos_hypen+1));

        if(p1_s <= p2_s && p1_e >= p2_e || p2_s <= p1_s && p2_e >= p1_e)
            total += 1;
    }
    return total;
}

int part2(){
    
    string DEL_COMMA = ",", DEL_HYPEN = "-";
    string line, pair;
    int total = 0;
    int p1_s, p1_e, p2_s, p2_e;
    size_t pos_comma, pos_hypen = 0;

    while(getline(cin, line)){
        if(line.empty())
            continue;
        pos_comma = line.find(DEL_COMMA);

        pair = line.substr(0, pos_comma);
        pos_hypen = pair.find(DEL_HYPEN);
        p1_s = stoi(pair.substr(0, pos_hypen));
        p1_e = stoi(pair.substr(pos_hypen+1));

        pair = line.substr(pos_comma+1);
        pos_hypen = pair.find(DEL_HYPEN);
        p2_s = stoi(pair.substr(0,pos_hypen));
        p2_e = stoi(pair.substr(pos_hypen+1));

        if(!(p1_e < p2_s || p2_e < p1_s))
            total++;

    }
    return total;
}