1class Solution {
2public:
3    string reorganizeString(string s) {
4        vector<int>freq(26,0);
5        for(auto it:s)
6        freq[it-'a']++;
7
8        priority_queue<pair<int,char>>pq;
9        for(int i=0;i<26;i++)
10        {
11            if(freq[i]>0)
12            pq.push({freq[i],char(i+'a')});
13        }
14
15        string ans="";
16        while(pq.size()>=2)
17        {
18            auto a = pq.top();pq.pop();
19            auto b = pq.top();pq.pop();
20
21            ans+=a.second;
22            ans+=b.second;
23            a.first--;
24            b.first--;
25
26            if(a.first>0)
27                pq.push({a.first,a.second});
28            if(b.first>0)
29                pq.push({b.first,b.second});
30        }
31        if(pq.size()>0)
32        {
33            if(pq.top().first>1) return "";
34            else ans+=pq.top().second;
35        }
36        return ans;
37    }
38};