1class Solution {
2    static bool cmp(vector<int>&a,vector<int>&b)
3    {
4        if(a[0]==b[0]) return a[1]<b[1];
5        return a[0]<b[0];
6    }
7public:
8    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
9        int n=intervals.size();
10        if(n==1) return 0;
11        sort(intervals.begin(),intervals.end(),cmp);
12        int cnt=0;
13        int prev=0;
14
15        for(int i=1;i<n;i++)
16        {
17            if(intervals[prev][1]>intervals[i][0])
18            {
19                if(intervals[prev][1]>intervals[i][1])
20                    prev=i;
21                cnt++;
22            }
23            else prev=i;
24        }
25        return cnt;
26    }
27};