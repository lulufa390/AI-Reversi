#include "reversi.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <QMessageBox>
using namespace std;

// set chess board empty
Reversi::Reversi()
{
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=0;
        }
    }
    curPlayer=0;
}

Reversi::Reversi(const Reversi & c)
{
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=c.board[i][j];
        }
    }
    curPlayer=c.curPlayer;
    bcnt = c.bcnt;
    wcnt = c.wcnt;
}

// initialize chess board
void Reversi::init()
{
    board[3][4]=board[4][3]=1;
    board[3][3]=board[4][4]=-1;
    curPlayer=1;
}

// play chess on point(row, col)
int Reversi::play(int row,int col)
{
	// find candidate points to play
    vector<int> cp;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (judge(curPlayer, i, j)) {
                cp.push_back(i * 8 + j);
            }
        }
    }
    // see if the input point is in the set of candiate points
    int find = 0;
    for (int i = 0; i < cp.size(); i++) {
        if (cp[i] == row * 8 + col) {
            find = 1;
            break;
        }
    }
    // if not, return 0
    if (!find) {
        return 0;
    }
    // if yes, reverse opponent's chess
    action(curPlayer,row,col);
    // current player change
    curPlayer=-curPlayer;
    // find out if the new current player has candidate points to play
    cp.clear();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (judge(curPlayer, i, j)) {
                cp.push_back(i * 8 + j);
            }
        }
    }
    // if not, change current player
    if(cp.empty()){
        curPlayer=-curPlayer;
    }
    return 1;
}

int Reversi::getPlayer()
{
    return curPlayer;
}

// get the number of black chess on board
int Reversi::blackCount(){
    int cnt=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==1){
                cnt++;
            }
        }
    }
    return cnt;
}

// get the number of white chess on board
int Reversi::whiteCount(){
    int cnt=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==-1){
                cnt++;
            }
        }
    }
    return cnt;
}

// get if the game ends
int Reversi::isEnd(){
    // if one player has no chess on board, game ends
	if(this->blackCount() == 0 || this->whiteCount() == 0){
        return true;
    }
    // if both players have no place to play, game ends
    vector<int> cpb,cpw;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(judge(1,i,j)){
                cpb.push_back(i*8+j);
            }
            if(judge(-1,i,j)){
                cpw.push_back(i*8+j);
            }
        }
    }
    if(cpb.size()==0&&cpw.size()==0){
        return true;
    }
    // if the chess board is full, game ends
    int count=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==0){
                count++;
            }
        }
    }
    if(count!=0){
        return false;
    }
    return true;
}

// get the game results, it returns the difference of the number of black chess 
// and the number of white chess, which means it returns a positive number if 
// black wins, and if white wins, it returns a negative number. 
int Reversi::endResult()
{
    return this->blackCount()-this->whiteCount();
}

// judge whether the point(row, col) is playable for the player
// for detail explanation, see the pseudo code in our report
bool Reversi::judge(int player, int row, int col)
{
    int color = player;
    if (board[row][col] != 0) {
        return false;
    }
    // get the result of each direction
    bool up = false, down = false, left = false, right = false;
    bool upleft = false, upright = false, downleft = false, downright = false;
    if (row >= 1 && col >= 1) {
        if (board[row - 1][col - 1] == -color) {
            upleft = judge(color, row - 1, col - 1, 0);
        }
    }
    if (row >= 1) {
        if (board[row - 1][col] == -color) {
            up = judge(color, row - 1, col, 1);
        }
    }
    if (row >= 1 && col <= 6) {
        if (board[row - 1][col + 1] == -color) {
            upright = judge(color, row - 1, col + 1, 2);
        }
    }
    if (col >= 1) {
        if (board[row][col - 1] == -color) {
            left = judge(color, row, col - 1, 3);
        }
    }
    if (col <= 6) {
        if (board[row][col + 1] == -color) {
            right = judge(color, row, col + 1, 4);
        }
    }
    if (row <= 6 && col >= 1) {
        if (board[row + 1][col - 1] == -color) {
            downleft = judge(color, row + 1, col - 1, 5);
        }
    }
    if (row <= 6) {
        if (board[row + 1][col] == -color) {
            down = judge(color, row + 1, col, 6);
        }
    }
    if (row <= 6 && col <= 6) {
        if (board[row + 1][col + 1] == -color) {
            downright = judge(color, row + 1, col + 1, 7);
        }
    }
    return up || down || left || right || upleft || upright || downleft || downright;
}

