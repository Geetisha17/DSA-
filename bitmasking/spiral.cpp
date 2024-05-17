#include<iostream>
#include<vector>
using namespace std;

vector<int> searchMatrix(vector<vector<int>>& nums, int target) {
        int r=0;
        int c=nums.size()-1;

        while(r<=nums.size()-1 && c>=0){
            if(nums[r][c]==target)
            return {r,c};

            else if(nums[r][c]<target)
            r++;
            
            else
            c--;
        }
        return {-1,-1};
}


int main(){
    vector<vector<int>>nums ={{2,4,6,8},{5,8,11,13},{7,14,17,18},{9,15,20,30}};
    cout<<"Geetisha Tandon"<<endl;
    vector<int>ans = searchMatrix(nums,30);
    for(auto x:ans)
    cout<<x<<" "<<endl; 
    return 0;
}