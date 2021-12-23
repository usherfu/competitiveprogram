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

#define DELIMITER "->"
#define GEN 10

void subtemplate(string left, string right, int gen, unordered_map<string, ll> &nodeCount, unordered_map<string, string> &rules);

//使用递归，但是效率还是不行。
int main() 
{ 

    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);
    
    string t, line;
    
    // read template
    cin >> t; 

    // read rule & initialize nodeCount
    
    unordered_map<string, ll> nodeCount;    
    unordered_map<string, string> rules;
    while (getline(cin, line))
    {   
        size_t pos = line.find(DELIMITER);
        
        if(pos == std::string::npos) continue;

        string pair = line.substr(0, pos -1);
        string middle = line.substr(pos+3);
        rules[pair] =  middle;

        nodeCount[string(1, pair[0])] = 0;
        nodeCount[string(1, pair[1])] = 0;
        nodeCount[middle] = 0;
    }
    
    for(auto i: rules){
        cout << i.first << "---" << i.second << endl;
    }

    for(auto n: nodeCount){
        cout << n.first << ": "  << n.second << endl;
    }

    for(int i=0; i<t.size()-1; i++){
        string left(1, t[i]), right(1, t[i+1]);
        subtemplate(left, right, GEN-1, nodeCount, rules);
        nodeCount[left]++;
    }
    nodeCount[string(1, t.back())]++;
    
    for(auto i: nodeCount){
        cout << i.first << "---" << i.second << endl;
    }

}

// find gen-th sub template given "left" and "right" character, and save occurance of each character in nodeCount
void subtemplate(string left, string right, int gen, unordered_map<string, ll> &nodeCount, unordered_map<string, string> &rules){
    string middle = rules[left + right];
    nodeCount[middle]++;
    if(gen == 0){
        return;
    }

    subtemplate(left, middle, gen-1, nodeCount, rules);
    subtemplate(middle, right, gen-1, nodeCount, rules);
}