// judge whether there is a chess of the player at the paticular direction of point(row, col)
// for detail explanation, see the pseudo code in our report
bool Reversi::judge(int color, int row, int col, int direction)
{
	// if it reaches a current player's chess, return true
    if (board[row][col] == color) {
        return true;
    }
    // if it reaches an empty points, return false
    else if (board[row][col] == 0) {
        return false;
    }
    // if it reaches an opponent's chess, continue recursion
    else if (board[row][col] == -color) {
        switch (direction) {
        case 0:
            if (row >= 1 && col >= 1) {
                return judge(color, row - 1, col - 1, direction);
            }
            return false;
        case 1:
            if (row >= 1) {
                return judge(color, row - 1, col, direction);
            }
            return false;
        case 2:
            if (row >= 1 && col <= 6) {
                return judge(color, row - 1, col + 1, direction);
            }
            return false;
        case 3:
            if (col >= 1) {
                return judge(color, row, col - 1, direction);
            }
            return false;
        case 4:
            if (col <= 6) {
                return judge(color, row, col + 1, direction);
            }
            return false;
        case 5:
            if (row <= 6 && col >= 1) {
                return judge(color, row + 1, col - 1, direction);
            }
            return false;
        case 6:
            if (row <= 6) {
                return judge(color, row + 1, col, direction);
            }
            return false;
        case 7:
            if (row <= 6 && col <= 6) {
                return judge(color, row + 1, col + 1, direction);
            }
            return false;
        default:
            return false;
        }
    }
    else {
        return false;
    }
}

// the current player plays at point(row, col)
// for detail explanation, see the pseudo code in our report
void Reversi::action(int player, int row, int col)
{
    int color = player;
    board[row][col] = color;
    bool up = false, down = false, left = false, right = false;
    bool upleft = false, upright = false, downleft = false, downright = false;
    if (row >= 1 && col >= 1) {
        if (board[row - 1][col - 1] == -color)
            upleft = judge(color, row - 1, col - 1, 0);
        if (upleft)
            reverse(color, row - 1, col - 1, 0);
    }
    if (row >= 1) {
        if (board[row - 1][col] == -color)
            up = judge(color, row - 1, col, 1);
        if (up)
            reverse(color, row - 1, col, 1);
    }
    if (row >= 1 && col <= 6) {
        if (board[row - 1][col + 1] == -color)
            upright = judge(color, row - 1, col + 1, 2);
        if (upright)
            reverse(color, row - 1, col + 1, 2);
    }
    if (col >= 1) {
        if (board[row][col - 1] == -color)
            left = judge(color, row, col - 1, 3);
        if (left)
            reverse(color, row, col - 1, 3);
    }
    if (col <= 6) {
        if (board[row][col + 1] == -color)
            right = judge(color, row, col + 1, 4);
        if (right)
            reverse(color, row, col + 1, 4);
    }
    if (row <= 6 && col >= 1) {
        if (board[row + 1][col - 1] == -color)
            downleft = judge(color, row + 1, col - 1, 5);
        if (downleft)
            reverse(color, row + 1, col - 1, 5);
    }
    if (row <= 6) {
        if (board[row + 1][col] == -color)
            down = judge(color, row + 1, col, 6);
        if (down)
            reverse(color, row + 1, col, 6);
    }
    if (row <= 6 && col <= 6) {
        if (board[row + 1][col + 1] == -color)
            downright = judge(color, row + 1, col + 1, 7);
        if (downright)
            reverse(color, row + 1, col + 1, 7);
    }
}

// reverse opponent's chess at the particular direction of point(row, col) 
// for detail explanation, see the pseudo code in our report
void Reversi::reverse(int color, int row, int col, int direction)
{
	// if it reaches the current player's chess, stop recursion
    if (board[row][col] == color) {
        return;
    }
    // if it reaches an empty point, stop recursion
    else if (board[row][col] == 0) {
        return;
    }
    // if it reaches an opponent's chess, reverse it and continue recursion
    else if (board[row][col] == -color) {
        board[row][col] = color;
        switch (direction) {
        case 0:
            if (row >= 1 && col >= 1)
                reverse(color, row - 1, col - 1, direction);
            return;
        case 1:
            if (row >= 1)
                reverse(color, row - 1, col, direction);
            return;
        case 2:
            if (row >= 1 && col <= 6)
                reverse(color, row - 1, col + 1, direction);
            return;
        case 3:
            if (col >= 1)
                reverse(color, row, col - 1, direction);
            return;
        case 4:
            if (col <= 6)
                reverse(color, row, col + 1, direction);
            return;
        case 5:
            if (row <= 6 && col >= 1)
                reverse(color, row + 1, col - 1, direction);
            return;
        case 6:
            if (row <= 6)
                reverse(color, row + 1, col, direction);
            return;
        case 7:
            if (row <= 6 && col <= 6)
                reverse(color, row + 1, col + 1, direction);
            return;
        default:
            return;
        }
    }
}

