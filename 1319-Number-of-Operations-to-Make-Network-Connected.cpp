class DisjointSet{
    public:
    vector<int>rank,parent,size;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
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
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
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
        else if(rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else 
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int extra=0;

        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1]; 
            if(ds.findUPar(u)==ds.findUPar(v))
            {
                extra++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int nC=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i)==i) nC++;
        }
        if(nC-1<=extra) return nC-1;
        return -1;
    } 
};