/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* k) {
        if(c==NULL) return NULL;
        if(c->val==k->val)return c;

        TreeNode*left=getTargetCopy(o,c->left,k);
        TreeNode*right=getTargetCopy(o,c->right,k);

        if(left)
        return left;
        return right;
    }
};