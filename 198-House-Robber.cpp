class Solution {
    int helper(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i==0) return nums[i];

        if(dp[i]!=-1) return dp[i];

        int nt = helper(i-1,nums,dp);
        int tk=0;
        if(i-2>=0)
        tk = nums[i]+ helper(i-2,nums,dp); 

        return dp[i] = max(nt,tk);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return helper(n-1,nums,dp);
    }
};