#include<bits/stdc++.h>
using namespace std;

class Solution
{
    
    // int mod=1e9+7;
    // int helper(int i,vector<int>&dp)
    // {
    //     if(i<=2) return dp[i] = i;
        
    //     if(dp[i]!=-1) return dp[i];
        
    //     int single = (helper(i-1,dp))%mod;
    //     int notsingle = ((i-1)*helper(i-2,dp))%mod;
        
    //     return dp[i] = (single + notsingle)%mod;
    // }
public:
int mod=1e9+7;
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<int>dp(n+1,0);
        dp[1]=1;dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            dp[i] = (dp[i-1]%mod + (dp[i-2]*(long long)(i-1))%mod)%mod;
        }
        return dp[n];
    }
};