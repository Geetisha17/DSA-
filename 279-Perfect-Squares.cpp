class Solution {
    int helper(int n,vector<int>&dp)
    {
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n];

        int mini=INT_MAX;
        for(int j=1;j*j<=n;j++)
        {
            int a = 1 + helper(n-(j*j),dp);
            mini = min(mini,a);
        }

        return dp[n] = mini;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};