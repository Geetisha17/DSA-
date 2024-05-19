#include<bits/stdc++.h>
using namespace std;

class Solution {
    int helper(int i,int j,vector<vector<int>>&dp,string &s,string &t)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = helper(i-1,j-1,dp,s,t);
        int mini = INT_MAX;
            mini = min(1+helper(i-1,j-1,dp,s,t) , min(1+helper(i-1,j,dp,s,t) , 1+helper(i,j-1,dp,s,t)));
        
        
        return dp[i][j] = mini;
    }
  public:
    int editDistance(string s, string t) {
        // Code here
        int n=s.length();
        int m=t.length();
        vector<int>prev(m+1,0);
        
        for(int j=0;j<=m;j++)
        prev[j] = j;
        
        for(int i=1;i<=n;i++)
        {
            vector<int>curr(m+1,0);
            curr[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1]) curr[j] = prev[j-1];
                else
                curr[j] = min(1+prev[j-1] , min(1+prev[j] , 1+curr[j-1]));
            }
            prev=curr;
        }
        
        return prev[m];
    }
};