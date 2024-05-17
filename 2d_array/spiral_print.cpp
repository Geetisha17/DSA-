#include<iostream>
using namespace std;

void spiral(int arr[][4],int r,int c){
    int startcol=0;
    int endcol=c-1;
    int startrow=0;
    int endrow=r-1;

    while(startcol<=endcol && startrow<=endrow){
        for(int j=startcol;j<=endcol;j++){
            cout<<arr[startrow][j]<<" ";
        }
        for(int i=startrow+1;i<=endrow;i++){
            cout<<arr[i][endcol]<<" ";
        }
        for(int j=endcol-1;j>=startcol;j--){
            if(startrow==endrow) break;
            cout<<arr[endrow][j]<<" ";
        }
        for(int i=endrow-1;i>=startrow+1;i--){
            if(startcol==endcol) break;
            cout<<arr[i][startcol]<<" ";
        }
        startcol++;
        endcol--;
        startrow++;
        endrow--;
    }
}

int main(){
      int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int r=3,c=4;
    spiral(arr,r,c);
    return 0;
}