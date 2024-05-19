#include<bits/stdc++.h>
using namespace std;

// int celebrity(vector<vector<int> >& a, int n) 
//     {
//         int in[n]={0};
//         int ou[n]={0};
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(a[i][j]==1)
//                 {
//                     in[j]++;
//                     ou[i]++;
//                 }
//             }
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             if(in[i]==n-1 && ou[i]==0)
//             return i;
//         }
//         return -1;
//     }

int celebrity(vector<vector<int> >& a, int n) 
    {
        int c = 0; 
        
        for (int i = 1; i < n; ++i) {
            if (M[c][i] == 1) {
                c = i; 
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != c && (M[i][c] == 0 || M[c][i] == 1)) {
                return -1;
            }
        }

        return c;
    }