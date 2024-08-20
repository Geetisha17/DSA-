class Solution {
    int helper(int i,vector<int>&nums,int buy,vector<vector<int>>&dp)
    {
        // if(i==0) return nums[0];
        if(i>=nums.size()-1) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy)
        {
            profit = max(nums[i] + helper(i+1,nums,0,dp) , helper(i+1,nums,1,dp));
        }
        else{
            profit = max(-nums[i] + helper(i+2,nums,1,dp) , helper(i+1,nums,0,dp));
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<int>dp(n+1,-1);
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,prices,1,dp);
    }
};