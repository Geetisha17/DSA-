#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        int leftmax=0;int rightmax=0;int maxi=0;

        int l=0;int r=n-1;

        while(l<=r)
        {
            if(nums[l] <= nums[r])
            {
                if(leftmax<nums[l]) leftmax=nums[l];
                else maxi += (leftmax-nums[l]);
                l++;
            }else{
                if(rightmax<nums[r]) rightmax=nums[r];
                else maxi += (rightmax-nums[r]);
                r--;
            }
        }
        return maxi;
    }
};