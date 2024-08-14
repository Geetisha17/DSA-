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
    void markParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&track,TreeNode*k)
    {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode*curr=q.front();q.pop();
            if(curr->left)
            {
                track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                track[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;

        unordered_map<TreeNode*,TreeNode*>track;
        markParent(root,track,target);

        queue<TreeNode*>q;q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        int curr_level=0;
        while(!q.empty())
        {
            int sz=q.size();
            if(curr_level++==k) break;
            for(int i=0;i<sz;i++)
            {
                TreeNode*current= q.front();q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);visited[current->right]=true;
                }
                if(track[current] && !visited[track[current]]){
                    q.push(track[current]);visited[track[current]]=true;
                }
            }
        }

        while(!q.empty())
        {
            TreeNode*current=q.front();q.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};