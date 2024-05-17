#include <iostream>
#include<vector>
using namespace std;

bool isSafe(int mat[][9],int i,int j,int no,int n){
   //check for row and coloum
	for(int k=1;k<=9;k++){
		if(mat[k][j]==no || mat[i][k]==no){
			return false;
		}
	}
	//check for subgrid
	int sx = (i/3)*3;
	int sy = (j/3)*3;

	for(int x=sx;x<sx+3;x++){
		for(int y=sy;y<sy+3;y++){
			if(mat[x][y]==no){
				return false;
			}
		}
	}
	return true;
}

bool sudokuSolver(int mat[][9],int i,int j,int n){
	//base case
	if(i==n){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	//corner case
	if(j==n){
		sudokuSolver(mat,i+1,j,n);
	}
	if(mat[i][j]!=0){
		sudokuSolver(mat,i,j+1,n);
	}
	//rec case
	//filling in the number
	for(int no=1;no<=n;no++){

		if(isSafe(mat,i,j,no,n)){

			mat[i][j]=no;

			bool subProblem = sudokuSolver(mat,i,j+1,n);
			if(subProblem){
				return true;
			}
		}
	}
	mat[i][j]=0;
	return false;
}

bool canSolve(vector<vector<char>> &board,int i,int j,char ch){
	//check for row and col
	for(int k=0;k<9;k++){
		if(board[i][k]==ch || board[k][j]==ch)
			return false;
	}
    //for subgrid
	int sx = (i/3)*3;
	int sy = (j/3)*3;

	for(int x=0;x<3;x++){
		
		for(int y=0;y<3;y++){

			if(board[x+sx][y+sy]==ch)
			return false;
		}
	}
	return true;
}

bool check(vector<vector<char>>&board){
	for(int i=0;i<9;i++){

		for(int j=0;j<9;j++){

			if(board[i][j]=='.'){

				for(char ch='1';ch<='9';ch++){

					if(canSolve(board,i,j,ch)){
						board[i][j]=ch;

					if(check(board))
					return true;
					board[i][j]='.';

					}
				}
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(vector<vector<char>>& board) {
	check(board);
}


int main() {
	// your code goes here
	return 0;
}

