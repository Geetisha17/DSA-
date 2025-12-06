1class Solution {
2public:
3    string longestDiverseString(int a, int b, int c) {
4        priority_queue<pair<int,char>>pq;
5        if(a!=0) pq.push({a,'a'});
6        if(b!=0) pq.push({b,'b'});
7        if(c!=0) pq.push({c,'c'});
8        string s;
9
10        while(!pq.empty())
11        {
12            auto it=pq.top();pq.pop();
13            int num=it.first;char ch=it.second;
14            int n=s.length();
15            if(n>=2 && s[n-1]==ch && s[n-2]==ch)
16            {
17                if(pq.empty()) break;
18                auto node=pq.top();pq.pop();
19                int res=node.first;char cha=node.second;
20                s.push_back(cha);res--;
21                if(res>0) pq.push({res,cha});
22            }
23            else
24            {
25                s.push_back(ch);num--;
26            }
27            if(num>0)
28            pq.push({num,ch});
29        }
30        return s;
31    }
32};