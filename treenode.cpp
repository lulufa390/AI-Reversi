#include "treenode.h"

//constructor for a TreeNode
TreeNode::TreeNode(int mycolor, int whosturn)
{
    row = col = -1;
    AiWinCnt = TotalCnt = 0;
    MyColor = mycolor;
    WhosTurn = whosturn;
    parent = NULL;

}

//a function for debugging
void TreeNode::PrintTree(){
    cout << WhosTurn << " " << row << " " << col << " " << AiWinCnt << " " << TotalCnt << endl;
    for(int i =0;i<children.size();i++){
        cout << "child" << i << endl;
        children[i]->PrintTree();
    }
}



