#include<bits/stdc++.h>
using namespace std;

int check(string s){
    int arr[26]={0};
int no=0;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        no = ch-'a';
        arr[no]++;
    }

    for(int i=0;i<26;i++){
        if(arr[i]==0){
            return 0;
        }
        else{
            return 1;
        }
    }
}

int main(){
    string s;
    cin>>s;
    cout<<check(s);

    return 0;
}