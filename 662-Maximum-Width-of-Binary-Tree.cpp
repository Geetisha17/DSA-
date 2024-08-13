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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;

        while(!q.empty())
        {
            int fst=0;int lst=0;
            int sz = q.size();
            int idx = q.front().second;

            for(int i=0;i<sz;i++)
            {
                auto it = q.front();q.pop();
                TreeNode*node = it.first;
                int dis = it.second()-idx;
                if(i==0) fst=dis;
                if(i==sz-1) lst=dis;

                if(node->left) q.push({node->left,2*dis+1});
                if(node->right) q.push({node->right,2*dis+2});
            }
            ans = max(ans,lst-fst+1);
        }
        return ans;
    }
};