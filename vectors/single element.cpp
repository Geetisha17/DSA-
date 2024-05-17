#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        int high = nums.size()-1;
        int low = 0;
        int mid;
        
        while(low<=high)
        {
            mid = (high+low)/2;
            //Unique element condition
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];
            
            if(((mid%2)==0 && nums[mid]==nums[mid+1])
               ||  ((mid%2)==1 && nums[mid]==nums[mid-1]))
                low = mid+1;
            else
                high = mid-1;
            
        }
        return -1;

