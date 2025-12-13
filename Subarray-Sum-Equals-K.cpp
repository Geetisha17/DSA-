1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int n=nums.size();
5        unordered_map<int,int>mp;mp[0]=1;
6        int numSubarray=0,sum=0;
7        
8        for(int i=0;i<n;i++)
9        {
10            sum+=nums[i];
11            if(mp.find(sum-k)!=mp.end())
12                numSubarray+=mp[sum-k];
13            
14            mp[sum]++;
15        }
16        return numSubarray;
17    }
18};