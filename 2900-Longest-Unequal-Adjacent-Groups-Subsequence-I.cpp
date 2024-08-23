class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>dp(n+1,0);
        vector<int>len(n+1,-1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(groups[i] != groups[j] && 1+dp[j] > dp[i])
                {
                    dp[i] = 1+dp[j];
                    len[i] = j;
                }
            }
        }
        int maxi = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i] > dp[maxi]) {
                maxi = i;
            }
        }
        
        vector<string> ans;
        while (maxi != -1) {
            ans.push_back(words[maxi]);
            maxi = len[maxi];
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};