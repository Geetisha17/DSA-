#include<iostream>
#include<vector>  
#include<algorithm> 
using namespace std;
    
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());
        int idx1=0,idx2=0;
        int i=0,j=v.size()-1;

        while(i<=j)
        {
            if(v[i].first+v[j].first==target){
                idx1=v[i].second;
                idx2=v[j].second;
                break;
            }else if(v[i].first+v[j].first<target){
                i++;
            }else{
                j--;
            }
        }return {idx1,idx2};
    }