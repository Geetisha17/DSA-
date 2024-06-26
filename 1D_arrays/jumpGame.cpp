#include<iostream>
#include<vector>
using namespace std;

int jump(vector<int>& nums) {
      int len = nums.size() - 1, curr = -1, next = 0, ans = 0;
        for (int i = 0; next < len; i++) {
            if (i > curr) ans++, curr = next;
            next = max(next, nums[i] + i);
        };
        return ans;
}