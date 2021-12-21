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
int check(string line, char &ret);

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    string line;
    int score = 0;
    char ret;
    while(getline(cin, line)){
        int result = check(line, ret);
        if(result == 2){
            switch (ret)
            {
            case ')':
                score += 3;
                break;
            case ']':
                score += 57;
                break;
            case '}':
                score += 1197;
                break;
            case '>':
                score += 25137;
                break;                                
            default:
                break;
            }
        }
    }
    cout << score;
    return 0; 
} 

// return:
//       0: syntax correct and complete
//       1: syntax correct and incomplete. Parameter ret contains the next expected character
//       2: syntax corrupted, and parameter ret contains the first illegal character
int check(string line, char &ret){
    unordered_map<char, char> legalpair;
    legalpair['('] = ')';
    legalpair['['] = ']';
    legalpair['{'] = '}';
    legalpair['<'] = '>';

    set<char> leftbracket;
    leftbracket.insert('('); 
    leftbracket.insert('[');
    leftbracket.insert('{');
    leftbracket.insert('<');

    stack<char> s;
    //s.push(line[0]);
    int i = 0;
    while(i < line.size()) {

        if( s.size() == 0){
            s.push(line[i]);
            i++;
            continue;
        }

        char cur = s.top();
        char expected = legalpair[cur];
        if(line[i] == expected ){
            s.pop();
            i++;
        }else if(leftbracket.find(line[i]) != leftbracket.end()){
            //new char is a leftbracket
            s.push(line[i]);
            i++;
        }else {
            // corrupted
            ret = line[i];
            //cout << "found corrupted line: " << ret << endl;
            return 2;
        }
    }

    if(s.size() == 0){
        //cout << "found complete line"  << endl;
        return 0;
    }else{
        ret = legalpair[s.top()];
        //cout << "found incomplete line: " << ret << endl;        
        return 1;
    }
}