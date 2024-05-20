#include<bits/stdc++.h>
using namespace std;

int helper(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&nums,int n,int m)
    {
        if(i==n-1 && j==m-1) return nums[i][j];
        
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int maxi = 0;
        int diaup = nums[i][j]+ helper(i-1,j+1,dp,nums,n,m);
        int right = nums[i][j]+ helper(i,j+1,dp,nums,n,m);
        int diadown = nums[i][j]+ helper(i+1,j+1,dp,nums,n,m);
        
        maxi  = max(maxi, max(diaup,max(right,diadown)));
        return dp[i][j] = maxi;
    }
    int maxGold(int n, int m, vector<vector<int>> nums)
    {
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int right = (j == m - 1) ? 0 : dp[i][j + 1]; 
                int diaUp = (i == 0 || j == m - 1) ? 0 : dp[i - 1][j + 1]; 
                int diaDown = (i == n - 1 || j == m - 1) ? 0 : dp[i + 1][j + 1]; 

                dp[i][j] = nums[i][j] + max(right, max(diaUp, diaDown));
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi , dp[i][0]);
        }
        return maxi;
    }