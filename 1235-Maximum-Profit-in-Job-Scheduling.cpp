class Solution {
    int bs(vector<pair<int,pair<int,int>>>&pt,int x,int n)
    {
        int low=0;int high=n-1;

        while(low<=high)
        {
            int mid = (low+high)/2;
            if(x<=pt[mid].first)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    int helper(int i,int n,vector<pair<int,pair<int,int>>>&pt,vector<int>&dp)
    {
        //base case
        if(i==n)
        return 0;

        if(dp[i]!=-1) return dp[i];

        int sk = helper(i+1,n,pt,dp);
        int enTime = pt[i].second.first; //end time
        int next = bs(pt,enTime,n);

        int tk = pt[i].second.second + helper(next,n,pt,dp);

        return dp[i] = max(sk,tk);
    }
    static bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
    {
        return a.first < b.first;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>>pt;

        int n=startTime.size();
        for(int i=0;i<n;i++)
        pt.push_back({startTime[i],{endTime[i],profit[i]}});

        sort(pt.begin(),pt.end(),cmp);
        int maxi=0;
        vector<int>dp(n+1,-1);
        return helper(0,n,pt,dp);
    }
};