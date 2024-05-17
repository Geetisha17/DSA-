#include<iostream>
#include<vector>
using namespace std;

int isValidSudoku(char** board, int boardRowSize, int boardColSize) 
{
    int row[9][9];  //row[5][0] means whether number 1('0'+1) in row 5 has appeared.
    int col[9][9];  //col[3][8] means whether number 9('8'+1) in col 3 has appeared
    int block[3][3][9]; //blocks[0][2][5] means whether number '6' in block 0,2 (row 0~2,col 6~8) has appeared.

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                int number = board[i][j]-'1'; //calculate the number's index(board's number minus 1)

                if(row[i][number]++) return 0;
                if(col[j][number]++) return 0;//if the number has already appeared once, return false.
                if(block[i/3][j/3][number]++) return 0;
            }
        }
    }
    return true;
}