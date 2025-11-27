1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int st=0;
5        int en=nums.size()-1;
6
7        while(st<=en)
8        {
9            int mid = (st+en)/2;
10            if(nums[mid]==target) return mid;
11
12            if(nums[st]<=nums[mid])
13            {
14                if(target>=nums[st] && target<=nums[mid])
15                    en=mid-1;
16                else
17                    st=mid+1;
18            }
19            else
20            {
21                if(target>=nums[mid] && target<=nums[en])
22                    st=mid+1;
23                else
24                    en=mid-1;
25            }
26        }
27        return -1;
28    }
29};