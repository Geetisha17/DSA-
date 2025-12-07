1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4        unordered_map<char,int>mp;
5        for(auto it:tasks)
6        mp[it]++;
7
8        priority_queue<int>pq;
9        for(auto it:mp)
10        pq.push(it.second);
11
12       int cntTask=0;
13        while(!pq.empty())
14        {
15            vector<int>temp;
16            int sz=pq.size();
17            int res=0;
18            for(int i=1;i<=n+1;i++)
19            {
20                if(!pq.empty())
21                {int task=pq.top();pq.pop();
22                task--;
23                if(task!=0)
24                temp.push_back(task);
25                res++;
26            }
27            }
28            if(res<(n+1))
29            {
30                if(temp.size()>0)
31                cntTask+=(n+1)-res;
32            }
33            cntTask+=res;
34            
35            if(temp.size()>0)
36            for(auto it:temp)
37            pq.push(it);
38        }
39        return cntTask;
40    }
41};