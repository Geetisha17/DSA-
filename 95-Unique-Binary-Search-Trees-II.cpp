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
    vector<TreeNode*> helper(int st,int e)
    {
        if(st>e) return {NULL};
        vector<TreeNode*>ans;

        for(int i=st;i<=e;i++)
        {
            vector<TreeNode*>lt = helper(st,i-1);
            vector<TreeNode*>rt = helper(i+1,e);

            for(TreeNode*left: lt)
            {
                for(TreeNode*right: rt)
                {
                    TreeNode*root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};