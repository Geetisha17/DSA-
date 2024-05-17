#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>s;
        int maxA=0;
        int n = arr.size();

        for(int i=0;i<=n;i++){

            while(!s.empty() && (i==n || arr[s.top()]>=arr[i])){
                int h = arr[s.top()];
                s.pop();
                int w;
                if(s.empty()) w=i;
                else w=i-s.top()-1;
                maxA=max(maxA,w*h);
            }
            s.push(i);
        }
        return maxA;
    }
};