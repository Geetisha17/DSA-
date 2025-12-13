1class Solution {
2    int helper(vector<int>&nums,int k)
3    {
4        int n=nums.size();
5        int st=0;int cntOdd=0;
6        int ans=0;
7
8        for(int en=0;en<n;en++)
9        {
10            if(nums[en]%2==1) cntOdd++;
11            while(st<=en && cntOdd>k)
12            {
13                if(nums[st]%2==1) cntOdd--;
14                st++;
15            }
16            ans+=(en-st+1);
17        }
18        return ans;
19    }
20public:
21    int numberOfSubarrays(vector<int>& nums, int k) {
22        return helper(nums,k)-helper(nums,k-1);
23    }
24};