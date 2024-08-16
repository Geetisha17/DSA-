class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int idx=-1;
        int lsum=0;
        int sum=0;
        for(auto it:nums)
        sum += it;

        for(int i=0;i<nums.size();i++)
        {
            if(lsum == sum-nums[i]-lsum)
            {
                idx=i;break;
            }
            lsum += nums[i];
        }
        return idx;
    }
};