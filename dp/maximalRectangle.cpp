#include<bits/stdc++.h>
using namespace std;

class Solution {
    int largetRectanglt(vector<int>&nums)
    {
        int n=nums.size();
        stack<int>st;
        int maxi=0;

        for(int i=0;i<=n;i++)
        {
           while(!st.empty() && (i==n || nums[st.top()] >= nums[i]))
           {
            int h = nums[st.top()];st.pop();
            int w;

            if(st.empty()) w=i;
            else w = (i-st.top()-1);
            maxi = max(maxi,h*w);
           }
           st.push(i);
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<int>dp(m,0);
        int maxi=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(nums[i][j]=='1') dp[j]++;
                else dp[j]=0;
            }
            int area = largetRectanglt(dp);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};