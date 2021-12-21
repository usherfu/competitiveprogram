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

#define COMMA_DELIMITER ","
#define EQUAL_DELIMITER "="

int foldX(vector<vector<int>> &m, int xx, int XX, int YY);
int foldY(vector<vector<int>> &m, int yy, int XX, int YY);
void print_matrix(const vector<vector<int>> &m, int XX, int YY);

int main() 
{ 

    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    vector<pair<int, int>> coordinate;
    vector<pair<char, int>> instructions;
    
    int maxX = -1, maxY = -1;
    string line;
    char comma;
    while(getline(cin, line)){
        size_t pos = line.find(COMMA_DELIMITER);
        if(pos == string::npos){
            // reading folding instructions
            if (line == "") continue; // skip empty line

            pos = line.find(EQUAL_DELIMITER);
            if(pos != string::npos){
                char c = line[pos-1];
                int cor = stoi(line.substr(pos+1));
                instructions.push_back(pair<char, int>{c, cor});
            }
        }else {
            // reading cooridnates
            stringstream ss(line);
            int x, y;
            ss >> x >> comma >> y;
            coordinate.push_back(pair<int, int>{x, y});
            
            if(x > maxX) maxX = x;
            if(y > maxY) maxY = y;
        }
    }    

    // for(int i=0; i<coordinate.size(); i++){
    //     cout << coordinate[i].first << "," << coordinate[i].second << endl;
    // }
    // for (size_t i = 0; i < instructions.size(); i++)
    // {
    //     cout << instructions[i].first << "=" << instructions[i].second << endl;
    // }
    
    // cout << maxX << "," << maxY << endl;

    int X = maxX +1, Y = maxY + 1;
    vector<vector<int> > matrix(Y, vector<int>(X));
    for (size_t i = 0; i < coordinate.size(); i++)
    {
        matrix[coordinate[i].second][coordinate[i].first] = 1;
    }

    // print matrix
    print_matrix(matrix, X, Y);
    cout << endl;
    // solve
    int XX = X, YY = Y;
    for(int n=0; n<instructions.size(); n++){
        if(instructions[n].first == 'x'){
            XX = foldX(matrix, instructions[n].second, XX, YY);
        }else if (instructions[n].first == 'y')
        {
            YY = foldY(matrix, instructions[n].second, XX, YY);
        }        
    }
    
    print_matrix(matrix, XX, YY);

    int count = 0;
    for(int y=0; y<YY; y++ ){
        for(int x=0; x<XX; x++)
            count += matrix[y][x];
    }

    cout << "Total visible dot; " << count << endl;
}

// fold along xx axis, return new X dimension
// XX and YY are the current matrix dimension
int foldX(vector<vector<int>> &m, int xx, int XX, int YY){

    if(xx > XX){
        cout << "wrong input: x= " << xx << "XX = " << XX << endl;
        return -1;
    }
    for(int x= xx+1; x < XX; x++){
        for(int y=0; y < YY; y++){
            m[y][xx-(x-xx)] = m[y][xx-(x-xx)] || m[y][x];
        }
    }
    return xx;
}

// fold along yy axis, return new Y dimension
int foldY(vector<vector<int>> &m, int yy, int XX, int YY){
    if(yy > YY){
        cout << "wrong input: y= " << yy << "YY = " << YY << endl;
        return -1;        
    }
    for(int y=yy+1; y < YY; y++){
        for(int x=0; x < XX; x++){
            m[yy-(y-yy)][x] = m[yy-(y-yy)][x] || m[y][x];
        }
    }
    return yy;
}

void print_matrix(const vector<vector<int>> &m, int XX, int YY){
    // print matrix
    for (size_t i = 0; i < YY; i++)
    {
        for (size_t j = 0; j < XX; j++)
        {
            char c = m[i][j] ? '#' : '.';
            cout << c << ' ';
        }
        cout << endl;
    }    
}