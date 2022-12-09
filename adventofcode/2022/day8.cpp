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
#include <filesystem>
#include <fstream>
#include <string>

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

void solution1();
void solution2();

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    //solution1();
    solution2();

    return 0; 
} 

void solution1(){

    std:ifstream infile("day8.txt");
    string line;

    int N = 99; // change this value with different input
    vector< vector<int> > grid(N, vector<int>(N)), marker(N, vector<int>(N, 0)); // marker initial value as 0
    int row = 0;
    while(getline(infile, line)){
        for(int i=0; i<line.size(); i++){
            grid[row][i] =  line[i] - '0'; //stoi(line.substr(i, 1));
        }
        row++;
    }

    // 1. scan row by row from left to right, with max_left, add 1 to corresponding marker if it is visiable from left
    for(int i=1; i < N-1; i++){
        int max_left = grid[i][0];
        for(int j=1; j < N-1; j++){
            // if(marker[i][j] == 0) //already marked
            //     continue;
            if(grid[i][j] > max_left){
                marker[i][j]++;
                max_left = grid[i][j];
            }
        }
    }

    // 2. scan row by row from right to left, with max_right, add 1 to corresponding marker if it is visiable from right. 
    for(int i=1; i < N-1; i++){
        int max_right = grid[i][N-1];
        for(int j=N-2; j>0; j--){
            if(grid[i][j] > max_right){
                marker[i][j]++;
                max_right = grid[i][j];
            }
        }
    }

    // 3. scan col by col from top to bottom, with max_top, add 1 to corresponding marker if it is visiable from top
    for(int j=1; j < N-1; j++){
        int max_top = grid[0][j];
        for(int i=1; i < N-1;i++){
            if(grid[i][j] > max_top){
                marker[i][j] ++;
                max_top = grid[i][j];
            }
        }
    }

    // 4. scan col by col from bottom to top, with max_bottom, add 1 to corresponding marker if it is visiable from bottom
    for(int j=1; j < N-1; j++){
        int max_bottom = grid[N-1][j];
        for(int i=N-2; i>0; i--){
            if(grid[i][j] > max_bottom){
                marker[i][j]++;
                max_bottom = grid[i][j];
            }
        }
    }

    // 5. count how many interior trees are visible (marker[i][j] != 0)
    int total = 0;

    for(int i=1; i < N-1; i++){
        for(int j=1; j < N-1; j++){
            if(marker[i][j] != 0)
                total ++;
        }
    }

    // // print marker
    // for (int i = 0; i < marker.size(); i++)
    // {
    //     for (int j = 0; j < marker[i].size(); j++)
    //     {
    //         cout << marker[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << "total visible trees: " << total + N*2 + (N-2)*2 << endl;
    // // print grid
    // for (int i = 0; i < grid.size(); i++)
    // {
    //     for (int j = 0; j < grid[i].size(); j++)
    //     {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return;
}

void solution2(){

    std:ifstream infile("day8.txt");
    string line;

    int N = 99; // change this value with different input
    vector< vector<int> > grid(N, vector<int>(N)), marker(N, vector<int>(N, 1)); // marker initial value as 1
    int row = 0;
    while(getline(infile, line)){
        for(int i=0; i<line.size(); i++){
            grid[row][i] =  line[i] - '0'; //stoi(line.substr(i, 1));
        }
        row++;
    }

    // 1.calculate scenic score
    for(int i=1; i < N-1; i++){
        for(int j=1; j < N-1; j++){

            // compare with left
            int dis = 0, index = j-1;
            while(index>=0){
                if(grid[i][j] > grid[i][index]){
                    dis++;
                    index--;
                }else{
                    dis++;
                    break;
                }
            }
            marker[i][j] *= dis;

            // compare with right
            dis = 0, index = j+1;
            while(index <= (N-1)){
                if (grid[i][j] > grid[i][index]){
                    dis++;
                    index ++;
                }else{
                    dis++;
                    break;
                }
            }
            marker[i][j] *= dis;

            // compare with up
            dis = 0, index = i-1;
            while(index >= 0){
                if(grid[i][j] > grid[index][j]){
                    dis++;
                    index--;
                }else{
                    dis++;
                    break;
                }
            }
            marker[i][j] *= dis;

            // compare with down
            dis = 0, index = i+1;
            while(index <= (N-1)){
                if(grid[i][j] > grid[index][j]){
                    dis++;
                    index++;
                }else { 
                    dis++;
                    break;
                }
            }
            marker[i][j] *= dis;
        }
    }


    // 2. find the lastest scenic score in marker

    int maxscore = 0, maxi = -1, maxj = -1;
    for(int i=1; i < N-1; i++){
        for(int j=1; j < N-1; j++){
            if(marker[i][j] > maxscore)
                maxscore = marker[i][j];
                maxi = i;
                maxj = j;
        }
    }

    // print marker
    for (int i = 0; i < marker.size(); i++)
    {
        for (int j = 0; j < marker[i].size(); j++)
        {
            cout << marker[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "max scenic score: " << maxscore << "at (" << maxi << ',' << maxj << ")" << endl;

    return;
}