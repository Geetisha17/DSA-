struct Node{
    Node*links[2];
    bool flag=false;

    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    Node*put(int bit,Node*node)
    {
        return links[bit]=node;
    }
    Node*get(int bit)
    {
        return links[bit];
    }
    void isEnd()
    {
        flag=false;
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
        Node*node = root;
        
        for(int i=31;i>=0;i--)
        {
            int bit = (n>>i) & 1; 

            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        } 
        node->isEnd();
    }

    int getMax(int n)
    {
        Node*node=root;
        int maxi=0;

        for(int i=31;i>=0;i--)
        {
            int bit = (n>>i) & 1;

            if(node->containsKey(1-bit))
            {
                maxi = maxi | (1<<i);
                node = node->get(1-bit);
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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for(auto it:nums)
        {
            trie.insert(it);
        }
        int maxi=0;

        for(auto it:nums)
        {
            maxi = max(maxi,trie.getMax(it));
        }
        return maxi;
    }
};