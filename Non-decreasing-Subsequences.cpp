class Solution {
    void helper(int i,vector<int>&nums,vector<int>&temp,set<vector<int>>&ans)
    {
        if(i>=nums.size())
        {
            if(temp.size()>=2)
                ans.insert(temp);
            return;
        }
        helper(i+1,nums,temp,ans);

        if(temp.empty() || temp.back()<=nums[i])
        {
            temp.push_back(nums[i]);
            helper(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        set<vector<int>>st;
        helper(0,nums,temp,st);
        for(auto it:st)
        ans.push_back(it);
        return ans;
    }
};