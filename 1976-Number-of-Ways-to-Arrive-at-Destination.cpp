class Solution {
public:
    const long long mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];

        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0,0});

        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty())
        {
            auto it=pq.top();
            long long node = it.second;
            long long dis = it.first;
            pq.pop();
            if(dis > dist[node]) continue;

            for(auto it:adj[node])
            {
                long long v = it.first;
                long long wt  = it.second;

                if(wt + dis < dist[v])
                {
                    dist[v] = wt+dis;
                    ways[v]=ways[node];
                    pq.push({dist[v],v});
                }
                else if(wt+dis == dist[v])
                {
                    ways[v] = (ways[v] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};