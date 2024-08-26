class Solution {
    bool helper(int i,int j,int k,string s1,string s2,string s3,vector<vector<int>>&dp)
    {
        if(k==0) return true;

        if(i<0 && j<0) return false;

        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];

        bool ans=false;

        if(i>=0 && s1[i]==s3[k-1])
        ans = helper(i-1,j,k-1,s1,s2,s3,dp);

        if(j>=0 && s2[j]==s3[k-1])
        ans = ans || helper(i,j-1,k-1,s1,s2,s3,dp);

        return dp[i+1][j+1]=ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int x=s3.length();

        if(n+m != x) return false;

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(n-1,m-1,x,s1,s2,s3,dp);
    }
};