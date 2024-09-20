class Solution {
    int helper(int i,int d,vector<vector<int>>&dp,vector<int>&nums)
    {
        int n=nums.size();
        if (d == 1) {
            int maxi = 0;
            for (int j = i; j < n; ++j) {
                maxi = max(maxi, nums[j]);
            }
            return maxi;
        }

        if(dp[i][d]!=-1) return dp[i][d];

        int mini=INT_MAX;
        int maxi=0;
        for(int j=i;j<=n-d;j++)
        {
            maxi = max(maxi,nums[j]);
            mini = min(mini , maxi + helper(j+1,d-1,dp,nums));
        }
        return dp[i][d]=mini;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return helper(0,d,dp,jobDifficulty);
    }
};