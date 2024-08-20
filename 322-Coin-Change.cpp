class Solution {
    int helper(int i,vector<int>&coins,int k,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if((k%coins[0]==0)) return k/coins[0];
            else return 0;
        }

        if(dp[i][k]!=-1) return dp[i][k];

        int nt = helper(i-1,coins,k,dp);
        int tk=0;
        if(coins[i]<=k)
        tk = 1 + helper(i,coins,k-coins[i],dp);

        return dp[i][k] = min(tk,nt);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount,-1));
        return helper(n-1,coins,amount,dp);
    }
};