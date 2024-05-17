#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int i=0,k=0;

    while(i<n){
        int j= i;

        while(j<n && chars[i]==chars[j]){
            j++;
        }
        chars[k]=chars[i];
        k++;

        while((j-i)>1){
            for(char c : to_string(j-i)){
                chars[k]=c;
                k++;
            }
        }
        i = j;
    }
    return k;
}

int main(){
    // vector<char> c = {'aabbccd'};
    // cout<<compress(c);

    return 0;
}