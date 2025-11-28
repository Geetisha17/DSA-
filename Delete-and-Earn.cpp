1class Solution {
2    int helper(int i,vector<int>&temp,vector<int>&freq,vector<int>&dp)
3    {
4        if(i==0) return freq[0]*temp[0];
5        if(i<0) return 0;
6        if(dp[i]!=-1) return dp[i];
7
8        int tk=0;
9        if(temp[i-1]+1 == temp[i])
10            tk = freq[i]*temp[i] + helper(i-2,temp,freq,dp);
11        else
12            tk = freq[i]*temp[i] + helper(i-1,temp,freq,dp);
13        int nt = helper(i-1,temp,freq,dp);
14
15        return dp[i]= max(nt,tk);
16    }
17public:
18    int deleteAndEarn(vector<int>& nums) {
19        int n=nums.size();
20        map<int,int>mp;
21        for(auto it:nums)
22            mp[it]++;
23        
24        vector<int>temp;vector<int>freq;
25        for(auto it:mp)
26        {
27            temp.push_back(it.first);
28            freq.push_back(it.second);
29        }
30        vector<int>dp(temp.size()+1,-1);
31        return helper(temp.size()-1,temp,freq,dp);
32    }
33};