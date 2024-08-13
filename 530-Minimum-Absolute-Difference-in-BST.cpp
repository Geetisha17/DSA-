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
    TreeNode*prev=nullptr;
    int mini=INT_MAX;
    void helper(TreeNode*root)
    {
        if(root==NULL) return;
        helper(root->left);

        if(prev!=NULL)
        mini = min(mini,abs(prev->val - root->val));

        prev = root; 
        helper(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return 0;
        helper(root);
        return mini;
    }
};