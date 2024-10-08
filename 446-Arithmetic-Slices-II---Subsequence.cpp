class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        unordered_map<long,int>mp[n]; // diff , count

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long diff = (long)nums[i]-nums[j];
                auto it = mp[j].find(diff);

                int cnt = it== end(mp[j]) ? 0 :it->second;

                mp[i][diff] += cnt+1;

                res += cnt;
            }
        }
        return res;
    }
};