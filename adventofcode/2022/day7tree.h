#include <string>
#include <vector>
using namespace std;

class treenode
{
public:
    enum NodeType {FILE, DIR};
    //treenode(/* args */);
    treenode(const treenode& node);
    treenode(NodeType t, string name, int filesize, treenode * parent);
    ~treenode();

    NodeType type;
    string name;
    int filesize;
    vector<treenode *> children;
    treenode * parent;

private:    
};


// class day7tree
// {
// private:
//     /* data */
// public:
//     day7tree(/* args */);
//     ~day7tree();
// };


