class SegmentTree{
    public:
    vector<int>segTree;
    SegmentTree(int n)
    {
        segTree.resize(4*n);
    }
    void buildTree(int idx,int l,int r,vector<int>&nums)
    {
        if(l==r)
        {
            segTree[idx]=l;
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*idx+1,l,mid,nums);
        buildTree(2*idx+2,mid+1,r,nums);
        segTree[idx] = (nums[segTree[2*idx+1]] >= nums[segTree[2*idx+2]]) ? segTree[2*idx+1] : segTree[2*idx+2];
    }
    int RMIQ(int idx,int l,int r,int ql,int qr,vector<int>&nums)
    {
        if(l>qr || r<ql) return -1;
        if(l>=ql && r<=qr) return segTree[idx];

        int mid = (l+r)/2;
        int left = RMIQ(2*idx+1,l,mid,ql,qr,nums);
        int right = RMIQ(2*idx+2,mid+1,r,ql,qr,nums);
        if(left==-1) return right;
        if(right==-1) return left;
        return (nums[left] >= nums[right]) ? left : right;
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        SegmentTree st(n);

        st.buildTree(0,0,n-1,nums);
        vector<int>ans;

        for(auto it:queries)
        {
            int a = min(it[0],it[1]);
            int b = max(it[0],it[1]);
            if(a==b || (nums[a] < nums[b]))
            {
                ans.push_back(b);
                continue;
            }
            
            int l = (b+1);
            int r = (n-1);
            int res=-1;

            while(l<=r)
            {
                int mid = (l+r)/2;
                int idx = st.RMIQ(0,0,n-1,b+1,mid,nums);
                if(idx!=-1 && nums[idx] > max(nums[a],nums[b]))
                {
                    res=idx;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};