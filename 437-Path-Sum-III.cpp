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
    void helper(TreeNode* root, int k, int &cnt, unordered_map<long long, int>& mp, long long sum) {
        if (root == NULL) return;

        sum += root->val;

        if (mp.find(sum - k) != mp.end()) {
            cnt += mp[sum - k];
        }

        mp[sum]++;

        helper(root->left, k, cnt, mp, sum);
        helper(root->right, k, cnt, mp, sum);

        mp[sum]--;
    }

public:
    int pathSum(TreeNode* root, int k) {
        int cnt = 0;
        unordered_map<long long, int> mp;
        mp[0] = 1; 
        helper(root, k, cnt, mp, 0);
        return cnt;
    }
};