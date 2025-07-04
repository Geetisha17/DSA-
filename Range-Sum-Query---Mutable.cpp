class SegmentTree{
    vector<int>segTree;
    int n;
    public:
    SegmentTree(int n)
    {
        this->n=n;
        segTree.resize(4*n);
    }
    void buildTree(int idx,int l,int r,vector<int>&nums)
    {
        if(l==r) {
            segTree[idx]=nums[l];
            return;
        }

        int mid = (l+r)/2;
        buildTree(2*idx+1,l,mid,nums);
        buildTree(2*idx+2,mid+1,r,nums);
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    void update(int i,int val,int pos,int l,int r)
    {
        if(l==r)
        {
            segTree[i] = val;
            return;
        }

        int mid = (l+r)/2;
        if(pos<=mid)
            update(2*i+1,val,pos,l,mid);
        else 
            update(2*i+2,val,pos,mid+1,r);
        
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int queryVal(int i,int l,int r,int ql,int qr)
    {
        if(l>qr || r<ql) return 0;
        if(l>=ql && r<=qr) return segTree[i];

        int mid = (l+r)/2;
        int left = queryVal(2*i+1,l,mid,ql,qr);
        int right = queryVal(2*i+2,mid+1,r,ql,qr);
        return left+right;
    }
};

class NumArray {
public:
    int n;
    SegmentTree st;
    NumArray(vector<int>& nums): n(nums.size()) , st(nums.size()) {
        st.buildTree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        st.update(0,val,index,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return st.queryVal(0,0,n-1,left,right);
    }
};