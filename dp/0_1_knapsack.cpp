#include <bits/stdc++.h> 
using namespace std;

int helper(int i,int w,vector<int>&weight,vector<int>&value,vector<vector<int>>&dp)
{
	if(i==0)
	{
		if(weight[0]<=w) return value[0];
		else return 0;
	}

	if(dp[i][w]!=-1) return dp[i][w];

	int notake = helper(i-1,w,weight,value,dp);

	int take = INT_MIN;

	if(weight[i]<=w)
	{
		take = value[i] + helper(i-1,w-weight[i] , weight,value,dp);
	}

	return dp[i][w]= max(take,notake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return helper(n-1,maxWeight,weight,value,dp);
}


// #include <bits/stdc++.h> 


// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

// 	for(int w=weight[0]; w<=maxWeight;w++) 
// 	dp[0][w] = value[0];

// 	for(int i=1;i<n;i++)
// 	{
// 		for(int w=0;w<=maxWeight;w++)
// 		{
// 			if(dp[i][w]!=0) return dp[i][w];

// 	int notake = dp[i-1][w];

// 	int take = INT_MIN;

// 	if(weight[i]<=w)
// 	{
// 		take = value[i] + dp[i-1][w-weight[i] ];
// 	}

// 	dp[i][w]= max(take,notake);
// 		}
// 	}

// 	return dp[n-1][maxWeight];
// }
