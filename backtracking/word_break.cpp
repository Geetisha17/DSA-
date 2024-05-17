#include<iostream>
#include<vector>
#include<string>
using namespace std;
int cnt=0;

void help(string s,int n,string res,vector<string>word){
    for(int i=1;i<=n;i++){

        string pre = s.substr(0,i);
        int l=word.size();
        bool flag=false;

        for(int j=0;j<l;j++){
            if(word[j]==pre)
            flag=true;
        }
        if(flag){
            if(i==n){
                res+=pre;
                cnt++;
                return;
            }
            help(s.substr(i,n-i),n-i,res+pre+" ",word);
        }
    }
}

int wordBreak(string s, vector<string> &dictionary)
{
    cnt=0;
    help(s,s.length(),"",dictionary);
    return cnt;
}