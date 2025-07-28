class Node{
    Node*links[26];
    bool flag=false;
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
};
class Trie {
    Node*root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node*node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i],new Node());
            node=node->get(word[i]);
        }
        node->isEnd();
    }
    
    bool search(string word) {
        Node*node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
                return false;
            node=node->get(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string word) {
        Node*node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
                return  false;
            node=node->get(word[i]);
        }
        return true;
    }
};
