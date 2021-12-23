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
#define GEN 40

unordered_map<string, ll> nextGeneration(unordered_map<string, ll> & pairCount, unordered_map<string, vector<string>> &rules);
void print_pairCount(unordered_map<string, ll> & pairCount);

int main() 
{ 

    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);
    
    string t, line;
    
    // read template
    cin >> t; 

    //这道题的思路不是把最终的字符串建造出来，而是直接计数 pair的个数。
    // reference https://github.com/welguisz/advent-of-code/blob/main/src/com/dwelguisz/year2021/AdventDay14.java
    // read rule: the rule has been transformed into following format:
    /*
    CH -> B  becomes CH -> [CB, BH]
    essentially we are counting pair now, then we count again the char in each pair
    */
    
    //unordered_map<string, ll> nodeCount;    
    unordered_map<string, vector<string>> rules;
    while (getline(cin, line))
    {   
        size_t pos = line.find(DELIMITER);
        
        if(pos == std::string::npos) continue;

        string pair = line.substr(0, pos -1);
        string middle = line.substr(pos+3);
        vector<string> output;
        output.push_back(pair[0] + middle);
        output.push_back(middle + pair[1]);
        rules[pair] =  output;
    }
    
    // print rules
    for(auto i: rules){
        cout << i.first << "--- [" ;
        vector<string> output = i.second;
        for(string s: output){
            cout << s << ' ';
        }
        cout << " ]" << endl;
    }

    set<string> pairs; // line "NNCB" --> pairs ["NN", "NC", "CB"]
    unordered_map<string, ll> pairCount;    // and count occurrences of each pair
    for(int i=0; i<t.size()-1; i++){
        string sub = t.substr(i,2);
        pairs.insert(sub);
        pairCount[sub] ++;
    }
 
    print_pairCount(pairCount);   
    cout << "------" << endl;     
    // ATTENTION: following approach double counted each character except the first and last letter of original template
    for(int i=1; i<=GEN; i++){
        pairCount = nextGeneration(pairCount, rules);
        cout << "After step : " << i << endl;
        print_pairCount(pairCount);        
    }

    unordered_map<char, ll> letterCount;
    for(auto p: pairCount){
        //cout << p.first << ": " << p.second << endl;
        string key = p.first;
        for(int i=0; i<key.size(); i++){
            letterCount[key[i]] += p.second;
        }
    }

    // now need also double count the first and last letter of original template
    letterCount[t.front()] += 1;
    letterCount[t.back()] += 1;

    ll max = -1, min = LLONG_MAX;
    for(auto l: letterCount){
        cout << l.first << ": " << l.second / 2 << endl;
        
        if(l.second/2 > max) max = l.second/2;

        if(l.second/2 < min) min = l.second/2;

    }

    cout << "difference: " << max - min << endl;

}

void print_pairCount(unordered_map<string, ll> & pairCount){
    for(auto i: pairCount){
        cout << i.first << ": " << i.second << endl;
    }
}
unordered_map<string, ll> nextGeneration(unordered_map<string, ll> & pairCount, unordered_map<string, vector<string>> &rules){
    unordered_map<string, ll> newPairCount;

    for(auto countStr: pairCount){
        // with key "countStr.first", get resulting pairs "mapped"
        // from CH (countStr.first) --> [CB, BH] (mapped)  
        vector<string> mapped = rules[countStr.first]; 

        for(string m : mapped){
            newPairCount[m] += countStr.second; // this is most critical step!!! do not add pairCount[m], which should be discarded
        }
    }
    return newPairCount;
}

// unordered_map<string, ll> nextGeneration(unordered_map<string, ll> & pairCount, unordered_map<string, vector<string>> &rules){
//     unordered_map<string, ll> newPairCount;

//     for(auto countStr: pairCount){
//         // with key "countStr.first", get resulting pairs "mapped"
//         // from CH (countStr.first) --> [CB, BH] (mapped)
//         vector<string> mapped = rules[countStr.first]; 

//         for(string m : mapped){
//             newPairCount[m] += pairCount[m] +1 ;
//         }
//     }

//     return newPairCount;
// }
