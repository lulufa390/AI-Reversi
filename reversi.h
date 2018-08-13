#ifndef REVERSI_H
#define REVERSI_H

#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "treenode.h"

const int SearchConst = 3000;

class Reversi
{
public:
    Reversi();
    Reversi(const Reversi & c);
    void init();
    void print();

    int play(int row,int cow);
    int getPlayer();
    int board[8][8];    //chess board, 1 for black chess, 0 for empty, -1 for white chess
    int blackCount();
    int whiteCount();
    int isEnd();
    int endResult();

    //function for AI player
    void AIplayer();

    //MCTS search part
    TreeNode * SearchTree(TreeNode * root);

    //Randomly play from some node to the end and get the result
    int RandomPlay(TreeNode * node);

    //backup the result to the node's ancestors
    void Backup(TreeNode * leaf, bool res);

    //find the best child for MCTS
    TreeNode * BestChild(TreeNode * parent);

    //pick the best way and play it
    void FindSolution(TreeNode * parent);

    //expand the tree node
    TreeNode * Expand(TreeNode * root);

    //check whether there is other ways to expand
    bool isExpandable(TreeNode * root);

    //copy the reversi object
    void CopyTo(Reversi & dst);

    //play the tree from origin root
    void PlayTree(Reversi & board, TreeNode * node);

    //judge whether we can put the chess pieces on specific places
    bool judge(int player, int row, int col);
    bool judge(int color, int row, int col, int direction);

private:
    int curPlayer;// the current player, 1 for black, -1 for white
    int bcnt,wcnt;

    void action(int player, int row, int col);
    void reverse(int color, int row, int col, int direction);
};

#endif // REVERSI_H
