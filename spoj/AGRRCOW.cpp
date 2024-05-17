#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPlace(vector<int>&nums,int mid,int k)
{
	int cnt=1;int last=nums[0];
	
	for(int i=1;i<nums.size();i++)
	{
		if(nums[i] - last >= mid)
		{
			cnt++;
			last=nums[i];
		}
		
		if(cnt>=k) return true;
	}
	return false;
}

int agg(vector<int>&nums,int c)
{
	int n=nums.size();
	sort(nums.begin(),nums.end());
	int s=0;
	int e=nums[n-1]-nums[0];
	int ans=0;
	
	while(s<=e)
	{
		int mid=(s+e)/2;
		
		bool res = isPlace(nums,mid,c);
		
		if(res)
		{
			ans=mid;
			s=mid+1;
		}else{
			e=mid-1;
		}
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		
		vector<int>nums(n);
		for(int i=0;i<n;i++)
		cin>>nums[i];
		
		cout<<agg(nums,c)<<endl;
	}
	return 0;
}