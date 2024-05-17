#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

bool isAnagram(string a, string b){
    if(a.length()!=b.length()) return 0;

    vector<int> s(26,0);
    vector<int> t(26,0);

    for(int i=0;i<a.length();i++){
        s[a[i]-'a']++;
        t[b[i]-'a']++;
    }
    return s==t;
}

int main(){
    return 0;
}