//copy all variables to destination
void Reversi::CopyTo(Reversi & dst){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            dst.board[i][j]=board[i][j];
        }
    }
    dst.curPlayer=curPlayer;
    dst.bcnt = bcnt;
    dst.wcnt = wcnt;
}


//use this function to play AI
void Reversi::AIplayer(){

    //let the time as the seed for randomly playing
    srand((unsigned int)time(0));

    int SearchTime = 0;
    TreeNode * root = new TreeNode(curPlayer, -curPlayer);
    while(SearchTime++ < SearchConst){
        //MCTS
        TreeNode * selectNode = SearchTree(root);

        //randomplay
        int Result = RandomPlay(selectNode);

        //back result
        bool Aiwin = (Result * selectNode->MyColor > 0) ? true : false;
        Backup(selectNode, Aiwin);

    }

    FindSolution(root);
}

//search the MCT
TreeNode * Reversi::SearchTree(TreeNode *root){
    Reversi tmp;
    while(true){
        CopyTo(tmp);
        PlayTree(tmp, root);
        //to the end of game, quit
        if(tmp.isEnd()){
            break;
        }
        //exist some ways to expand
        if(tmp.isExpandable(root)){
            return tmp.Expand(root);
        }
        //children are full, continue search
        else{
            root = BestChild(root);
        }

    }
    return root;
}

//Random play to get a result
int Reversi::RandomPlay(TreeNode * node){
    Reversi tmp(*this);
    PlayTree(tmp, node);

    vector<Pairs> options;

    while(tmp.isEnd() == false){

        //find all possible ways
        for(int i =0;i<8;i++){
           for(int j =0;j<8;j++){
               if(tmp.judge(tmp.curPlayer, i,j)){
                   options.push_back(Pairs(i,j));
               }
           }
        }

        //random select one and play it
        int Rand = rand()%options.size();
        tmp.play(options[Rand].r, options[Rand].c);
        options.clear();

    }

    //return the result
    return tmp.endResult();
}

//backup the result
void Reversi::Backup(TreeNode *leaf, bool res){
    //add the result to all ancestors until the root
    while(leaf){
        leaf->TotalCnt += 1;
        leaf->AiWinCnt += res;
        leaf = leaf->parent;
    }
}

//find the most valuable node in MCTS
TreeNode * Reversi::BestChild(TreeNode *parent){
    if(parent->children.size() == 0){
        return NULL;
    }

    double MaxValue = 0;
    double MaxIndex = 0;
    for(int i = 0;i<parent->children.size();i++){
        double tmp;
        //if the next step is human
        if(parent->WhosTurn == parent->MyColor){
            //UCB formula
            tmp = 1 - 1.0 * parent->children[i]->AiWinCnt / parent->children[i]->TotalCnt
                + sqrt(log(parent->TotalCnt) / parent->children[i]->TotalCnt);
        }
        //if the next step is AI
        else{
            //UCB formula
            tmp = 1.0 * parent->children[i]->AiWinCnt / parent->children[i]->TotalCnt
                + sqrt(log(parent->TotalCnt) / parent->children[i]->TotalCnt);            
        }

        //change the MaxValue and index
        if(tmp > MaxValue){
            MaxValue = tmp;
            MaxIndex = i;
        }
    }

    //return the best child
    return parent->children[MaxIndex];
}

