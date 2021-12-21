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
#include <unordered_map>
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
// http://courses.csail.mit.edu/6.006/spring11/lectures/lec02.pdf
void solve2_bruteforce(vector< vector<int> >& v);

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    vector< vector<int> > heightmap;
    string line;
    bool first = true;
    //read data, and extend the bound by 1 on each side, e.g. M*N --> (M+2)*(N+2)
    while(getline(cin, line)){
        vector<int> cur;
        cur.push_back(9);
        for(int i=0; i<line.size(); i++){
            cur.push_back(int(line[i] - '0'));
        }
        cur.push_back(9);
        if(first){
            vector<int> v(cur.size(), 9);
            heightmap.push_back(v);
            first = false;
        }
        heightmap.push_back(cur);
    }
    vector<int> v (heightmap[0].size(), 9);
    heightmap.push_back(v );


    for(int i=0; i<heightmap.size(); i++){
        for(int j=0; j<heightmap[i].size(); j++){
            cout << heightmap[i][j] << ' ';
        }
        cout << endl;
    }

    solve2_bruteforce(heightmap);
    return 0; 
} 

ll findBasin(vector< vector<int> > & v , int m, int n){
    set< pair<int, int> > basin;
    vector< pair<int, int> > tocheck;
    tocheck.push_back( make_pair(m, n));
    //basin.insert( make_pair(m, n) );
    while(tocheck.size() != 0){
        int i = tocheck[0].first, j = tocheck[0].second;
        tocheck.erase(tocheck.begin());
        basin.insert(make_pair(i, j)); // if already exists, simply return iterator of the exsiting one

        if( v[i-1][j] != 9 && basin.find(make_pair(i-1, j)) == basin.end() ) {
            tocheck.push_back( make_pair(i-1, j) );
        }
        if( v[i+1][j] != 9 && basin.find(make_pair(i+1, j)) == basin.end() ) {
            tocheck.push_back( make_pair(i+1, j) );
        }
        if( v[i][j-1] != 9 && basin.find(make_pair(i, j-1)) == basin.end() ) {
            tocheck.push_back( make_pair(i, j-1) );
        }            
        if( v[i][j+1] != 9 && basin.find(make_pair(i, j+1)) == basin.end() ) {
            tocheck.push_back( make_pair(i, j+1) );
        }   

    }
    // for(set< pair<int, int> >::iterator it=basin.begin(); it != basin.end(); it++){
    //     cout << (*it).first << ' ' << (*it).second << endl;
    // }
    return basin.size();
}
void solve2_bruteforce(vector< vector<int> >& v){
    int M = v.size(), N = v[0].size();
    vector<ll> basin;
    for(int i=1; i<M-1; i++){
        for(int j=1; j<N-1; j++){
            if(v[i][j] < v[i-1][j] && v[i][j] < v[i+1][j] && v[i][j] < v[i][j-1] && v[i][j] < v[i][j+1]){
                ll bsize = findBasin(v, i, j);
                basin.push_back(bsize);
                cout << "(i,j): " << i << ',' << j << "-- " << v[i][j] << " basin= " << bsize << endl;
            }
        }
    }

    // sort basin
    // for(int i=0; i< basin.size(); i++)
    //     cout << basin[i] << endl;    
    for(int i=0; i < basin.size()-1; i++){
        for(int j=i+1; j < basin.size(); j++){
            if(basin[i] < basin[j]){
                ll l = basin[i];
                basin[i] = basin[j];
                basin[j] = l;
            }
        }
    }

    // for(int i=0; i< basin.size(); i++)
    //     cout << basin[i] << endl;
    cout << basin[0] << ' ' << basin[1] << ' ' << basin[2] << endl;
    cout << basin[0] * basin[1] * basin[2];
}