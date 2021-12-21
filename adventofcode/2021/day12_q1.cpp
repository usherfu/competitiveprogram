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
#define EDGE_DELIMITER "-"
#define START "start"
#define END "end"

void print_graph(const std::unordered_map<string, std::list<string>> & g);
void add_path(string fromNode, string toNode, std::unordered_map<string, std::list<string>> & g);
vector<vector<string>> bfs(const vector<string> &curPath, std::unordered_map<string, std::list<string>> & g);
bool isUpper(const std::string& s);
bool isLower(const std::string& s);

int main() 
{ 
    

    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    std::unordered_map<string, std::list<string>> g; // string is the name of node, e.g. start, A, end, and etc.

    string line;
    while(getline(cin, line)){
        size_t pos = line.find(EDGE_DELIMITER);
        if(pos == string::npos)  continue;

        string fromNode = line.substr(0, pos), toNode = line.substr(pos+1);
        
        add_path(fromNode, toNode, g);
    }

    print_graph(g);

    vector<string> curPath;
    curPath.push_back("start");
    vector<vector<string>> paths = bfs(curPath, g);
    

    for(int i=0; i<paths.size(); i++){
        cout << "start ";
        for(int j=0; j<paths[i].size(); j++){
            cout << paths[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "total paths: " << paths.size() << endl;    
}

/*
Parameter:
    curPath: from start to current node
    g: the complete graph
    return: a list of paths, which could lead to "end" from curPath

*/
vector<vector<string>> bfs(const vector<string> &curPath, std::unordered_map<string, std::list<string>> & g){
    string curNode = curPath.back();
    vector<vector<string>> toEnd;

    std::list<string> linkedNode = g[curNode];
    for(string s : linkedNode){
        if(s == END){
            vector<string> v;
            v.push_back(END);
            toEnd.push_back(v);
        }else if(s == START){
            continue;
        }else if(isUpper(s)){
            vector<string> newPath(curPath.begin(), curPath.end());
            newPath.push_back(s);
            vector<vector<string>> rest = bfs(newPath, g);
            for(int i=0; i<rest.size(); i++){
                rest[i].insert(rest[i].begin(), s);
                toEnd.push_back(rest[i]); // 
            }            
        }else if(isLower(s) && std::count(curPath.begin(), curPath.end(), s) == 0){
            // next node s has not been visited before
            vector<string> newPath(curPath.begin(), curPath.end());
            newPath.push_back(s);
            vector<vector<string>> rest = bfs(newPath, g);
            for(int i=0; i<rest.size(); i++){
                rest[i].insert(rest[i].begin(), s);
                toEnd.push_back(rest[i]); //             
            }
        }
    }
 
    return toEnd; 
}

bool isUpper(const std::string& s) {
    return std::all_of(s.begin(), s.end(), [](unsigned char c){ return std::isupper(c); });
}

bool isLower(const std::string& s) {
    return std::all_of(s.begin(), s.end(), [](unsigned char c){ return std::islower(c); });
}

void add_path(string fromNode, string toNode, std::unordered_map<string, std::list<string>> & g){

        if(g.find(fromNode) == g.end()){
            // new node added to graph
            std::list<string> linkedNode;
            linkedNode.push_back(toNode);
            g[fromNode] = linkedNode;
        }else{
            g[fromNode].push_back(toNode);
        }
        // reverse direction

        if(g.find(toNode) == g.end()){
            // new node added to graph
            std::list<string> linkedNode;
            linkedNode.push_back(fromNode);
            g[toNode] = linkedNode;
        }else{
            g[toNode].push_back(fromNode);
        }        
}

void print_graph(const std::unordered_map<string, std::list<string>> & g){

    for(const auto it : g){
        cout << it.first << ": ";
        std::list<string> linkedNode = it.second;
        for(string s : linkedNode){
            cout << s << ' ';
        }
        cout << endl;
    }
}