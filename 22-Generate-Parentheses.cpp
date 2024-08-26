class Solution {
    void helper(int n,int op,int cl,vector<string>&ans,string temp)
    {
        if(op == n && cl == n)
        {
            ans.push_back(temp);
            return;
        }
        if(op<n)
        helper(n,op+1,cl,ans,temp+\(\);
        if(cl<op)
        helper(n,op,cl+1,ans,temp+\)\);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(n,0,0,ans,\\);
        return ans;
    }
};