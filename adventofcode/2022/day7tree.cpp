#include "day7tree.h"

treenode::treenode(NodeType t, string name, int filesize, treenode * parent){

    this->type = t;
    this->name = name;
    this->filesize = filesize;
    this->parent = parent;
}

treenode::treenode(const treenode& node){
    this->type = node.type;
    this->name = node.name;
    this->filesize = node.filesize;
    this->parent = node.parent;

    for(const auto &e: node.children){
        this->children.push_back(e);
    }
}
treenode::~treenode(){

}