#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <vector>

using namespace std;


class TreeNode
{
public:
    int row;
    int col;
    int AiWinCnt;   //the number of wins in the simulation
    int TotalCnt;   //total number of simulation
    int MyColor;    //color for AI player
    int WhosTurn;   //this node is whose turn
    std::vector<TreeNode*> children;    //children's pointer array
    TreeNode * parent;      //parent pointer

public:
    //constructor
    TreeNode(int mycolor, int whosturn);
    void PrintTree();
};

//a small class to store position
class Pairs{
public:
    int r;  //row
    int c;  //column
public:
    //constructor
    Pairs(int rr, int cc) : r(rr), c(cc){}
};

#endif // TREENODE_H
