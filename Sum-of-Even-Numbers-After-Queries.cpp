class Solution {
public:
    int bagOfTokensScore(vector<int>& nums, int power) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int score=0;
        int ans=0;
        int l=0;int r=n-1;

        while(l<=r)
        {
            if(power >= nums[l])
            {
                power-=nums[l];score++;l++;
            }
            else if(power >= nums[r])
            {
                power -= nums[r];score++;r--;
            }
            else if(power < nums[r] && score>0)
            {
                power+=nums[r];score--;r--;
            }
            else l++;
            ans=max(ans,score);
        }
        return ans;
    }
};