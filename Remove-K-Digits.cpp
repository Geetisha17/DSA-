1class Solution {
2public:
3    string removeKdigits(string num, int k) {
4        stack<char>st;
5        int n=num.length();
6        if(k==n) return "0";
7
8        string ans="";
9        for(int i=0;i<n;i++)
10        {
11            while(!st.empty() && k>0 && st.top() > num[i])
12            {
13                st.pop();k--;
14            }
15            st.push(num[i]);
16        }
17        while(!st.empty() && k>0)
18        {
19            st.pop();k--;
20        }
21        while(!st.empty())
22        {
23            ans.push_back(st.top());st.pop();
24        }
25        reverse(ans.begin(),ans.end());
26        while(ans[0]=='0')
27        ans.erase(ans.begin());
28        if(ans.empty()) return "0";
29        return ans;
30    }
31};