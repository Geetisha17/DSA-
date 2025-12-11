1class Solution {
2    int helper(int i,int j,bool flag,vector<int>&nums,vector<vector<int>>&dp)
3    {
4        if(i>j) return 0;
5        if(dp[i][j]!=-1) return dp[i][j];
6
7        int res=(flag)?INT_MIN:INT_MIN;
8
9        if(flag)
10        {
11            res = max(nums[i]+helper(i+1,j,false,nums,dp),
12                    nums[j]+helper(i,j-1,false,nums,dp));
13        }
14        else
15        {
16            res = min(helper(i+1,j,true,nums,dp),
17                    helper(i,j-1,true,nums,dp));
18        }
19        return dp[i][j]= res;
20    }
21public:
22    bool predictTheWinner(vector<int>& nums) {
23        int n=nums.size();
24        vector<vector<int>>dp(n,vector<int>(n+1,-1));
25        int tol = accumulate(nums.begin(),nums.end(),0);
26        int playO= helper(0,n-1,true,nums,dp);
27        int rem = tol-playO;
28
29        return (playO>=rem);
30    }
31};