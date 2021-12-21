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

# define N 12
# define N_A 100
# define MAX_STEP 100

void flash(int m, int n, vector< vector <int> > &o, set< pair<int, int> > &flashed);

int main() 
{ 
    vector< vector <int> > o;

    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);


    string line;
    vector<int> padding(N, N_A);
    o.push_back(padding);
    while(getline(cin, line)){
        vector<int> v;
        v.push_back(N_A);
        for(int i=0; i<line.size(); i++){
            v.push_back(int(line[i] - '0'));
        }
        v.push_back(N_A);
        o.push_back(v);
    }
    o.push_back(padding);

    // for(int i=0; i<o.size(); i++){
    //     for(int j=0; j<o[i].size(); j++){
    //         cout << o[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int count = 0;
    vector<int> adjX {1, 0, 1, -1, 1, -1,  0, 1};
    vector<int> adjY {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> vect{ 10, 20, 30 };
 
    for(int step=1; step<=MAX_STEP; step++){
        
        //vector< vector <bool> > flashed(N, vector<bool> (N, false) );
        set< pair<int, int> > flashed;
        vector< pair<int, int> > toflash;
        //increase engergy by 1 
        for(int i=1; i<o.size()-1; i++){
            for(int j=1; j<o[i].size()-1; j++){
                o[i][j]++;
                if(o[i][j] > 9)
                    toflash.push_back( make_pair(i, j));        
            }
        }
//use recursive to rewrite the code?


        while(toflash.size() != 0){
            int m = toflash[0].first, n = toflash[0].second;
            toflash.erase(toflash.begin());
            flashed.insert(make_pair(m, n));

            for(int a=0; a<adjX.size(); a++){
                int i = m + adjX[a], j = n + adjY[a]; 
                if( 0 < i && i < (N-1) && 0 < j && j < (N-1)){
                    o[i][j] ++;

                    if(flashed.find(make_pair(i,j)) != flashed.end()) // already flashed
                        continue;

                    if(o[i][j] > 9)
                        toflash.push_back(make_pair(i,j));
                }
            }
        }

        // set flashed energy to 0
        for(set< pair<int, int> >::iterator it = flashed.begin(); it != flashed.end(); it++){
            int i = (*it).first, j=  (*it).second;
            o[i][j] = 0;
            count ++;
        }

        if(step < 10 || step % 10 == 0){
            cout << "After step " << step << endl;
            for(int i=0; i<o.size(); i++){
                for(int j=0; j<o[i].size(); j++){
                    cout << o[i][j] << ' ';
                }
                cout << endl;
            }            
        }

    }
    cout << "total flashed: " << count << endl;
    return 0; 
} 
