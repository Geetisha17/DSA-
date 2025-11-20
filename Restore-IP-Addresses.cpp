class Solution {
    void helper(int i,int part,string temp,vector<string>&ans,string &s)
    {
        if(i>=s.length() && part==4)
        {
            ans.push_back(temp);
            return;
        }

        string res="";
        for(int j=i;j<s.length();j++)
        {
            res+=s[j];
            if(res.length()>3) break;
            if(res[0]=='0' && res.length()>1) break;

            if(stoi(res)<=255)
            {
                if(part<3)
                helper(j+1,part+1,temp+res+".",ans,s);
                else
                helper(j+1,part+1,temp+res,ans,s);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        helper(0,0,"",ans,s);
        return ans;
    }
};