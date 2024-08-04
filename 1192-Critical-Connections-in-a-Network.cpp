class Solution {
    int timer = 1;

    void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],vector<int>&time,vector<int>&low,vector<vector<int>>&ans)
    {
        vis[node]=1;
        time[node] = low[node]=timer;
        timer++;

        for(auto it:adj[node])
        {
            if(it==parent) continue;
            if(!vis[it])
            {
                dfs(it,node,vis,adj,time,low,ans);
                low[node] = min(low[node] , low[it]);

                if(low[it] > time[node])
                {
                    ans.push_back({it,node});
                }
            }
            else 
            {
                low[node] = min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];

        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n,0);
        vector<int>time(n);
        vector<int>low(n);

        vector<vector<int>>ans;

        dfs(0,-1,vis,adj,time,low,ans);

        return ans;
    }
};