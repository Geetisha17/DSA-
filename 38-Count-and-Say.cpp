class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return \1\;
        
        int cnt=1;
        string prev = countAndSay(n-1);
        string ans=\\;

        for(int i=1;i<prev.size();i++)
        {
            if(prev[i] == prev[i-1])
            {
                cnt++;
            }
            else{
                ans += to_string(cnt) + prev[i-1];
                cnt=1;
            }
        }
        if(cnt>0)
        ans += to_string(cnt) + prev.back();

        return ans;
    }
};