1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int n=nums.size();
5        int maxiJumpWeCanTake=0;
6        
7        for(int i=0;i<n;i++)
8        {
9            if(maxiJumpWeCanTake < i) return false;
10            maxiJumpWeCanTake = max(maxiJumpWeCanTake,nums[i]+i);
11        }
12        return true;
13    }
14};