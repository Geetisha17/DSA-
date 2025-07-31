class Node{
    Node*links[2];
    bool flag=false;
    public:
    bool containsKey(int a)
    {
        return (links[a]!=NULL);
    }
    void put(int a,Node*node)
    {
        links[a]=node;
    }
    Node*get(int a)
    {
        return links[a];
    }
    void setEnd()
    {
        flag=true;
    }
    bool getEnd()
    {
        return flag;
    }
};
class Trie{
    Node*root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node*node=root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit))
                node->put(bit,new Node());
            node=node->get(bit);
        }
        node->setEnd();
    }
    int getMax(int num)
    {
        Node*node=root;
        int maxi=0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(node->containsKey(!bit))
            {
                maxi = maxi | (1<<i);
                node=node->get(!bit);
            }
            else node=node->get(bit);
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans(queries.size());
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>temp;

        for(int i=0;i<queries.size();i++)
            temp.push_back({queries[i][1],{queries[i][0],i}});
        
        sort(temp.begin(),temp.end());
        int idx=0;
        Trie trie;

        for(int i=0;i<temp.size();i++)
        {
            int ai = temp[i].first;
            int xi = temp[i].second.first;
            int qIdx = temp[i].second.second;

            while(idx<nums.size() && nums[idx]<=ai)
                trie.insert(nums[idx++]);
            
            if(idx==0) ans[qIdx]=-1;
            else ans[qIdx]=trie.getMax(xi);
        }
        return ans;
    }
};