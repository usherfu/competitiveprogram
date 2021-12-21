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
#include <bits/stdc++.h>
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

#define M 10
#define N 4

char vbar_delimiter = '|', space_delimiter = ' ';

int solve(vector<string> input, vector<string> output);

int main() 
{ 
    ios::sync_with_stdio(0); //make io more efficient
    std:ifstream infile("testset_day8.txt");

    string line, s;
    size_t pos;
    int count = 0;
    vector<string> input(M);
    vector<string> output(N);

    while(getline(infile, line)){

        istringstream iss(line);
        string s;
        for(int i=0; iss >> s; i++){

            input[i] = s;
            cout << input[i] << " ";
            char c = iss.peek();
            while(c == space_delimiter){
                iss.ignore();
                c = iss.peek();
            }
            if(c == vbar_delimiter){
                iss.ignore(); // ignore '|'
                break;
            }
        }
        cout << endl;

        for(int i=0; iss >> s; i++){
            output[i] = s;
            cout << output[i] << " ";            
        }
        cout << endl;

        //solve
        cout << "solving" << endl;
        count += solve(input, output);
    }
    cout << count << endl;

    return 0;
}

 void sort(string &s){
     char c;
     for(int i=0; i<s.size()-1; i++){
         for(int j=i+1; j<s.size(); j++){
             if(s[i]>s[j]){
                 c = s[i];
                 s[i] = s[j];
                 s[j] = c;
             }
         }
     }
}

char findExtraChar(string s1, string s2){
    int len=0;
    for(int i=0; i<s1.size(); i++){
        len += s1[i];
    }
    for(int i=0; i<s2.size(); i++){
        len -= s2[i];
    }

    return char(abs(len));
}

string noDuplicateMerge(string s1, string s2){
    string s;
    int idx1=0, idx2=0;
    while(idx1<s1.size() && idx2<s2.size()){
        if(s1[idx1] == s2[idx2]){
            s += s1[idx1];
            idx1++;
            idx2++;
        }else if(s1[idx1] > s2[idx2]){
            s += s2[idx2];
            idx2++;
        }else if(s1[idx1] < s2[idx2]){
            s += s1[idx1];
            idx1++;
        }
    }
    while(idx1<s1.size()){
        s += s1[idx1];
        idx1 ++;
    }
    while(idx2<s2.size()){
        s += s2[idx2];
        idx2 ++;
    }
    return s;
}

int noOfCharDiff(string s1, string s2){
    unordered_set <char> set;
    for(int i=0;i<s1.size(); i++){
        set.insert(s1[i]);
    }

    int count = 0;
    for(int i=0; i<s2.size(); i++){
        if(set.find(s2[i]) == set.end())
            count ++;
    }
    return count;
}

// check if s1 contains all character in s2
bool contains(string s1, string s2){
    unordered_set <char> set;
    for(int i=0; i<s1.size();i++){
        set.insert(s1[i]);
    }
    for(int i=0; i<s2.size(); i++){
        if(set.find(s2[i]) == set.end())
            return false;
    }
    return true;
}
int solve(vector<string> input, vector<string> output){
    
    vector<string> digits(M, "");

    // sort
    for(int i=0; i<input.size(); i++){
        sort(input[i]);
        //cout << input[i] << " ";
        switch (input[i].size())
        {
        case 2:
            digits[1] = input[i]; // 1 is found
            break;
        case 3:
            digits[7] = input[i]; // 7 is found
            break;
        case 4:
            digits[4] = input[i]; // 4 is found
            break; 
        case 7:
            digits[8] = input[i]; // 8 is found
            break;                               
        default:
            break;
        }
    }
    for(int i=0; i<output.size(); i++){
        sort(output[i]);
        //cout << output[i] << " " << endl;
    }

    // top seg, compare 7 and 1
    char top_seg = findExtraChar(digits[7], digits[1]);
    // cout << "top seg:" << top_seg << endl;
    
    //bottom seg, no duplicate merge 7 and 4, then compare with 9

    char btm_seg;
    string s4_7 = noDuplicateMerge(digits[7], digits[4]);
    for(int i=0; i<input.size(); i++){
        if(input[i].size() == 6 && noOfCharDiff(s4_7, input[i]) == 1){
            btm_seg = findExtraChar(input[i], s4_7);
            //cout << "btm seg: " << btm_seg << endl;
            digits[9] = input[i]; // 9 is found
        }
    }

    // middle seg, 
    // find 3 by checking if it contains 1 and #of segment is 5. (only digit 2, 3 and 5 has 5 segments )
    char mid_seg;
    for(int i=0; i<input.size(); i++){
        if(input[i].size() == 5 && contains(input[i], digits[1])){
            digits[3] = input[i];  // 3 is found
            break;
        }
    }
    for(int i=0; i < digits[3].size(); i++){
        char c = digits[3][i];
        if( c != top_seg && c != btm_seg && c != digits[1][0] && c!=digits[1][1] ){
            mid_seg = c;
            break;
        }
    }

    // find 0 and 6 by list all digits with 6 segments, but not containing middle segments
    for(int i=0; i<input.size(); i++){
        if(input[i].size() == 6 && input[i] != digits[9]){
            string s(1, mid_seg);
            if(contains(input[i],s)){
                digits[6] = input[i];  // 6 is found
            }else{
                digits[0] = input[i];  // 0 is found
            }
        }
    }

    // find 5 and 2
    // first determin top right seg by comparing 6 and 8
    char top_right_seg = findExtraChar(digits[8], digits[6]);
    for(int i=0; i<input.size(); i++){
        if(input[i].size() == 5 && input[i] != digits[3]){
            string s(1, top_right_seg);
            if(contains(input[i],s)){
                digits[2] = input[i];  // 2 is found
            }else{
                digits[5] = input[i];  // 5 is found
            }

        }
    }


    // calculate final result
    int sum = 0;
    int base = 1;

    for(int i=output.size()-1; i>=0; i--){
        int bit;        
        for(int j=0; j < digits.size() ; j++){
            if(output[i] == digits[j]){
                bit = j;
                break;
            }
        }
        sum += bit * base;
        base = base * 10;
    }
    return sum;   
}