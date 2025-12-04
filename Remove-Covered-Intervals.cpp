1class Solution {
2    static bool cmp(vector<int>&a,vector<int>&b)
3    {
4        if(a[0]==b[0]) return a[1]>b[1];
5        return a[0]<b[0];
6    }
7public:
8    int removeCoveredIntervals(vector<vector<int>>& nums) {
9        int n=nums.size();
10        sort(nums.begin(),nums.end(),cmp);
11        int prev=0;
12        int cnt=n;
13
14        for(int i=1;i<n;i++)
15        {
16            if(nums[prev][1] >= nums[i][1])
17                cnt-=1;
18            
19            else prev=i;
20        }
21        return cnt;
22    }
23};