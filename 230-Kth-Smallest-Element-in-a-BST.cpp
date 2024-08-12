/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int helper(TreeNode*root,int k,int &ans,int &cnt)
    {
        if(root==NULL) return ans;

        helper(root->left,k,ans,cnt);
        cnt++;
        if(cnt==k) ans=root->val;

        helper(root->right,k,ans,cnt);
        return ans;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;int cnt=0;
        helper(root,k,ans,cnt);
        return ans;
    }
};