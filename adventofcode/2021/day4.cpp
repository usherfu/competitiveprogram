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

#define N 5
#define M 5
#define MARK -1

vector<int> inputNum;
vector< vector<int> > board;
vector<bool> board_mark;
vector<int> curArray;
    vector<int> winning_board;
    vector<int> winning_number;
    

int solve( int r);
void solve2( int r);
void print_result(int w, int r);

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

// part 1

// read data

    string line;

    getline(cin, line);
    stringstream ssdata(line);
    for(int i; ssdata>>i;){
        inputNum.push_back(i);
        if (ssdata.peek() == ',')
            ssdata.ignore();
    }

    while(getline(cin, line)){
        if (line == "" && curArray.size() != 0){
            board.push_back(curArray);
            board_mark.push_back(true);
            curArray.clear();
        }
        stringstream ss(line);
        for(int i; ss >> i;){
            curArray.push_back(i);
            if(ss.peek() == ' ')
                ss.ignore();
        }
    }
    if(curArray.size() != 0){
        board_mark.push_back(true);
        board.push_back(curArray);
    }


    // for(int i=0; i<inputNum.size(); i++)
    // {
    //     cout << inputNum[i] << ' '; 
    // }
    // cout << endl;

    // for(int i=0; i<board.size(); i++)
    // {
    //     for(int j=0; j<board[i].size(); j++){
    //         cout << board[i][j] << ' ';
    //         if((j+1)%5 == 0)
    //             cout << endl;
    //     }
    //     cout << endl;

    // }

    // solve1
    // int winning = -1, called = -1;
    // for(int i=0; i < inputNum.size(); i++){
    //     cout << "checking number: " << inputNum[i] << endl;
    //     winning = solve(inputNum[i]);
    //     if( winning != -1 ){
    //         called = inputNum[i];
    //         break;
    //     }
    // }

    // if(winning != -1){
    //     cout << "Board found: " << winning << endl;
    //     int unmarked = 0;
    //     for(int j=0; j<board[winning].size(); j++){
    //         if(board[winning][j] != -1)
    //             unmarked += board[winning][j];
    //         cout << board[winning][j] << ' ';
    //         if((j+1)%5 == 0)
    //             cout << endl;
    //     }
    //     cout << called * unmarked;
    // }

    //solve 2
    for(int i=0; i < inputNum.size(); i++){
        cout << "checking number: " << inputNum[i] << endl;
        solve2(inputNum[i]);
    }


  return 0; 
}

int solve( int r){
    for(int b=0; b < board.size(); b++){
        for(int i=0; i<board[b].size(); i++){
            if(board[b][i] == r){
                board[b][i] = MARK;
                //cout << "match: board " << b << " (" << i  << ")  -  ";
            }
        }
        //cout << endl;
        // check row
        int count = 0;
        for(int i=0; i<board[b].size(); i++){
            count += board[b][i];
            if((i+1)%5 == 0){
                if(count == -5){
                    return b;
                }
                count = 0;
            }
        }

        // check col
        for(int i=0; i<N; i++){
            count = 0;
            for(int j=0; j<M; j++){
                count += board[b][i+5*j];
            }
            if(count == -5)
                return b;
        }
    }

    return -1;
}

void solve2( int r){


    for(int b=0; b < board.size(); b++){
        for(int i=0; i<board[b].size(); i++){
            if(board[b][i] == r){
                board[b][i] = MARK;
            }
        }

        // check row
        int count = 0;
        if(board_mark[b]){
            for(int i=0; i<board[b].size(); i++){
                count += board[b][i];
                if((i+1)%5 == 0){
                    if(count == -5){
                        board_mark[b] = false;
                        cout << "checking row: " << b <<  endl;
                        winning_board.push_back(b);
                        winning_number.push_back(r);
                        print_result(b, r);
                    }
                    count = 0;
                }
            }
        }


        // check col
        count = 0;
        if(board_mark[b]){
            for(int i=0; i<N; i++){
                count = 0;
                for(int j=0; j<M; j++){
                    count += board[b][i+5*j];
                }

                if(count == -5){
                    board_mark[b] = false;;
                    cout << "checking col: " << b <<  endl;
                    winning_board.push_back(b);
                    winning_number.push_back(r);                    
                    print_result(b, r);
                }
            }
        }

    }

    // cout << "winning_board size: " << winning_board.size() << endl;
    // for(int i=0; i<winning_board.size(); i++){
    //     cout << winning_board[i] << endl;
    //     cout << winning_number[i] << endl;
    // }


    //print_result(winning_board[winning_board.size()-1], winning_number[winning_number.size()-1]);

}

void print_result(int w, int r){

            int unmarked = 0;
            for(int j=0; j<board[w].size(); j++){
                if(board[w][j] != -1)
                    unmarked += board[w][j];
                cout << board[w][j] << ' ';
                if((j+1)%5 == 0)
                    cout << endl;
            }
            cout << r * unmarked << endl;
}