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
#include "day7tree.h"

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

void solution();
void dumpFS(treenode * cur, int indent);
int foldersize(treenode* cur, vector<int> &dirSize, int &sizeOfAtMost100000);

int main() 
{ 
 
    ios::sync_with_stdio(0); //make io more efficient
    cin.tie(0);

    solution();

    return 0; 
} 

void solution(){

    std:ifstream infile("day7.txt");
    string line;

    treenode * head = new treenode(treenode::NodeType::DIR, "/", 0, nullptr);
    //skip first line
    getline(infile, line);
    
    treenode * cur = head;
    while(getline(infile, line)){
        if(line.find("$ cd ..") != string::npos){ // parent folder
            cur = cur->parent;
        }else if(line.find("$ cd ") != string::npos){ // go to subfolder
            string folder = line.substr(5);
            for(const auto &e: cur->children){
                if(e->name == folder){
                    cur = e;
                    break;
                }
            }
        }else if(line == "$ ls"){
            continue;
        }else if(line.find("dir ") != string::npos){
            string folder = line.substr(4);
            treenode * t = new treenode(treenode::NodeType::DIR, folder, 0, cur);
            cur->children.push_back(t);
        }else{ // file
            size_t p = line.find(' ');
            int size = stoi(line.substr(0,p));
            string file = line.substr(p+1);
            treenode * t = new treenode(treenode::NodeType::FILE, file, size, cur);
            cur->children.push_back(t);
        }
    }

    dumpFS(head, 0);
    // calculate size
    int sizeOfAtMost100000 = 0;
    vector<int> dirSize;
    int rootSize = foldersize(head, dirSize, sizeOfAtMost100000);
    cout << "Part 1: total size of all directories each of which is less than 100000: " << sizeOfAtMost100000 << endl;

    int requireSpace = 30000000 - (70000000 - rootSize);
    int tobeDeleted = rootSize;
    for(const auto &e: dirSize){
        //find the smallest number that is bigger than requireSpace
        if(e > requireSpace && e < tobeDeleted){
            tobeDeleted = e;
        }
    }
    cout << "Part 2: delete directory with size " << tobeDeleted << " to retain more than 30000000 unused space" << endl;
}

void dumpFS(treenode * cur, int indent){
    string spaces = "                                                                    ";
    if (cur == nullptr)
        return;

    cout << spaces.substr(0, indent) << "- " << cur->name << " (dir)" << endl;
    indent += 2;
    for(const auto &e:cur->children){
        if(e->type == treenode::NodeType::DIR){
            dumpFS(e, indent);
        }else {
            cout << spaces.substr(0, indent) << "- " << e->name << " (file, size=" << e->filesize << ")" << endl;
        }
    }
    
}
int foldersize(treenode* cur, vector<int> &dirSize, int &sizeOfAtMost100000){
    if(cur == nullptr)
        return 0;
    int size = 0;
    for(const auto &e:cur->children){
        if(e->type == treenode::NodeType::FILE){
            size += e->filesize;
        }else{
            size += foldersize(e, dirSize, sizeOfAtMost100000);
        }
    }
    cout << "folder: " << cur->name << " " << size << endl;
    dirSize.push_back(size);

    if(size <= 100000){
        sizeOfAtMost100000 += size;
    }
    return size;
}