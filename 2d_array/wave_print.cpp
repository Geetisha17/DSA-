#include<iostream>
using namespace std;

void wave(int arr[][4],int r,int c){
    for(int j=0;j<c;j++){
        if(j%2==0){
            for(int i=0;i<=r-1;i++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int i=r-1;i>=0;i--){
                cout<<arr[i][j]<<" ";
            }
        }
    }
}

int main(){
    
     int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int r=3,c=4;
    wave(arr,r,c);
    return 0;
}