#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int mod = 1e9+7;
    long long helper(vector<int>&dp,int n)
    {
        if (n <= 1)
        return 1;
        
        if(dp[n]!=-1) return dp[n];
 
    long long res = 0;
    for (int i = 0; i < n; i++)
        res = (res + (helper(dp,i)%mod) * (helper(dp,n - i - 1)%mod))%mod;
 
    return dp[n]=res%mod;
    }
    int findCatalan(int n) 
    {
    vector<long long>dp(n+1,0);
    
    dp[0]=dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i] = (dp[i] + (dp[j] * dp[i-j-1])%mod)%mod;
        }
    }
    return (int)dp[n];
    }
};    