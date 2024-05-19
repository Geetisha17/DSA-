#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        vector<int>nums(arr,arr+n);
        int tol = accumulate(nums.begin(),nums.end(),0);
        
        if(tol%2==1) return 0;
        
        tol=tol/2;
        
        vector<vector<int>>dp(n,vector<int>(tol+1,0));
        
        for(int i=0;i<n;i++)
        dp[i][0] = 1;
        
        for(int i=1;i<n;i++)
        {
            for(int k=0;k<=tol;k++)
            {
                int take = dp[i-1][k];
                int notTake=0;
                if(nums[i]<=k)
                notTake = dp[i-1][k-nums[i]];
                
                dp[i][k] = take || notTake;
            }
        }
        int res = dp[n-1][tol];
        
        if(res) return 1;
        return 0;
    }
};