1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n=s.length();
5        unordered_map<char,int>mp;
6        int st=0;int maxLen=0;
7
8        for(int en=0;en<n;en++)
9        {
10            mp[s[en]]++;
11
12            while(st<=en && mp[s[en]]>1)
13            {
14                mp[s[st]]--;
15                if(mp[s[st]]==0) mp.erase(s[st]);
16                st++;
17            }
18            maxLen=max(maxLen,en-st+1);
19        }
20        return maxLen;
21    }
22};