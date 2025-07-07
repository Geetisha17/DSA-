class Solution {
    bool helper(vector<int>&nums,long long k,int tol)
    {
        long long ans=0;
        for(auto it:nums)
        {
            ans += (k/it);
            if(ans>=tol) return true;
        }
        return (ans>=tol);
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low= 1;
        long long high= 1e14;
        long long ans=-1;

        while(low<=high)
        {
            long long mid = (low+high)/2;
            bool res = helper(time,mid,totalTrips);
            if(res)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};