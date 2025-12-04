1class Solution {
2    static bool cmp(vector<int>&a,vector<int>&b)
3    {
4        if(a[1]==b[1]) return a[0]<b[0];
5        return a[1]<b[1];
6    }
7public:
8    int findMinArrowShots(vector<vector<int>>& points) {
9        int n=points.size();
10        if(n==1) return 1;
11        sort(points.begin(),points.end(),cmp);
12        int cnt=n;
13        int prev=0;
14
15        for(int i=1;i<n;i++)
16        {
17            if(points[prev][1] >= points[i][0])
18            {
19                cnt--;
20            }
21            else prev=i;
22        }
23        return cnt;
24    }
25};