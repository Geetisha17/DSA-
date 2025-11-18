class BSTIterator {
    stack<TreeNode*>st;
public:
    void helper(TreeNode*root)
    {
        if(!root) return;
        while(root)
        {
            st.push(root);root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    int next() {
        TreeNode* res=st.top();st.pop();
        if(res->right) helper(res->right);
        return res->val; 
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};
