1class Solution {
2public:
3    string minWindow(string s, string t) {
4        unordered_map<char,int>mp;
5        for(auto it:t) mp[it]++;
6
7        int n=s.length();
8        int st=0;int minLen=1e9;int idx=-1;
9        unordered_map<char,int>freq;int cnt=0;
10
11        for(int en=0;en<n;en++)
12        {
13            if(mp[s[en]]>0)
14            {
15                freq[s[en]]++;
16                if(freq[s[en]]<=mp[s[en]]) cnt++;
17            }
18
19            while(st<=en && cnt==t.length())
20            {
21                if(minLen > (en-st+1))
22                {
23                    minLen=(en-st+1);
24                    idx=st;
25                }
26                if(mp[s[st]]>0)
27                {
28                    if(freq[s[st]]<=mp[s[st]]) cnt--;
29                    freq[s[st]]--;
30                }
31                st++;
32            }
33        }
34        if(idx==-1) return "";
35        return s.substr(idx,minLen);
36    }
37};