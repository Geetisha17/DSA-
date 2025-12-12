1class Solution {
2    int helper(int i,int j,string &s,string &t,vector<vector<int>>&dp)
3    {
4        if(i<0 || j<0) return 0;
5        if(dp[i][j]!=-1) return dp[i][j];
6        if(s[i]==t[j]) return dp[i][j]= 1+helper(i-1,j-1,s,t,dp);
7        return dp[i][j] =max(helper(i-1,j,s,t,dp) , helper(i,j-1,s,t,dp));
8    }
9public:
10    int minDistance(string s, string t) {
11        int n=s.length();int m=t.length();
12        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
13        int res= helper(n-1,m-1,s,t,dp);
14        return (n+m)- (2*res);
15    }
16};