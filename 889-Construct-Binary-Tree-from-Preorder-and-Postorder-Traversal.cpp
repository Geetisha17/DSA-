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
    TreeNode* helper(int prs, int preend, vector<int>& preorder,int pos, int poend, vector<int>& postorder, unordered_map<int, int>& mp)
    {
        if (prs > preend || pos > poend) return NULL;

        TreeNode* root = new TreeNode(preorder[prs]);
        if (prs == preend) return root; 

        int val = preorder[prs + 1];
        int idx = mp[val];

        int rem = idx - pos + 1;

        root->left = helper(prs+1, prs+rem, preorder, pos, idx, postorder, mp);
        root->right = helper(prs + rem + 1, preend, preorder, idx + 1, poend - 1, postorder, mp);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        unordered_map<int,int>mp;

        for(int i=0;i<postorder.size();i++)
        mp[postorder[i]]=i;

        TreeNode*root = helper(0,n-1,preorder,0,n-1,postorder,mp);
        return root;
    }
};