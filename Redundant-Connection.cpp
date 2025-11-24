class DisjointSet{
    vector<int>rank,parent;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++) parent[i]=i;
    }
    int findUPar(int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u=findUPar(u);int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        } 
        else 
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int a=-1;int b=-1;
        int n=edges.size();
        DisjointSet ds(n);
        for(auto it:edges)
        {
            if(ds.findUPar(it[0])==ds.findUPar(it[1]))
            {
                a=it[0],b=it[1];
            }
            ds.unionByRank(it[0],it[1]);
        }
        return {a,b};
    }
};