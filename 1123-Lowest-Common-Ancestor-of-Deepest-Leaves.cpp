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
    int maxH(TreeNode*root)
    {
        if(root==NULL) return 0;

        int l=maxH(root->left);
        int r = maxH(root->right);

        return max(l,r)+1;
    }
    TreeNode*lca(TreeNode*root,unordered_set<TreeNode*>mp)
    {
        if(root==NULL || mp.find(root) != mp.end()) return root;
        TreeNode*l = lca(root->left,mp);
        TreeNode*r = lca(root->right,mp);
        if(l && r) return root;
        else if(l) return l;
        return r; 
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;q.push(root);
        int h = maxH(root);
        int cnt=0;
        unordered_set<TreeNode*>res;

        while(!q.empty())
        {
            int sz=q.size();
            cnt++;
            res.clear();
            for(int i=0;i<sz;i++)
            {
                TreeNode*node=q.front();q.pop();
                if(cnt == h)
                res.insert(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return lca(root,res);
    }
};