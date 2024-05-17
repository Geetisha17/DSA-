#include<bits/stdc++.h>
using namespace std;

int defkin(int W, int H, vector<pair<int, int>> v)
{
    // your code goes here
  int n=v.size();
  vector<int>a;
  vector<int>b;
  a.push_back(0);
  b.push_back(0);
  for(int i=0;i<n;i++){
    a.push_back(v[i].first);
    b.push_back(v[i].second);
  }
  a.push_back(W+1);
  b.push_back(H+1);
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int mx=0,my=0;
  for(int i=0;i<a.size()-1;i++){
      mx = max(mx,a[i+1]-a[i]-1);
      my = max(my,b[i+1]-b[i]-1);
  }
  return mx*my;
}

int main(){
   int t;
   cout<<"t";
   cin>>t;

   while(t--){
    int w,h,n;
    cout<<"w,h,n";
    cin>>w>>h>>n;

    vector<int> a ;
    vector<int> b;
    a.push_back(0);
    b.push_back(0);

    for(int i=0;i<n;i++){
        int x,y;
        cout<<"x,y";
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    a.push_back(w+1);
    b.push_back(h+1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

   int mx=0,my=0;
    for(int i=0;i<a.size()-1;i++){

        mx = max(mx , a[i+1]-a[i]-1);
        my = max(my , b[i+1]-b[i]-1);

    }
    cout<<mx*my<<" ";
   }


    return 0;
}