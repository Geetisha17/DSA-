1class Solution {
2    int helper(int i,int A,vector<vector<int>>&costs,vector<vector<int>>&dp)
3    {
4        int n=costs.size();
5        if(i>=n) return 0;
6        if(dp[i][A]!=-1) return dp[i][A];
7        int ans=1e9;
8        int B=i-A;
9
10        if(A<(n/2))
11            ans = min(ans,costs[i][0]+helper(i+1,A+1,costs,dp));
12        
13        if(B<(n/2))
14            ans=min(ans,costs[i][1]+helper(i+1,A,costs,dp));
15        
16        return dp[i][A]= ans;
17    }
18public:
19    int twoCitySchedCost(vector<vector<int>>& costs) {
20        int n=costs.size();
21        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
22        return helper(0,0,costs,dp);
23    }
24};