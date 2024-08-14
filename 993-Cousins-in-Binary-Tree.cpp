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
    void findUPar(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<TreeNode*, TreeNode*> par;
        findUPar(root, par);

        queue<TreeNode*> q;
        q.push(root);
        
        bool x1 = false, y1 = false;
        TreeNode* p1 = nullptr;
        TreeNode* p2 = nullptr;

        while (!q.empty()) {
            int sz = q.size();
            x1 = y1 = false;
            
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->val == x) {
                    x1 = true;
                    p1 = par[node];
                }
                if (node->val == y) {
                    y1 = true;
                    p2 = par[node];
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            if (x1 && y1) {
                return p1 != p2;
            }
        }
        
        return false;
    }
};
