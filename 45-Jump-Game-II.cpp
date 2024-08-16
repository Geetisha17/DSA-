class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;

        vector<int> dp(n, INT_MAX);
        dp[0]=0; 

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MAX) continue; 

            for (int j = i + 1; j < n && j <= i + nums[i]; ++j) {
                dp[j] = min(dp[j], dp[i]+1);
            }
        }

        return dp[n-1];
    }
};