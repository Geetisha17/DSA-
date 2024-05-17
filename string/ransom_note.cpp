#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> arr(26,0);
    for(char s:magazine) arr[s-'a']++;
    for(char t:ransomNote)
        if(!arr[t-'a']--)
        return 0;
        return 1;
}


int main(){
    string a="aac";
    string b="aab";
    cout<<canConstruct(a,b);
    return 0;
}