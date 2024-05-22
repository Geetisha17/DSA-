#include <bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it=q.front();q.pop();
            Node*n=it.first;
            int l=it.second;
            mp[l]=n->data;
            
            if(n->left) q.push({n->left,l-1});
            if(n->right) q.push({n->right,l+1});
        }
        
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }