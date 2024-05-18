#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        stack<int>st;

        unordered_map<int,int>mp;

        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]=i;
        }
        
        for(auto it:mp)
        {
            cout<<it.first<<" "<<it.second<<" ";
            cout<<endl;
        }
        

        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(mp.find(nums2[i]) != mp.end())
            {
                while(!st.empty() && st.top()<nums2[i])
                {
                    st.pop();
                }

                if (st.empty()==false) {
                    ans[mp[nums2[i]] ] = st.top();
                } else {
                    ans[mp[nums2[i]] ] = -1;
                }
            }
            st.push(nums2[i]);
        }
        return ans;
    }

int main() {
    vector<int>v1={2,4};
    vector<int>v2={1,2,3,4};
    
    vector<int>ans=nextGreaterElement(v1,v2);
    for(auto x:ans)
    cout<<x<<" ";

    return 0;
}