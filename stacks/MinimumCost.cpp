#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string s) {
  if(s.length()%2==1) return -1;

  stack<char>st;
  for(int i=0;i<s.length();i++)
  {
      char ch=s[i];

      if(ch=='{')
      {
          st.push(ch);
      }else{
          if(!st.empty() && st.top()=='{')
          {
              st.pop();
          }else{
              st.push(ch);
          }
      }
  }

  int op=0;int cl=0;
  while(!st.empty())
  {
      if(st.top()=='{')
      op++;
      else 
      cl++;

      st.pop();
  }

  return (op+1)/2 + (cl+1)/2;
}