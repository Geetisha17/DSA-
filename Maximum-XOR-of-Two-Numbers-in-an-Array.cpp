class Node{
    Node*links[2];
    bool flag=false;
    public:
    bool containsKey(int a)
    {
        return (links[a]!=NULL);
    }
    Node*get(int a)
    {
        return links[a];
    }
    void put(int a,Node*node)
    {
        links[a]=node;
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
    int largest(int num)
    {
        Node*node=root;
        int maxi=0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(node->containsKey(!bit))
            {
                maxi=maxi | (1<<i);
                node=node->get(!bit);
            }else{
                node=node->get(bit);
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
            trie.insert(it);
        int maxi=0;
        for(auto it:nums)
            maxi=max(maxi,trie.largest(it));

        return maxi;
    }
};