class Solution {
    void helper(vector<string>&ans,int open,int close,int n,string s)
    {
        if(open==n && close==n)
        {
            ans.push_back(s);
            return;
        }

        if(open<n) 
        {
            s.push_back('(');
            helper(ans,open+1,close,n,s);
            s.pop_back();
        }
        if(close<open) {
            s.push_back(')');
            helper(ans,open,close+1,n,s);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        helper(ans,0,0,n,\\);
        return ans;
    }
};