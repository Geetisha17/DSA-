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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxiArea = 0, n = matrix.size(), m = matrix[0].size();
                vector<int> height(m,0);
                
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(matrix[i][j] == '1') height[j]++;
                        else height[j] = 0;
                    }   
                    int area = largestRectangleArea(height);
                    maxiArea = max(maxiArea,area);
                }
                return maxiArea;
    }
};


