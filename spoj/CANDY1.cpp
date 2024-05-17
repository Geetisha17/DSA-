#include<iostream>
#include<vector>
using namespace std;

int main()
{
    while(true)
    {
        int n;
        cin>>n;
        
        if(n==-1) break;
        
        int cnt=0;
        vector<int>v(n);
        int total=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            total+=v[i];
        }
        
        int rem = total%n;
        int avg = total/n;
        
        if(rem!=0)
        {
            cout<<-1<<endl;
        }
        else {
            cnt=0;
            for(int i=0;i<v.size();i++)
            {
                if(v[i] > avg)
                {
                    cnt = cnt+(v[i]-avg);
                }
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}