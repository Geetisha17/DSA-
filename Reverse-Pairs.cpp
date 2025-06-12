class Solution {
    void merge(vector<int>&nums,int l,int r,int mid)
    {
        int i=l;int j=mid+1;
        vector<int>temp;

        while(i<=mid && j<=r)
        {
            if(nums[i] >= nums[j])
                temp.push_back(nums[j++]);
            
            else
                temp.push_back(nums[i++]);
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=r) temp.push_back(nums[j++]);

        int k=0;
        for(int i=l;i<=r;i++)
            nums[i]=temp[k++];
    }
    void mergeSort(vector<int>&nums,int l,int r,int &cnt)
    {
        if(l>=r) return;

        int mid = (l+r)/2;
        mergeSort(nums,l,mid,cnt);
        mergeSort(nums,mid+1,r,cnt);
        int j = mid + 1;
        for (int i=l;i<=mid;i++) {
            while (j<=r && (long long)nums[i]>2LL * nums[j])
                j++;
                cnt += (j-(mid+1));
        }
        merge(nums,l,r,mid);
    }
public:
    int reversePairs(vector<int>& nums) {
        int cnt=0;
        mergeSort(nums,0,nums.size()-1,cnt);
        return cnt;
    }
};