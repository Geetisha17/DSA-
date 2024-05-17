#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printNQueen(int n,int board[][20]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool canPlace(int board[][20],int n ,int x,int y){
    
    for(int k=0;k<x;k++){
        if(board[k][y]==1){
            return false;
        }
    }

    int i=x,j=y;
    while(i>=0 && j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }

    i=x,j=y;
    while(i>=0 && j<n){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

int solveNQueen(int n,int board[][20],int i){
    //base case
    if(i==n){
        //print the board
        //printNQueen(n,board);
        return 1;
    }
    //rec case
    //placing queen in each coloum
    int ways=0;
    for(int j=0;j<n;j++){
       if(canPlace(board,n,i,j)){
        board[i][j]=1;
        ways+= solveNQueen(n,board,i+1);
        
        //backtrack
        board[i][j]=0;
       }
    }
    return ways;
}

bool isSafe(int i,int j,vector<string> &board,int n){
    int x=i;
    int y=j;

    while(y>=0){
        if(board[x][y]=='Q'){
            return false;
        }
        y--;
    }
    x=i;
    y=j;
    while(x>=0 && y>=0){
        if(board[x][y]=='Q'){
            return false;
        }
        x--;
        y--;
    }

    x=i;
    y=j;

    while(x<n && y>=0){
        if(board[x][y]=='Q'){
            return false;
        }
        x++;
        y--;
    }
    return true;
}

void canSolve(vector<vector<string>> &ans,vector<string> &board,int j,int n){
    //base case
    if(j==n){
        ans.push_back(board);
        return;
    }

    for(int i=0;i<n;i++){

        if(isSafe(i,j,board,n)){
            board[i][j]='Q';
            canSolve(ans,board,j+1,n);

            //backtracking
            board[i][j]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');

    for(int i=0;i<n;i++){
        board[i]=s;
    }
    canSolve(ans,board,0,n);
    return ans;
}

int main(){
    int board[20][20]={0};
    int n;
    cin>>n;
    cout<<"ways "<<solveNQueen(n,board,0);

    return 0;
}