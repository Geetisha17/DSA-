struct Node {
    Node* links[26];
    bool flag = false;
    int eachVal = 0;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }
    
    Node* put(char ch, Node* node) {
        links[ch - 'a'] = node;
        return node;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    bool isEndsWith() {
        return flag;
    }
    
    bool setEndWith() {
        flag = true;
        return flag;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node = node->put(ch, new Node());
            } else {
                node = node->get(ch);
            }
        }
        node->setEndWith();
    }
    
    string findstr() {
        string ans = \\;
        Node* node = root;

        while (node != nullptr) {
            Node* next = nullptr;
            int cnt = 0;
            char ch;

            for (int i = 0; i < 26; i++) {
                if (node->links[i] != nullptr) {
                    // cout<<node->links[i]<<endl;
                    cnt++;
                    next = node->links[i];
                    ch = 'a' + i;
                    cout<<ch<<endl;
                }
            }

            if (cnt != 1 || node->isEndsWith()) {
                break;
            }

            ans += ch;
            cout<<ans<<endl;
            node = next;
        }

        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;

        for (const string& word : strs) {
            trie.insert(word);
        }

        return trie.findstr();
    }
};
