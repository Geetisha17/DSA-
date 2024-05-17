#include<iostream>
#include<vector>
using namespace std;

/* 3 3 4 2 4 4 2 4 4  first we'll take result and the number with maximum count will be our answer.
*/
int majorityElement(vector<int>& nums) {
    int res=0,count=0;
   
    for(auto v:nums){  // so the loop will traverse till the end of the length of the vector.
        if(count==0){  // initially if my count is zero the result = nums[i],
            res=v;    
        }
        if(res!=v){ 
            count--;
        }else{
            count++;
        }
    }
    return res;
}
//basically conter-balancing like 3,3,4,4,3 so in case 1 with two 3 count=2 second case with two 4 count=0 again with one extra 3 count=1

// 3 3 4 2 4 4 2 4 4
//res = 3 || 4
//will increment count by 1 if my res = v[i]
// will decrement count by 1 if res !=v[i]
// count= 1 || 2 || 1 || 0 || 1 || 2 || 1 || 2 || 3
// maximum count if 3 of number 4 so result=4.

int main(){
    vector<int> nums ={3,3,4,2,4,4,2,4,4};
    cout<<majorityElement(nums);
    return 0;
}