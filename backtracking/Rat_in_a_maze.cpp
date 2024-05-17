#include<iostream>
#include<vector>
using namespace std;

void ratchase(vector<string>a,vector<vector<int>>&b,vector<vector<int>>&v,int i,int j,int n,int m){
    if(i==n && j==m){
        for(int k=0;k<n;k++){
            for(int l=0;l<m;l++){
                v[k][l]=b[k][l];
            }
        }
        return;
    }
    //down
    if(i!=n && a[i+1][j]!='X' && b[i+1][j]!=1){
        b[i+1][j]=1;
        ratchase(a,b,v,i+1,j,n,m);
        b[i+1][j]=0;
    }
    //up
    if(i>0 && a[i-1][j]!='X' && b[i-1][j]!=1){
        b[i-1][j]=1;
        ratchase(a,b,v,i-1,j,n,m);
        b[i-1][j]=0;
    }
    //right
    if(j!=m && a[i][j+1]!='X' && b[i][j+1]!=1){
        b[i][j+1]=1;
        ratchase(a,b,v,i,j+1,n,m);
        b[i][j+1]=0;
    }
    //left
    if(j>0 && a[i][j-1]!='X' && b[i][j-1]!=1){
        b[i][j-1]=1;
        ratchase(a,b,v,i,j+1,n,m);
        b[i][j-1]=0;
    }
    return;
}

vector<vector<int>> ratAndMice(vector<string> a) {
    int n=a.size();
    int m=a[0].size();
    vector<vector<int>> b(n,vector<int>(m,0));
    vector<vector<int>> v(n,vector<int>(m,0));
    b[0][0]=1;
    ratchase(a,b,v,0,0,n,m);
    return v;
}

int main(){
    return 0;
}