#include <bits/stdc++.h> 
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            //node
            TreeNode*n=q.front().first;
            int x=q.front().second.first; // vertical
            int y=q.front().second.second; // level
            q.pop();
            mp[x][y].insert(n->val);
            if(n->left) q.push({n->left,{x-1,y+1}});
            if(n->right) q.push({n->right,{x+1,y+1}});
        }
        
        vector<vector<int>>ans;

        for(auto i:mp)
        {
            vector<int>curr;
            for(auto j:i.second)
            {
                curr.insert(curr.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(curr);
        }
        return ans;
    }