//find the best next step
void Reversi::FindSolution(TreeNode *parent){
    if(parent->children.size() == 0){
        return;
    }

    int BestIndex = 0;
    double MaxWinValue = 0;

    for(int i = 0;i<parent->children.size();i++){

        //the AI-win number of a node
        double WinValue =  1.0 * parent->children[i]->AiWinCnt;


        Reversi tmp(*this);

        //number of ways for the enemy
        int ways = 0;

        //calculate the center rate
        double centerRate1 =0, centerRate2 = 0;

        //the lose corner flag
        bool loseCorner = false;

        //calculate the pre center rate
        for(int k =2;k<6;k++){
            for(int j =2;j<6;j++){
                if(tmp.board[k][j] == parent->MyColor){
                    if(k==2||k==5||j==2||j==5){
                        centerRate1 +=1;
                    }
                    else{
                        centerRate1 +=2;
                    }
                }
            }
        }


        tmp.play(parent->children[i]->row,parent->children[i]->col);

        //calculate the after center rate
        for(int k =2;k<6;k++){
            for(int j =2;j<6;j++){
                if(tmp.board[k][j] == parent->MyColor){
                    if(k==2||k==5||j==2||j==5){
                        centerRate2 +=1;
                    }
                    else{
                        centerRate2 +=2;
                    }
                }
            }
        }

        // in the opening, the Centor is important
        if(tmp.whiteCount() + tmp.blackCount() < 32){
            WinValue *= centerRate2 / centerRate1;
        }


        //choose the step with no loseCorner and less enemy ways
        if(tmp.curPlayer != parent->MyColor){
            for(int k =0;k<8;k++){
               for(int j =0;j<8;j++){
                   if(tmp.judge(tmp.curPlayer, k,j)){
                       ways++;
                       if((k==0||k==7) && (j==0||j==7)){
                           loseCorner = true;
                       }
                   }
               }
            }
            WinValue *= (20.0 - ways) / 20.0;
            if(loseCorner){
                WinValue *= 0.7;
            }
        }

        //put in the corner is important
        if( (parent->children[i]->row == 0 || parent->children[i]->row == 7) &&
                (parent->children[i]->col == 0 || parent->children[i]->col == 7 )){
            WinValue *= 1.5;
        }
        //the other changes to the strategy
//        else if( ((parent->children[i]->row == 0 || parent->children[i]->row == 7) &&
//                (parent->children[i]->col == 2 || parent->children[i]->col == 3|| parent->children[i]->col == 4|| parent->children[i]->col == 5 ))
//                 || ((parent->children[i]->col == 0 || parent->children[i]->col == 7) &&
//                     (parent->children[i]->row == 2 || parent->children[i]->row == 3|| parent->children[i]->row == 4|| parent->children[i]->row == 5 ))
//                 )
//        {
//            WinValue *= 1.1;
//        }
//        else if( ((parent->children[i]->row == 0 || parent->children[i]->row == 7) &&
//                (parent->children[i]->col == 1 || parent->children[i]->col == 6 ))
//                 || ((parent->children[i]->col == 0 || parent->children[i]->col == 7) &&
//                     (parent->children[i]->row == 1 || parent->children[i]->row == 6 ))
//                 )
//        {
//            WinValue *= 0.8;
//        }
        //it is not good to put in the four places
        else if( (parent->children[i]->row == 1 || parent->children[i]->row == 6) &&
                (parent->children[i]->col == 1 || parent->children[i]->col == 6 )){
            WinValue *= 0.8;
        }

        if(WinValue > MaxWinValue){
            MaxWinValue = WinValue;
            BestIndex = i;
        }
    }

    play(parent->children[BestIndex]->row, parent->children[BestIndex]->col);
}

//play from the root to node
void Reversi::PlayTree(Reversi & board ,TreeNode *node){
    std::vector<TreeNode*> plays;
    while(node->parent){
        plays.push_back(node);
        node = node->parent;
    }
    for(std::vector<TreeNode*>::reverse_iterator it = plays.rbegin(); it!=plays.rend();it++){
        board.play((*it)->row, (*it)->col);
    }

}


//judge whether the root is expandable
bool Reversi::isExpandable(TreeNode * root){
    int cnt = 0;
    for(int i =0;i<8;i++){
        for(int j =0;j<8;j++){
            if(judge(curPlayer, i, j))
                cnt++;
        }
    }
    //if the possible ways are more than the number of children, expandable
    if(root->children.size() < cnt){
        return 1;
    }
    return 0;

}

//expand the node
TreeNode * Reversi::Expand(TreeNode * root){

    TreeNode * newnode = new TreeNode(root->MyColor, curPlayer);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(judge(newnode->WhosTurn, i, j)){
                bool AlreadyHas = 0;
                for(int k=0;k<root->children.size();k++){
                    if(root->children[k]->row == i && root->children[k]->col == j){
                        AlreadyHas = 1;
                    }
                }
                //find a new node to insert into the children
                if(!AlreadyHas){
                    newnode->row=i;
                    newnode->col=j;
                    root->children.push_back(newnode);
                    newnode->parent = root;
                    return newnode;
                }
            }
        }
    }
    return NULL;
}

//a function for debug
void Reversi::print(){
    cout<<"---------------"<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]>0){
                cout<<"B ";
            }else if(board[i][j]<0){
                cout<<"W ";
            }else{
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"---------------"<<endl;
}
