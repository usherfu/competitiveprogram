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

string space_delimiter = " ", hyphen_delimiter = "-", colon_delimiter = ": ";

bool solve1(string input)
{
    size_t pos = 0;
    int minFreq = 10000000;
    int maxFreq = -1;
    string key, password;

    pos = input.find(space_delimiter);
    if(pos == string::npos)
        return false;
    
    // extract frequency bound
    string temp = input.substr(0, pos);
    input.erase(0, pos + space_delimiter.length()); // remove extracted string
 
    pos = temp.find(hyphen_delimiter);
    if(pos == string::npos)
        return false;
    
    minFreq = stoi(temp.substr(0, pos));

    maxFreq = stoi(temp.substr(pos + 1));

    // extract key letter
    pos = input.find(colon_delimiter);
    if(pos == string::npos)
        return false;
    key = input.substr(0, pos);
    
    // extract password
    password= input.substr(pos + colon_delimiter.length());

    //cout << "minFreq, maxFreq:" << minFreq << ", " << maxFreq << endl;
    //cout << "key, password: " << key << ", " << password << endl;

    int nCount = 0;
    for(int i=0; i < password.length(); ++i)
    {
        if (password[i] == key[0]){
            nCount++;
            if (nCount > maxFreq)
                return false;
        }
    }
    if(nCount < minFreq)
        return false;
    return true;
}

bool solve2(string input)
{
    size_t pos = 0;
    int minFreq = 10000000;
    int maxFreq = -1;
    string key, password;

    pos = input.find(space_delimiter);
    if(pos == string::npos)
        return false;
    
    // extract frequency bound
    string temp = input.substr(0, pos);
    input.erase(0, pos + space_delimiter.length()); // remove extracted string
 
    pos = temp.find(hyphen_delimiter);
    if(pos == string::npos)
        return false;
    
    minFreq = stoi(temp.substr(0, pos));

    maxFreq = stoi(temp.substr(pos + 1));

    // extract key letter
    pos = input.find(colon_delimiter);
    if(pos == string::npos)
        return false;
    key = input.substr(0, pos);
    
    // extract password
    password= input.substr(pos + colon_delimiter.length());

    //cout << "minFreq, maxFreq:" << minFreq << ", " << maxFreq << endl;
    //cout << "key, password: " << key << ", " << password << endl;

    if(minFreq > password.length() || maxFreq > password.length())
        return false;

    if((password[minFreq-1] == key[0] && password[maxFreq-1] != key[0]) ||
       (password[minFreq-1] != key[0] && password[maxFreq-1] == key[0]))
        return true;

    return false;
}

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    string line;
    int validPassword = 0;
    while(getline(cin, line)){
        if(solve2(line))
            validPassword ++ ;
    }
    cout << validPassword;
    return 0; 
} 