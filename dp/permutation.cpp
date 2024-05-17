#include <bits/stdc++.h>
using namespace std;

int per(int n,int k,vector<vector<int>>&dp)
{
    if(k==0 ) return 1;
    if(k>n) return 0;
    
    if(dp[n][k]!=-1) return dp[n][k];
    
    return dp[n][k] = per(n-1,k,dp) + k*per(n-1,k-1,dp);
}

int main() {
    int n=10;int r=2;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
    for(int i=0;i<n;i++)
    dp[i][0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=r;j++)
        {
            dp[i][j] = dp[i-1][j] + j*dp[i-1][j];
        }
    }
    cout<<dp[n][r];

    return 0;
}