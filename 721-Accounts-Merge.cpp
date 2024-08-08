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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;

        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[0].size();j++)
            {
                string mail = accounts[i][j];
                mp[mail] = i;
                ds.unionBySize(i,mp[mail]);
            }
        }
        vector<vector<string>>ans;
        vector<string>mergeMail[n];

        for(auto it:mp)
        {
            string mail=it.first;
            int node = ds.findUPar(it.second);
            mergeMail[node].push_back(mail);
        }

        for(int i=0;i<n;i++)
        {
            if(mergeMail[i].size()==0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergeMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};