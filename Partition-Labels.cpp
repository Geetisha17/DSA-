1class Solution {
2    bool static cmp(const pair<int,int>&a,const pair<int,int>&b)
3    {
4        if(a.first == b.first) return a.second<b.second;
5        return a.first < b.first;
6    }
7public:
8    vector<int> partitionLabels(string s) {
9        vector<int>ans;
10        vector<pair<int,int>>mp(26,{-1,-1});
11
12        for(int i=0;i<s.length();i++)
13        {
14            int idx=s[i]-'a';
15            if(mp[idx].first==-1)
16                mp[idx].first=i;
17            mp[idx].second=i;
18        }
19
20        sort(mp.begin(),mp.end(),cmp);
21        int maxRange=-1;int res=0;int minRange=1e9;
22        for(auto it:mp)
23        {
24            if(it.first==-1) continue;
25
26            if(minRange==1e9)
27            {
28                maxRange=it.second;
29                minRange=it.first;
30            }
31            else if(it.first > maxRange)
32            {
33                ans.push_back(maxRange-minRange+1);
34                minRange=it.first;maxRange=it.second;
35            }
36            else
37            {
38                maxRange = max(maxRange,it.second);
39                minRange = min(minRange,it.first);
40            }
41        }
42
43        if(minRange!=-1)
44            ans.push_back(maxRange-minRange+1);
45        return ans;
46    }
47};