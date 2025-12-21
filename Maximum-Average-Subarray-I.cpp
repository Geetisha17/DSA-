1class Solution {
2public:
3    double findMaxAverage(vector<int>& nums, int k) {
4        int n=nums.size();
5        int st=0; double sum=0;
6        double ans=INT_MIN;
7
8        for(int en=0;en<n;en++)
9        {
10            sum+=nums[en];
11
12            if(st<=en && (en-st+1)>k)
13            {
14                sum-=nums[st++];
15            }
16            if((en-st+1)==k)
17            ans = max(ans,(double)(sum/k));
18        }
19        return ans;
20    }
21};