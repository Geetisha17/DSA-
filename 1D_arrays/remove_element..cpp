#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==val){
            nums.erase(nums.begin()+i);
           i--;
        }
    }
    return nums.size();
}

int main(){
    vector<int> nums={1,2,3,4,5};
    cout<<removeElement(nums,4);
    return 0;
}