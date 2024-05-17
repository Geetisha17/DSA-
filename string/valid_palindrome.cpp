#include<bits/stdc++.h>
using namespace std;

bool isvalid(char ch){
     if(ch>='a' && ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9'){
        return 1;
     }
     return 0;
}

bool palin(string a){
    int s=0;
    int e=a.length()-1;
while(s<=e){
    if(a[s]!=a[e]){
        return 0;
    }
    else{
        s++;
        e--;
    }
}
    return 1;

}

int lowercase(char ch){
    if(ch>='a' && ch<='z' || ch>='0' && ch<='9'){
        return ch;
    }
    else{
        return ch-'A'+'a';
    }
}

bool palindrome(string s){
     string temp="";

    for(int i=0;i<s.length();i++){
        if(isvalid(s[i])){
        temp.push_back(s[i]);
        }
    } 
    for(int i=0;i<temp.length();i++){
        temp[i]=lowercase(temp[i]);
    }

    return palin(temp);
}

int main(){
    string s="A man, a plan , a canal : Panama";

    cout<<palindrome(s);
    return 0;
}