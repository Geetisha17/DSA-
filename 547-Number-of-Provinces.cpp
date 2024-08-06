class Solution {
    void helper(int node,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[node]=1;

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                helper(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& graph) {
        int n=isConnected.size();
        vector<int>vis(n+1,0);
        vector<vector<int>>adj(n);

        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                if(graph[i][j]==1 && i!=j)
                {
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }

        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                helper(i,vis,adj);
            }
        }
        return cnt;
    }
};