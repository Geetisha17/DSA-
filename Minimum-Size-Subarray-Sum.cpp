class Solution {
    bool helper(vector<int>&nums,int mid,int target){
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(i>=mid) sum -= nums[i-mid];
            if(i>=mid-1 && sum>=target) return true;
        }
        return false;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=0;
        int low=1;
        int high=nums.size();
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            int res = helper(nums,mid,target);
            if(res)
            {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};