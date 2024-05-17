#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotatematrix(vector<vector<int>> matrix){
int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(i!=j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(matrix[i][j],matrix[i][n-j-1]);
        }
    }
    return matrix;
}

int main(){
vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
 vector<vector<int>> x=rotatematrix(matrix);

for(int  i=0;i<matrix.size();i++){
    for(int j=0;j<x[i].size();j++){
         cout<<x[i][j]<<" ";
          }
          cout<<endl;
    }
    return 0;
}

