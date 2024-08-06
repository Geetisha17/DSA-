struct Node{
    Node*links[2];
    bool flag=false;

    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }

    Node*put(int bit,Node*node)
    {
        return links[bit] = node;
    }

    Node*get(int bit)
    {
        return links[bit];
    }
    void isEnd()
    {
        flag=true;
    }
};

class Trie{
    Node*root;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(int n)
    {
        Node*node=root;

        for(int i=31;i>=0;i--)
        {
            int bit = (n>>i) & 1;

            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            } 
            node = node->get(bit);
        }
        node->isEnd();
    }

    int findMax(int n)
    {
        Node*node=root;
        int maxi=0;

        for(int i=31;i>=0;i--)
        {
            int bit = (n>>i) & 1;

            if(node->containsKey(!bit))
            {
                maxi = maxi | (1<<i);
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans(queries.size(),0);
        sort(nums.begin(),nums.end());

        vector<pair<int,pair<int,int>>>temp;

        for(int i=0;i<queries.size();i++)
        {
            temp.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(temp.begin(),temp.end());
        int idx=0;

        Trie trie;
        for(int i=0;i<queries.size();i++)
        {
            int ai = temp[i].first;
            int xi = temp[i].second.first;
            int qIdx = temp[i].second.second;

            while(idx<nums.size() && nums[idx] <= ai)
            {
                trie.insert(nums[idx]);
                idx++;
            } 
            if(idx==0) ans[qIdx] = -1;
            else ans[qIdx]=trie.findMax(xi);
        }
        return ans;
    }
};