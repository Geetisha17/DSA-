#include<iostream>
#include<vector>
using namespace std;

 vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n , vector<int> (n));
	int val=0;
	int start_row=0;
	int start_col=0;
	int end_col = n-1;
	int end_row = n-1;

	while(start_row<=end_row && start_col<=end_col){
		
		for(int j=start_col;j<=end_col;j++){
			ans[start_row][j]=++val;
		}
		for(int i=start_row+1;i<=end_row;i++){
			ans[i][end_col]=++val;
		}
		for(int j=end_col-1;j>=start_col;j--){
			if(start_row==end_row) break;
			ans[end_row][j]=++val;
		}
		for(int i=end_row-1;i>=start_row+1;i--){
			if(start_col==end_col) break;
			ans[i][start_col]=++val;
		}
		start_row++;
		end_row--;
		start_col++;
		end_col--;
	}
	return ans;
    }