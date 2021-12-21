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
#include <fstream>
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

string vbar_delimiter = "|";

int main() 
{ 
    ios::sync_with_stdio(0); //make io more efficient
    std:ifstream infile("testset_day8.txt");

    string line, s;
    size_t pos;
    int count = 0;

    while(getline(infile, line)){
        pos = line.find(vbar_delimiter);
        if(pos == string::npos)
            continue;
        cout << line;
        string output = line.substr(pos+1);
        cout << output << endl;
        istringstream iss(output);
        while(iss >> s){
            cout << s << " ";
            int n = s.size();
            if(n == 2 || n == 3 || n == 4 || n == 7){
                count ++;
            }
        }
    }
    cout << count << endl;

    return 0;
}

