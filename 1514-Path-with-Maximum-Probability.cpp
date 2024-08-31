class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        queue<pair<int,double>>q;
        q.push({start,1});

        vector<double>maxi(n);
        maxi[start] = 1;

        while(!q.empty())
        {
            auto it=q.front();q.pop();
            int node = it.first;
            double res = it.second;

            maxi[node] = max(maxi[node],res);

            for(auto it:adj[node])
            {
                int u = it.first;
                double wt = it.second;

                if(res*wt > maxi[u])
                {
                    maxi[u]=res*wt;
                    q.push({u,res*wt});
                }
            }
        }
        return maxi[end];
    }
};