class Solution {
    bool isPali(string s,int st,int en)
    {
        while(st<=en)
            if(s[st++]!=s[en--]) return false;
        return true;
    }
    void helper(int i,vector<string>&temp,vector<vector<string>>&ans,string &s)
    {
        if(i>=s.length())
        {
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<s.length();j++)
        {
            if(isPali(s,i,j))
            {
                temp.push_back(s.substr(i,j-i+1));
                helper(j+1,temp,ans,s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        helper(0,temp,ans,s);
        return ans;
    }
};