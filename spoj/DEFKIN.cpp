#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int h,w,n;
        cin>>h>>w>>n;
        
        vector<int>a;
        vector<int>b;
        a.push_back(0);
        b.push_back(0);
        
        for(int i=0;i<n;i++)
        {
            int x,y;cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
        }
        a.push_back(h+1);
        b.push_back(w+1);
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int maxiA=0;int maxiB=0;
        
        for(int i=0;i<a.size()-1;i++){
            maxiA = max(maxiA,a[i+1]-a[i]-1);
            maxiB = max(maxiB,b[i+1]-b[i]-1);
        }
        cout<<maxiA*maxiB<<endl;
    }
    return 0;
}
