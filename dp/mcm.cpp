#include<bits/stdc++.h>
using namespace std;

class Solution{
    int helper(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int res = nums[i-1]*nums[k]*nums[j] + helper(i,k,nums,dp) + helper(k+1,j,nums,dp);
            mini=min(mini,res);
        }
        
        return dp[i][j] = mini;
    }    
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<int> nums(arr, arr + n);
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        dp[i][i] =0;
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int mini = 1e9;
                for(int k=i;k<j;k++)
                {
                    mini = min(mini , (nums[i-1] *nums[k]*nums[j]) + dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};