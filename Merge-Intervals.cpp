1class Solution {
2    static bool cmp(vector<int>&a,vector<int>&b)
3    {
4        if(a[0]==b[0]) return a[1]<b[1];
5        return a[0]<b[0];
6    }
7public:
8    vector<vector<int>> merge(vector<vector<int>>& intervals) {
9        vector<vector<int>>ans;
10        int n=intervals.size();
11        sort(intervals.begin(),intervals.end(),cmp);        
12
13        for(int i=0;i<n;i++)
14        {
15            if(ans.empty())
16                ans.push_back(intervals[i]);
17            else
18            {
19                if(ans.back()[1] >= intervals[i][0])
20                {
21                    int mini=min(ans.back()[0],intervals[i][0]);
22                    int maxi=max(ans.back()[1],intervals[i][1]);
23
24                    ans.pop_back();
25                    ans.push_back({mini,maxi});
26                }
27                else
28                    ans.push_back(intervals[i]);
29            }
30        }
31        return ans;
32    }
33};