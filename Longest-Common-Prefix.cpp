class Node{
    Node*links[26];
    bool flag=false;
    int cw=0;
    public:
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node*node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void isEnd()
    {
        flag=true;
    }
    bool getEnd()
    {
        return flag;
    }
    void setCnt()
    {
        cw++;
    }
    int getCnt()
    {
        return cw;
    }
};
class Trie{
    Node*root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string word)
    {
        Node*node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i],new Node());
            node=node->get(word[i]);
            node->setCnt();
        }
        node->isEnd();
    }
    int longest(string word,int tol)
    {
        Node*node=root;
        int i=0;
        for(;i<word.length();)
        {
            if(node->get(word[i])->getCnt()==tol)
                node=node->get(word[i]);
            else
                break;
            i++;
        }
        return i;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;

        for(auto it:strs)
            trie.insert(it);

        int len = trie.longest(strs[0],strs.size());
        if(len==0) return "";
        return strs[0].substr(0,len);
    }
};