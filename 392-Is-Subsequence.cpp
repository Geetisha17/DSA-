class Solution {
    bool helper(int i,int j,string s,string t,vector<vector<int>>&dp)
    {
        if(i<=0)
        return true;
        if(j<=0)
        return false;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1] == t[j-1]) return dp[i][j]= helper(i-1,j-1,s,t,dp);
        else
        return dp[i][j] = helper(i,j-1,s,t,dp);
    }
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0) return true;
        if(t.length()==0) return false;
        int n=s.length();
        int m=t.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n,m,s,t,dp);
    }
};