class Solution {
    bool helper(int i,string s,unordered_set<string>st,vector<int>&dp)
    {
        if(i==s.length()) return 1;

        if(dp[i]!=-1) return dp[i];

        string temp=\\;
        for(int j=i;j<s.length();j++)
        {
            temp+=s[j];
            if(helper(j+1,s,st,dp) && st.find(temp) != st.end())
            return dp[i] = true;
        }   
        return dp[i]  = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<int>dp(n+1,-1);
        return helper(0,s,st,dp);
    }
};