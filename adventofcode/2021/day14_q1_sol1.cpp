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

class Node {
public:
    string data;
    Node* next;

    Node(){
        data = "";
        next = NULL;
    }

    Node(const string &s){
        data = s;
        next = NULL;
    }

    Node(const string&s, Node * pointer){
        data = s;
        next = pointer;
    }
};

void insert(Node* ptr, unordered_map<string, string> & rules);
void print_polymer(Node* head);

//使用了linked 列表
int main() 
{ 

    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);
    
    string t, line;
    
    // read template
    cin >> t;

    Node * head = new Node(string(1, t[0]));
    Node * pre = head;
    for(int i=1; i<t.size(); i++){
        Node * cur = new Node(string(1, t[i]));
        pre->next = cur;
        pre = cur;        
    }

    // read rules
    unordered_map<string, string> rules;
    while (getline(cin, line))
    {   
        size_t pos = line.find(DELIMITER);
        
        if(pos == std::string::npos) continue;

        rules[line.substr(0, pos -1)] =  line.substr(pos+3);
    }
    
    for(auto i: rules){
        cout << i.first << "---" << i.second << endl;
    }

    print_polymer(head);

    for(int i=1; i<=GEN; i++){
        Node * cur = head;
        while(cur && cur->next){
            Node * next = cur->next;
            insert(cur, rules);
            cur = next;
        }
        cout << "GEN: " << i << endl;
        //print_polymer(head);
    }

    unordered_map<string, ll> nodeCount;
    Node * current = head;
    while(current){
        nodeCount[current->data] ++;
        current = current->next; 
    }
    for(auto i: nodeCount){
        cout << i.first << "---" << i.second << endl;
    }

}

void insert(Node* ptr, unordered_map<string, string> & rules){
    string key = ptr->data + ptr->next->data;
    //cout << "key: " << key << endl;
    string val = rules[key];
    //cout << "val: " << val << endl;
    Node * newNode = new Node(val);
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void print_polymer(Node* head){
    Node * cur = head;

    while(cur){
        cout << cur->data << ' ';
        cur = cur->next;
    }
    cout << endl;
}
