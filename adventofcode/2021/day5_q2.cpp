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

#define M 1000

vector< vector<int> > diag(M, vector<int> (M, 0) );


int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    string line; 
    int x1, y1, x2, y2;
    vector<int> array;
    while(getline(cin, line)){
        stringstream ss(line);
        array.clear();
        for(int i; ss >> i;){
            array.push_back(i);
            char c = ss.peek();
            while(c == ',' || c == ' ' || c == '-' || c == '>' ){
                ss.ignore();
                c = ss.peek();
            }
        }
        x1 = array[0], y1 = array[1], x2 = array[2], y2 = array[3];

        if(x1 == x2){
            for(int i = min(y1, y2); i <= max(y1, y2); i++){
                diag[x1][i] ++;
            }
        }else if(y1 == y2){
            for(int i = min(x1, x2); i <= max(x1, x2); i++){
                diag[i][y1] ++;
            }
        }else {
            int grad = (x1 - x2) / (y1 - y2);
            if(grad == 1){
                int minx = min(x1, x2), miny = min(y1, y2);
                for(int i=0; i<=abs(x1-x2); i++){
                    diag[minx+i][miny+i] ++;
                }
            }else if(grad == -1){
                int minx = min(x1, x2), maxy = max(y1, y2);
                for(int i=0; i<=abs(x1-x2); i++){
                    diag[minx+i][maxy-i] ++;
                }
            }
        }

    }

    int count = 0;
    for(int i=0; i < diag.size(); i++){
        for(int j=0; j < diag[i].size(); j++){
            if(diag[i][j] > 1){
                count ++;
            }
        }
    }

    cout << count;
    return 0;
}