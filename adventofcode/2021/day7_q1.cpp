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
#include <fstream>
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


int main() 
{ 
    ios::sync_with_stdio(0); //make io more efficient
    std:ifstream infile("testset_day7.txt");

    string line;
    getline(infile, line);
    stringstream ssdata(line);
    vector<int> posvec;
    for(int i; ssdata>>i;){
        posvec.push_back(i);
        if (ssdata.peek() == ',')
            ssdata.ignore();
    }

    int M = posvec.size();
    int t;
    //sort
    for(int i=0; i<M-1; i++){
        for(int j=i+1; j<M; j++){
            if (posvec[i] > posvec[j]){
                t = posvec[i];
                posvec[i] = posvec[j];
                posvec[j] = t;
            }
        }
    }
    for(int i=0; i<M; i++){
        cout << posvec[i] << ' ';
    }

    ll min = LLONG_MAX;
    int maxP = posvec[M-1];
    cout << "maxP: " << maxP << endl;
    for(int p=0; p<maxP; p++){
        ll sum=0;

        for(int i=0; i<M; i++){
            sum += abs(posvec[i]-p);
        }

        if (sum < min)
            min = sum;
    }

    cout << endl << min;
    return 0;
}

