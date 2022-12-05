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

string solution(); 
void move1(string line, vector< stack<char> > &crates);
void move2(string line, vector< stack<char> > &crates);

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    cout << solution();

    return 0; 
} 

string solution(){

    string line;
    vector< stack<char> > crates;
    crates.reserve(10);

    // 1. initialize
    int ts = 0;
    while(getline(cin, line)){
        if (line.find('1') != string::npos){
            ts = stoi(line.substr(line.size()-3));
            break;
        }


        int index = 0;
        for(int i=0; i <= line.size()+1; i += 4){
            if(line[i+1] != ' '){
                crates[index].push(line[i+1]);
            }
            index ++;
        }
    }

    for(int i=0; i<ts;i++){
        stack<char> s;
        while(!crates[i].empty()){
            s.push(crates[i].top());
            crates[i].pop();            
        }
        crates[i].swap(s);
    }

    // 2. move 1 command
    while(getline(cin, line)){
        if(line.empty())
            continue;
        
        // part 1
        //move1(line, crates);

        // part 2
        move2(line, crates);
    }

    // 3. return top element of each stack
    string result;
    for(int i=0; i<ts; i++){
        result += crates[i].top();
    }

    // cout << "total # of stack: " << ts << endl;
    // for(int i=0; i<ts; i++){
    //     cout << "stack: " << i+1 << endl;
    //     while(! crates[i].empty()){
    //         cout << crates[i].top() << ' ';    
    //         crates[i].pop();
    //     }
    //     cout << endl;
    // }
    return result;
}

void move1(string line, vector< stack<char> > & crates){
    size_t posfrom = line.find("from"), posto = line.find("to");
    int n = stoi(line.substr(4, posfrom-1)); // extract between 'move' and 'from'

    int from = stoi(line.substr(posfrom+4, posto-1)); // extract between 'from' and 'to'
    int to = stoi(line.substr(posto+2));
    //cout << n << ' ' << from << ' ' << to << endl;

    while(n){
        crates[to-1].push(crates[from-1].top());
        crates[from-1].pop();
        n--;
    }
    
}

void move2(string line, vector< stack<char> > & crates){
    size_t posfrom = line.find("from"), posto = line.find("to");
    int n = stoi(line.substr(4, posfrom-1)); // extract between 'move' and 'from'

    int from = stoi(line.substr(posfrom+4, posto-1)); // extract between 'from' and 'to'
    int to = stoi(line.substr(posto+2));
    //cout << n << ' ' << from << ' ' << to << endl;

    stack<char> temp;
    while(n){
        temp.push(crates[from-1].top());
        crates[from-1].pop();
        n--;
    }
    while(!temp.empty()){
        crates[to-1].push(temp.top());
        temp.pop();
    }


    
}