#include<iostream>
using namespace std;

pair<int,int> staircase(int arr[][4],int r,int c,int key){
    int j=c-1;
    int i=0;

     if(arr[i][j]>key || arr[r-1][c-1]<key){
            return {0,0};
        }

    while(i<=r-1 && j>=0){
       if(arr[i][j]==key){
        return {i,j};
       }
        else if(arr[i][j]>key){
            j--;
        }
        else{
            i++;
        }
         
    }
  
}

int main(){
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int r=3,c=4;
    pair<int,int> coords =staircase(arr,r,c,8);
    cout<<coords.first<<" "<<coords.second<<endl; 
    return 0;
}