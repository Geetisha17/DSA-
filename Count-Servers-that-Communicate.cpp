class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        DisjointSet ds(n+m+1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    ds.unionByRank(i,j+n+1);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0) continue;

                if(grid[i][j]==1)
                    mp[ds.findUPar(i)]++;
                
            }
        }
        int cnt=0;
        for(auto it:mp)
            if(it.second>1) cnt+=it.second;
        
        
        return cnt;
    }
};