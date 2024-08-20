class Solution {
    int helper(int n,vector<int>&dp)
    {
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n];

        int mini=1e9;
        for(int i=0; i<n; i++)
        {
            int res = 1 + helper(n-i*i,dp);
            mini = min(mini,res);
        }
        return dp[n]=mini;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};