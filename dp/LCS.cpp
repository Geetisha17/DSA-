#include<bits/stdc++.h>
using namespace std;

int helper(int i,int j,vector<vector<int>>&dp,string s,string t)
    {
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = 1+helper(i-1,j-1,dp,s,t);
        
        return dp[i][j] = max(helper(i-1,j,dp,s,t),helper(i,j-1,dp,s,t));
    }
    int lcs(int n, int m, string s, string t)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)
        dp[i][0]=0;
        
        for(int j=0;j<=m;j++)
        dp[0][j]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][m];
    }