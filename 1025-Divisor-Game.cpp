class Solution {
    int helper(int idx,vector<int>& days, vector<int>& cost,vector<int>&dp)
    {
        if(idx>=days.size())
        {
            return 0;
        }

        if(dp[idx]!=-1) return dp[idx];
        int i;
        int op1 = cost[0] + helper(idx+1,days,cost,dp);

        for(i=idx;i<days.size() && days[i]<days[idx]+7;i++);
        int op2 = cost[1]  + helper(i,days,cost,dp);

        for(i=idx;i<days.size() && days[i]<days[idx]+30;i++);
        int op3 = cost[2]  + helper(i,days,cost,dp);

        return dp[idx] = min(op1,min(op2,op3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size()-1;
        vector<int>dp(n+1,-1);
        return helper(0,days,costs,dp);
    }
};