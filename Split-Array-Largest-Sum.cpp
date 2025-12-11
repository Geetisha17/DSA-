1class Solution {
2    bool helper(vector<int>&nums,long long mid,int k)
3    {
4        long long sum=0;int splits=1;
5        int n=nums.size();
6        for(int i=0;i<n;i++)
7        {
8            if(sum+nums[i]<=mid)
9                sum+=nums[i];
10            
11            else
12            {
13                splits++;
14                sum=nums[i];
15            }
16            if(splits>k) return false;
17        }
18        return true;
19    }
20public:
21    int splitArray(vector<int>& nums, int k) {
22        int n=nums.size();
23        long long low=*max_element(nums.begin(),nums.end());
24        long long high=accumulate(nums.begin(),nums.end(),0);
25
26        int ans=0;
27        while(low<=high)
28        {
29            long long mid = (low+high)/2;
30            if(helper(nums,mid,k))
31            {
32                ans=mid;
33                high=mid-1;
34            }
35            else
36            {
37                low=mid+1;
38            }
39        }
40        return ans;
41    }
42};