class DisjointSet{
    vector<int>parent;
    vector<int>rank;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findUPar(int node)
    {
        if(parent[node]==node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u == ulp_v)
            return;
        if(rank[ulp_v] > rank[ulp_u])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        int n=accounts.size();
        DisjointSet ds(n);

        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])!=mp.end())
                    ds.unionByRank(mp[accounts[i][j]],i);
                
                mp[accounts[i][j]]=i;
            }
        }
        vector<vector<string>>mails(n);
        for(auto it:mp)
        {
            int node = ds.findUPar(it.second);
            mails[node].push_back(it.first);
        }

        vector<vector<string>>ans;
        for(int i=0;i<mails.size();i++)
        {
            if(mails[i].size()==0) continue;
            sort(mails[i].begin(),mails[i].end());
            vector<string>temp(mails[i]);
            temp.insert(temp.begin(),accounts[i][0]);   
            ans.push_back(temp);
        }
        return ans;
    }
};