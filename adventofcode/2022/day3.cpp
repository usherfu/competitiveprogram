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

int part1(); 
int part2();
char duplicate(string line);

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

// part 1
   //cout << part1();

// part 2
    cout << part2();
    return 0; 
} 


int part1(){

    string line;
    int total = 0;
    while(getline(cin, line)){
        char dup = duplicate(line);
        //cout << dup << endl;
        if(dup <= 'Z')
            total += dup - 'A' + 27;
        
        if(dup >='a')
            total += dup - 'a' + 1;
    }
    return total;
}

char duplicate(string line){
    unordered_set<char> com1, com2;
    int size = line.size();
    for(int i=0; i<size; i++){
        if(i<size/2)
            com1.insert(line[i]);
        else
            com2.insert(line[i]);
    }

    for(const auto& elem: com1) {
    //for(unordered_set<char>::iterator itr = com1.begin(); itr != com1.end(); ++itr){
        auto p = com2.insert(elem);
        if(p.second == false)
            return elem;
    }
    return 0;
}

int part2(){
    
    int total = 0;
    string line;
    while(getline(cin, line)){

        unordered_set<char> r1, r2, r3;
        for(int i=0; i<line.size(); i++){
            r1.insert(line[i]);
        }
        getline(cin, line);

        for(int i=0; i<line.size(); i++){
            r2.insert(line[i]);
        }        
        getline(cin, line);
        for(int i=0; i<line.size(); i++){
            r3.insert(line[i]);
        }

        char common = '.';
        for(const auto& re1: r1){
            if (r2.find(re1) != r1.end() && r3.find(re1) != r3.end()){
                common = re1;
            }
        }

        if(common <= 'Z')
            total += common - 'A' + 27;
        
        if(common >='a')
            total += common - 'a' + 1;  
      
    }
    return total;
}