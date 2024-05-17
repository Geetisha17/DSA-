#include<bits/stdc++.h>
using namespace std;

void powerSet(vector<int> nums,int index,vector<int> output,vector<vector<int>> &ans){
    //base case
    if(index>=nums.size()){  // if we hit the base case i.e i goes beyond the size of array
        ans.push_back(output);  // we will store the output in the ans basically the base ans
        return;
    }
    //excluding ith number
    powerSet(nums,index+1,output,ans);  // then we will move to the next no.
    //including ith number
    int j = nums[index]; // we will take the first no of the ans store it in the output
    output.push_back(j);
    powerSet(nums,index+1,output,ans); // furthur moving to the next index
    return;
}

vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    powerSet(nums,index,output,ans);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end(),ans.end()));
    return ans;
}

int main(){
    vector<int> nums ={1,2,3};
    vector<vector<int>> x=subsets(nums);
    
    return 0;
}