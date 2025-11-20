class Solution {
    void helper(int i,int n,string temp,vector<string>&ans)
    {
        if(i>=n)
        {
            ans.push_back(temp);return;
        }

        helper(i+1,n,temp+"1",ans);
        
        if(temp.size()==0 || temp.back()=='1')
            helper(i+1,n,temp+"0",ans);
        
    }
public:
    vector<string> validStrings(int n) {
        vector<string>ans;
        helper(0,n,"",ans);
        // for(auto it:st) ans.push_back(it);
        return ans;
    }
};