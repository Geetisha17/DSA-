1class Solution {
2public:
3    bool checkSubarraySum(vector<int>& nums, int k) {
4        int n=nums.size();
5        unordered_map<int,int>mp;mp[0]=-1;
6        int st=0;int sum=0;
7
8        for(int en=0;en<n;en++)
9        {
10            sum+=nums[en];
11            
12            if(mp.find(sum%k)!=mp.end())
13            {
14                if(en-mp[sum%k]>1)
15                return true;
16            }
17            if(mp.find(sum%k)==mp.end())
18            mp[sum%k]=en;
19        }
20        return false;
21    }
22};