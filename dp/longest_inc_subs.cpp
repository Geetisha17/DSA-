#include <bits/stdc++.h> 
using namespace std;

int helper(int idx,int prev,int n,int arr[],vector<vector<int>>&dp)
{
    if(idx==n) return 0;

    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

    int notTake = helper(idx+1,prev,n,arr,dp);
    int take =0;
    if(prev==-1 || arr[idx] > arr[prev])
    take = 1 + helper(idx+1,idx,n,arr,dp);

    return dp[idx][prev+1]= max(take,notTake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return helper(0,-1,n,arr,dp);
}   