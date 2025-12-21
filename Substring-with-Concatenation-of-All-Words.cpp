1class Solution {
2public:
3    vector<int> findSubstring(string s, vector<string>& words) {
4        unordered_map<string,int>mp;
5        for(auto it:words) mp[it]++;
6
7        int wordsz = words[0].length();
8        int tolLen = wordsz * words.size();
9        vector<int>ans;
10
11        for(int i=0;i<wordsz;i++)
12        {
13            int left=i,right=i,wordsSoFar=0;
14            unordered_map<string,int>seenSoFar;
15            while(right + wordsz <= s.length())
16            {
17                string word = s.substr(right,wordsz);
18                right+=wordsz;
19
20                if(mp.find(word)!=mp.end())
21                {
22                    seenSoFar[word]++;
23                    wordsSoFar++;
24
25                    while(seenSoFar[word] > mp[word])
26                    {
27                        string temp=s.substr(left,wordsz);
28                        seenSoFar[temp]--;
29                        wordsSoFar--;
30                        left+=wordsz;
31                    }
32                    if(wordsSoFar == words.size())
33                    ans.push_back(left);
34                }
35                else
36                {
37                    seenSoFar.clear();
38                    wordsSoFar=0;
39                    left=right;
40                }
41            }
42        }
43        return ans;
44    }
45};