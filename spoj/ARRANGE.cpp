#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int>nums(n);
        
        for(int i=0;i<n;i++)
        cin>>nums[i];
        
        sort(nums.begin(),nums.end());
        int i=0;
        
        while(nums[i]==1)
        {
            cout<<1<<" ";
            i++;
        }
        if(i==n-2 && nums[i]==2 && nums[i+1]==3)
        {
            cout<<2<<" "<<3;
        }
        else 
        {
            for(int j=n-1;j>=i;j--)
            {
                if(nums[j]!=1)
                cout<<nums[j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}
