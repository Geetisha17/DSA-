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
    void helper(TreeNode*root,vector<vector<int>>&ans,vector<int>&temp,int k)
    {
        if(root==NULL) return;

        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL && k-root->val==0)
        ans.push_back(temp);

        if(root->left) helper(root->left,ans,temp,k-root->val);
        if(root->right) helper(root->left,ans,temp,k-root->val);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int k) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        vector<int>temp;
        helper(root,ans,temp,k);
        return ans;
    }
};