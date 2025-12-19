1class Solution {
2public:
3    string reorganizeString(string s) {
4        unordered_map<char,int>mp;
5        for(auto it:s)
6        mp[it]++;
7
8        priority_queue<pair<int,char>>pq;
9        for(auto it:mp)
10        pq.push({it.second,it.first});
11
12        string ans="";
13        while(pq.size()>=2)
14        {
15            auto a = pq.top();pq.pop();
16            auto b = pq.top();pq.pop();
17            cout<<a.first<<" "<<a.second<<endl;
18            cout<<b.first<<" "<<b.second<<endl;
19
20            ans+=a.second;
21            ans+=b.second;
22            a.first--;
23            b.first--;
24
25            if(a.first>0)
26                pq.push({a.first,a.second});
27            if(b.first>0)
28                pq.push({b.first,b.second});
29        }
30        if(pq.size()>0)
31        {
32            if(pq.top().first>1) return "";
33            else ans+=pq.top().second;
34        }
35        return ans;
36    }
37};