class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty())
        {
            auto it=q.front();q.pop();
            int len=it.second;
            string word=it.first;

            if(word==endWord) return len;
            for(int i=0;i<word.length();i++)
            {
                int ori=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,len+1});
                    }
                }
            }
        }
        return -1;
    }
};