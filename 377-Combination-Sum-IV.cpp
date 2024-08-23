class Solution {
    int helper(vector<int>&nums,int k,vector<int>&dp)
    {
        if(k==0) return 1;
        if(k<0) return 0;

        if(dp[k]!=-1) return dp[k];

        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt += helper(nums,k-nums[i],dp);
        }
        return dp[k] = cnt;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return helper(nums,target,dp);
    }
};