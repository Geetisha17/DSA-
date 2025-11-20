class Solution {
    void helper(int i,string &s,string temp,vector<string>&ans)
    {
        if(i>=s.length())
        {
            ans.push_back(temp);
            return;
        }

        helper(i+1,s,temp+s[i],ans);

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            if(islower(s[i])) 
            helper(i+1, s, temp + char(toupper(s[i])), ans);
            else if(isupper(s[i]))
            helper(i+1, s, temp + char(tolower(s[i])), ans);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        helper(0,s,"",ans);
        return ans;
    }
};