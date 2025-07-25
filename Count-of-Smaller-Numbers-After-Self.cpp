class Solution {
    void merge(vector<pair<int,int>>&nums,vector<int>&ans,int l,int mid,int r)
    {
        int i=l;int j=mid+1;
        vector<pair<int,int>>temp;

        while(i<=mid && j<=r)
        {
            if(nums[i].first > nums[j].first)
            {
                ans[nums[i].second] += (r-j+1);
                temp.push_back(nums[i++]);
            }
            else
                temp.push_back(nums[j++]);
        }
        while(i<=mid)
            temp.push_back(nums[i++]);
        while(j<=r)
            temp.push_back(nums[j++]);

        int k=0;
        for(int st=l;st<=r;st++)
            nums[st] = temp[k++];
    }
    void mergeSort(vector<pair<int,int>>&vec,vector<int>&ans,int l,int r)
    {
        if(l>=r) return ;
        int mid = (l+r)/2;
        mergeSort(vec,ans,l,mid);
        mergeSort(vec,ans,mid+1,r);
        merge(vec,ans,l,mid,r);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>vec;
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],i});

        mergeSort(vec,ans,0,n-1);
        return ans;
    }
};