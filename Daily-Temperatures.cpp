1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>&nums) {
4        int n=nums.size();
5        stack<pair<int,int>>st;vector<int>ans(n);
6
7        for(int i=n-1;i>=0;i--)
8        {
9            int cnt=0;
10            while(!st.empty() && st.top().first<=nums[i])
11            {
12                cnt+=st.top().second;
13                st.pop();
14            }
15            if(st.empty()) ans[i]=0;
16            else ans[i] = cnt+1;
17
18            if(st.empty()) st.push({nums[i],1});
19            else st.push({nums[i],1+cnt});
20
21        }
22        return ans;
23    }
24};