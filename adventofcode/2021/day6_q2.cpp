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

#define M 256

ll gen8(ll m);
ll gen6(ll m);

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    string line;
    getline(cin, line);
    stringstream ssdata(line);
    vector<int> fish;
    for(int i; ssdata>>i;){
        fish.push_back(i);
        if (ssdata.peek() == ',')
            ssdata.ignore();
    }


    vector<ll> result(7,0);

    for(int i=0; i<result.size(); i++){
        result[i] = gen6(M-i-1) + gen8(M-i-1);
        cout << result[i] << ' ';
    }
    cout << endl;

    ll count = 0;
    for(int i=0; i<fish.size(); i++)
    {
        cout << result[fish[i]] << ' ' ;
        count += result[fish[i]];
    }
    cout << endl;

    cout << count;
   return 0;
}

ll gen8(ll m){
    if( m <= 8 )
        return 1;
    return gen6(m-9) + gen8(m-9);
}

ll gen6(ll m){
    if( m <= 6 ){
        return 1;
    }

    return gen6(m-7) + gen8(m-7);
}