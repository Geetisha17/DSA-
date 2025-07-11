class Solution {
    bool helper(vector<int>temp,long long mid)
    {
        long long rem=0;
        vector<long long>nums(temp.begin(),temp.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] > mid) return false;
            rem = mid - nums[i];
            nums[i+1] = nums[i+1]-rem;
        }
        return nums[nums.size()-1] <= mid;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long l=0;
        long long h=*max_element(nums.begin(),nums.end());
        long long ans=-1;
        while(l<=h)
        {
            long long mid=(l+h)/2;
            if(helper(nums,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return (int)ans;
    }
};