#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
class Solution{
    int helper(int n,int r,vector<vector<int>>&dp)
    {
        if(r==0 || r==n) return 1;
    
    if(dp[n][r]!=-1) return dp[n][r];
    
    return dp[n][r] = (helper(n-1,r-1,dp) + helper(n-1,r,dp))%mod;
    }
public:
    int nCr(int n, int r){
        if(r>n) return 0;
        vector<int>prev(n+1,0);
        
        prev[0]=1;
        for(int i=1;i<=n;i++)
        {
            vector<int>curr(n+1,0);
            curr[0]=1;
            for(int j=1;j<=r;j++)
            {
                curr[j] = (prev[j-1] + prev[j])%mod;
            }
            prev=curr;
        }
        return (prev[r]);
    }
};