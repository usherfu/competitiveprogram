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
#include <filesystem>
#include <fstream>
#include <string>

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

int solution1();
int solution2();
int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    //cout << solution1();
    cout << solution2();
    return 0; 
} 

int solution1(){

    std::ifstream input("day6.txt");
    std::stringstream sstr;

    while(input >> sstr.rdbuf());
    string line = sstr.str();
    //cout << line << endl;

    int start = 0;
    if(line[0] == line[1] || line[0] == line [2])
        start = 4;
    else if(line[1] == line[2])
        start = 5;
    else start = 3;

    for(int i=start; i<line.size(); ){
        cout << i;
        cout << ": " << line[i-3] << line[i-2] << line[i-1] << line[i] << endl;
        char cur = line[i];
        if(cur == line[i-1]){
            i += 3;
        }else if(cur == line[i-2]){
            i += 2;
        }else if(cur == line[i-3]){
            i += 1;
        }else {
            if(line[i-1] != line[i-2] && line[i-1] != line[i-3] && line[i-2] != line[i-3])
                return i+1;
            else
                i+=1;
        }
    }
    return -1;
}

// n: number of unique elements to check
// last: starting from last, to check n elements of uniqueness
// N: total number of unique elements of the question, i.e. # of elements move forward if duplicate element is found.
int advance(const string &line, int n, int last, int N){

    if(n == 1)
        return last + N - 1; // all unique

    for(int i=last-1; i > last-n;){
        if(line[last] == line[i]){
            return i+N;
        }
        i--;
    }
    
    return advance(line, n-1, last-1, N);
}
int solution2(){

    int N = 14;
    std::ifstream input("day6.txt");
    std::stringstream sstr;

    while(input >> sstr.rdbuf());
    string line = sstr.str();

    //int start = advance(line, 14, 13, 14);
    int start = advance(line, N, N-1, N);
    if(start == N-1)
        return N;
    for(int i=start; i<line.size();){
        int next = advance(line, N, i, N);
        if(next == i)
            return next+1;
        i = next;
    }
    return -1;
}