class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;

        int cnt=0;int temp=0;

        for(int i=2;i<n;i++)
        {
            if(nums[i-1]-nums[i-2] == nums[i]-nums[i-1])
            {
                temp++;
                cnt += temp;
            }
            else{
                temp=0;
            }
        }
        return cnt;
    }
};