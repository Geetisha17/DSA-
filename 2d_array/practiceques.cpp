#include<iostream>
using namespace std;

int count(int arr[][4],int r,int c){
    int count=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==0){
                count++;
            }
        }
    }
    return count;
}

int even(int arr[][4],int r,int c){
    int sum=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]%2==0)
            sum+=arr[i][j];
        }
    }
    return sum;
}

int diagonal(int arr[][4],int r,int c){
    int sum=0;

    for(int i=0;i<r;i++){
       for(int j=0;j<c;j++){
        if(arr[i][j]==arr[j][i])
        sum+=arr[i][j];
       }
    }
    return sum;

}

int  product(int arr[][4],int r,int c){
    int count=0;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==0){
                return 0;
            }
           
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]<0){
                count++;
            }
           
        }
    }
    if(count%2==0){
        return 1;
    }
    else return 0;

}
int main(){
    int arr[3][4]={{1,-2,-3,5},{-5,10,7,70},{8,80,90,70}};
    int r=3,c=4;
    cout<<product(arr,r,c);
    return 0;
}