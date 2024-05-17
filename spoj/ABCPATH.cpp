// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

int helper(int i, int j, char ch, int x, int y, vector<string>& grid,vector<vector<int>>&dp) {
    if (i < 0 || j < 0 || i >= x || j >= y || grid[i][j] != ch)
        return 0;
        
    if(dp[i][j]!=-1) return dp[i][j];
    
    int arr[8][2] = {
        {i + 1, j + 1},
        {i + 1, j},
        {i, j + 1},
        {i, j - 1},
        {i - 1, j - 1},
        {i - 1, j},
        {i - 1, j + 1},
        {i + 1, j - 1}};
    int maxi = 0;
    for (int k = 0; k < 8; k++) {
        int next_x = arr[k][0];
        int next_y = arr[k][1];

        int len = helper(next_x, next_y, ch + 1, x, y, grid,dp);
        if (len > maxi)
            maxi = len;
    }
    dp[i][j] = maxi+1;
    return 1 + maxi;
}


int main() {
    int cnt=1;
    while(true)
    {
        int W,H;
        cin>>H>>W;
         
        if(W==0 && H==0) break;
        
        vector<string>grid;
        vector<vector<int>>dp(H,vector<int>(W,-1));
        for(int i=0;i<H;i++)
        {
            string temp;
            cin>>temp;
            grid.push_back(temp);
        }
        
        int maxi=0;
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
               int temp = max(maxi,helper(i,j,'A',H,W,grid,dp)) ;
               maxi=max(maxi,temp);
            }
        }
        cout<<"Case "<<cnt << ": "<< maxi<<endl;
        cnt++;
    }
    return 0;
}