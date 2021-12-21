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
int check(string line, char &ret, string& rest);

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    string line;
    ll score = 0;
    vector<ll> totalscore;
    vector<string> reststring;
    char ret;
    while(getline(cin, line)){
        string rest;
        int result = check(line, ret, rest);
        if(result == 1){
            reststring.push_back(rest);
            score = 0;
            for(int i=0; i<rest.size(); i++){
                score *= 5;

                switch (rest[i])
                {
                case ')':
                    score += 1;
                    break;
                case ']':
                    score += 2;
                    break;
                case '}':
                    score += 3;
                    break;
                case '>':
                    score += 4;
                    break;                                
                default:
                    break;
                }

            }
            totalscore.push_back(score);            
        }
    }
    cout << endl;
    for(int i=0; i<reststring.size(); i++){
        cout << reststring[i] << endl;
    }
    cout << endl;
    for(int i=0; i<totalscore.size()-1; i++){
        for(int j=i+1; j<totalscore.size(); j++){
            if(totalscore[i] > totalscore[j]){
                ll t = totalscore[i];
                totalscore[i] = totalscore[j];
                totalscore[j] = t;
            }
        }
    }
    for(int i=0; i<totalscore.size(); i++){
        cout << totalscore[i] << endl;
    }
    cout << "middle value: " << totalscore[(totalscore.size())/2];
    return 0; 
} 

// return:
//       0: syntax correct and complete
//       1: syntax correct and incomplete. Parameter rest contains the rest of expected character
//       2: syntax corrupted, and parameter ret contains the first illegal character
int check(string line, char &ret, string& rest){
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
        while(s.size() != 0){
            rest.push_back(legalpair[s.top()]);
            s.pop();
        }
        //cout << "found incomplete line: " << ret << endl;        
        return 1;
    }
}