class DisjointSet{
    vector<int>parent,rank,size;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findUPar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u,int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v) return;
        else if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u,int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v) return;
        else if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else if(rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];

        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[0].size();j++)
            {
                if(graph[i][j]==1)
                {
                    ds.unionBySize(i,j);
                }
            }
        }

        DisjointSet ds(n);
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                if(ds.findUPar(i) != ds.findUPar(it))
                {
                    cnt++;
                }
            }
        }
    }
};