class Solution {
    void merge(vector<pair<int,int>>&nums,int l,int r,int mid,vector<int>&ans)
    {
        int i=l;int j=mid+1;
        vector<pair<int,int>>temp(r-l+1);
        int k=0;

        while(i<=mid && j<=r)
        {
            if(nums[i].first > nums[j].first)
            {
                ans[nums[i].second] += (r-j+1);
                temp[k++]=  nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        while(i<=mid)
            temp[k++] = nums[i++];
        while(j<=r) 
            temp[k++] = nums[j++];
        
        for (int i = l; i <= r; i++) {
            nums[i] = temp[i - l];
        }
    }
    void mergeSort(vector<pair<int,int>>&nums,int l,int r,vector<int>&ans)
    {
        if(l>=r) return;

        int mid = (l+r)/2;
        mergeSort(nums,l,mid,ans);
        mergeSort(nums,mid+1,r,ans);
        merge(nums,l,r,mid,ans);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>vec;
        
        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],i});
        mergeSort(vec,0,n-1,ans);
        return ans;
    }
};