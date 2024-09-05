class Solution {
    int helper(int i,vector<int>&days,vector<int>&cost,vector<int>&dp)
    {
        if(i>=days.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        int x=cost[0]+helper(i+1,days,cost,dp);
        int j=i;
        while(j<days.size() && days[j]<days[i]+7)
        j++;

        int y = cost[1] + helper(j,days,cost,dp);

        j=i;
        while(j<days.size() && days[j]<days[i]+30)
        j++;

        int z=cost[2]+helper(j,days,cost,dp);

        return dp[i] = min(x,min(y,z));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        sort(days.begin(),days.end());
        vector<int>dp(n+1,-1);
        return helper(0,days,cost,dp);
    }
};