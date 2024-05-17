#include <bits/stdc++.h>
using namespace std;

string removeDuplicate(string s){
    // your code goes here
 int arr[26]={0};
 
 for(int i=0;i<s.length();i++){
     arr[s[i] - 'a']++;
 }

 string ans="";
 for(int i=0;i<26;i++){
     if(arr[i]>0){
         ans+='a' +i;
     }
 }
 return ans;
}