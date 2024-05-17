#include<bits/stdc++.h>
using namespace std;


int canBeFormedOrNot(string s1, string s2) {
   const int MAX=256;
  int count[MAX] = {0};
    for (int i = 0; i < s1.length(); i++)
        count[s1[i]]++;
         
    // Now traverse through str2 to check
    // if every character has enough counts
    for (int i = 0; i < s2.length(); i++)
    {
        if (count[s2[i]] == 0)
           return 0;
        count[s2[i]]--;
    }
    return 1;
    
}

int main(){
    string s1="abcd";
    string s2="bce";
    
    cout<<canBeFormedOrNot(s1,s2);
    return 0;
}